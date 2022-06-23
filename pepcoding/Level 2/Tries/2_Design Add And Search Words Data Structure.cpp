// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:
// 1. WordDictionary() Initializes the object.
// 2. void addWord(word) Adds word to the data structure, it can be matched later.
// 3. boolean search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

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
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int idx = ch - 'a';
        if (curr->child[idx] == nullptr)
            curr->child[idx] = new Node();
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

bool find(Node *curr, string word, int i)
{
    if (i == word.length())
        return curr->isEnd;

    if (word[i] == '.')
    {
        for (Node *node : curr->child)
            if (node != nullptr && find(node, word, i + 1))
                return true;
        return false;
    }

    else
    {
        int idx = word[i] - 'a';
        if (curr->child[idx] == nullptr)
            return false;
        else
            return find(curr->child[idx], word, i + 1);
    }
}

bool search(Node *root, string str)
{
    Node *curr = root;
    return find(curr, str, 0);
}

void solve()
{
    Node *root = new Node();
    insert(root, "apple");
    insert(root, "app");
    insert(root, "zare");
    insert(root, "cards");
    cout << "Hello world!\n"
         << search(root, "a.p") << "\t" << search(root, "c.rds") << "\t" << search(root, "za.") << endl;
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

addWord bad
addWord dad
addWord mad
search pad
search bad
search .ad
search b..

*/