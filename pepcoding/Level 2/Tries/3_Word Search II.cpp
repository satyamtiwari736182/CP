// 1. Given an m x n board of characters and a list of strings words, return all words present on the board.
// 2. Word must be made from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// You can return word's in any order.

#include "../header.h"

class Node
{
public:
    Node *child[26];
    string isEnd;
    Node()
    {
        fill(child, child + 26, nullptr);
        isEnd = " ";
    }
};

void insert(Node *root, string str)
{
    Node *curr = root;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int idx = ch - 'a';
        if (curr->child[idx] == nullptr)
            curr->child[idx] = new Node();
        curr = curr->child[idx];
    }
    curr->isEnd = str;
}

char puzzle[100][100];

void dfs(Node *curr, int i, int j, vs &ans, vector<vi> &visited)
{
    if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() || visited[i][j])
        return;
    Node *node = curr->child[puzzle[i][j] - 'a'];
    if (node == nullptr)
        return;
    if (node->isEnd != " ")
    {
        ans.pb(node->isEnd);
        node->isEnd = " ";
    }

    visited[i][j] = true;
    dfs(node, i + 1, j, ans, visited);
    dfs(node, i - 1, j, ans, visited);
    dfs(node, i, j + 1, ans, visited);
    dfs(node, i, j - 1, ans, visited);
    visited[i][j] = false;
}

vs search(Node *root, int n, int m)
{
    Node *curr = root;
    vs ans;
    vector<vi> visited(n);
    for (auto &vis : visited)
        vis.resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(curr, i, j, ans, visited);
    // pmatrix(visited, n, m);
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    Fill(puzzle, '\0');
    rmatrix(puzzle, n, m);
    // cout << "\n**************\n";
    // pmatrix(puzzle, n, m);

    int word_cnt;
    cin >> word_cnt;
    vs words;

    Node *root = new Node();
    for (int i = 0; i < word_cnt; i++)
    {
        string str;
        cin >> str;
        words.pb(str);
        insert(root, str);
    }

    vs res = search(root, n, m);
    for (string word : res)
        cout << word << " ";
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    // int n;
    // string str;
    // while (cin >> n)
    //     cout << "**  " << str;

    return 0;
}

/*

4
4
oaan
etae
ihac
ifra
6
oath
pea
eat
car
eatat
rain
*/