// Implement the MapSum class:
// 1. MapSum() Initializes the MapSum object.
// 2. void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
// 3. int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

#include "../header.h"

class Node
{
public:
    Node *child[26];
    int score;
    Node()
    {
        fill(child, child + 26, nullptr);
        score = 0;
    }
};

void insert(Node *root, string str, int val, map<string, int> &hashmap)
{
    Node *curr = root;
    int delta = val - hashmap[str];
    hashmap[str] = val;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int idx = ch - 'a';
        if (curr->child[idx] == nullptr)
            curr->child[idx] = new Node();
        curr = curr->child[idx];
        curr->score += delta;
    }
}

int sum(Node *root, string prefix)
{
    Node *curr = root;
    for (char ch : prefix)
    {
        if (curr->child[ch - 'a'] == nullptr)
            return 0;
        curr = curr->child[ch - 'a'];
    }
    return curr->score;
}

void solve()
{

    Node *root = new Node();
    string str = "";
    map<string, int> hashmap;
    vi res;
    while (str != "exit")
    {
        fflush(stdin);
        getline(cin, str);
        string tok;
        vs queryStr;
        str_to_tok(str, ' ', queryStr, tok);
        int val = 0;

        if (queryStr.size() == 2)
        {
            convert(queryStr[1], val);
            insert(root, queryStr[0], val, hashmap);
            //    hashmap[str] = val;
        }
        else
            res.pb(sum(root, queryStr[0]));
    }

    cout << endl;
    parr(res, res.size() - 1);
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

apple 3
ap
app 2
apple 2
ap
exit

*/