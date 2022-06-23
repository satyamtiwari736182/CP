// Implement the StreamChecker class as follows:

// 1. StreamChecker(words): Constructor, init the data structure with the given words.
// 2. query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.


#include "../header.h"

class Node
{
public:
    Node *child[26];
    bool isEnd;
    Node()
    {
        fill(child, child + 26, nullptr);
        isEnd = false;
    }
};

void insert(Node *root, string str)
{
    Node *curr = root;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        int idx = ch - 'a';
        if (curr->child[idx] == nullptr)
            curr->child[idx] = new Node();
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

bool query(Node *root, string str)
{

    Node *curr = root;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        curr = curr->child[ch - 'a'];
        if (curr == nullptr)
            return false;
        if (curr->isEnd)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        insert(root, str);
    }

    cin >> n;
    vs res;
    string str = "";
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        char ch;
        cin >> ch;
        str = str + ch;
        string str1 = query(root, str) == true ? "true" : "false";
        res.pb(str1);
    }
    cout << endl;
    parr(res, res.size());
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

3
cd
f
kl
12
a
b
c
d
e
f
g
h
i
j
k
l
*/