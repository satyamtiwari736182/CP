#include "../header.h"
using namespace std;

//* Tries is also known as
//!   Prefix Tree important.

class Node
{
public:
    bool isEnd;
    Node *child[26];
    Node()
    {
        isEnd = false;
        fill(child, child + 26, nullptr);
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

bool search(Node *root, string str)
{
    Node *curr = root;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int idx = ch - 'a';
        if (curr->child[idx] == nullptr)
            return false;
        curr = curr->child[idx];
    }
    return curr->isEnd;
}

bool startsWith(Node *root, string str)
{
    Node *curr = root;
    for (int i = 0; i < str.length(); i++)
    {
        if (curr->child[str[i] - 'a'] == nullptr)
            return false;
        curr = curr->child[str[i] - 'a'];
    }
    return true;
}

int main()
{
    Node *root = new Node();
    insert(root, "apple");
    insert(root, "app");
    insert(root, "zare");
    insert(root, "cards");
    cout << "\nHello world!\n"
         << search(root, "car") << "\t" << startsWith(root, "car") << endl;
    for (int i = 0; i < 26; i++)
        cout << root->child[i] << " ";
    return 0;
}