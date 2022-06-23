// Given an array of strings words, return all the concatenated words in the given list of words.
// Concatenated word is a word that can be created by concatination of at least two other shorter words from the list.

// You can return concatination words in any order


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

set<string> ans;
void search(Node *curr, Node *nword, Node *root)
{
    if (curr->str != " " && nword->str != " ")
        ans.insert(curr->str);

    if (nword->str != " ")
        search(curr, root, root);

    for (int i = 0; i < 26; i++)
        if (curr->child[i] != nullptr && nword->child[i] != nullptr)
            search(curr->child[i], nword->child[i], root);
}

void search1(Node *curr, Node *root)
{
    if (curr->str != " ")
        search(curr, root, root);

    for (Node *chld : curr->child)
        if (chld != nullptr)
            search1(chld, root);
}

void solve()
{

    Node *root = new Node();
    string str = "";
    int n;
    cin >> n;
    vs arr(n);
    rarr(arr, 0, n);
    for (string str : arr)
        insert(root, str);
    search1(root, root);
    cout << endl;
    for (auto val : ans)
        cout << val << " ";
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

8
cat
cats
catsdogcats
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat

*/