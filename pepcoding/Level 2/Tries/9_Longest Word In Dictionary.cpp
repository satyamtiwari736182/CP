// 1. Given an array of strings words.
// 2. Find the word of longest length, where all of its substrings starting from 0th index exists as different word in array.
// 3. If there are multiple answers with same length return one which is smallest in lexicographical order. If there is no valid string return empty string.



#include "../header.h"

class Node
{
public:
    Node *child[26];
    string str;
    Node()
    {
        fill(child, child + 26, nullptr);
        str = " ";
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
    curr->str = str;
}

void dfs(Node *root, string *ans)
{
    Node *curr = root;
    for (Node *chld : curr->child)
    {
        if (chld != nullptr && chld->str != " ")
        {
            if (ans->length() < chld->str.length())
                *ans = chld->str;
            dfs(chld, ans);
        }
    }
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
    string ans = "";
    dfs(root, &ans);
    cout << "\nLongest word: " << ans << endl;
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

7
a
banana
app
appl
ap
apply
apple

*/