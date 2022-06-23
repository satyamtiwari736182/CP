// 1. You r given an array of string's say dictionary and a long string say sentence.
// 2. You have to replace all words in sentence which contains a prefix in dictionary with the prefix itself in dictionary.

// Example
// dictionary = ["cat","bat","rat"]
// sentence = "the cattle was rattled by the battery"

// In this sentence cattle, rattled and battery are the words containing prefix in dictionary they are cat, rat and bat.
// sentence after replace words is "the cat was rat by the bat".

// 3. If there are multiple prefix for a word in dictionary replace it with the shortest prefix word.

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

string searchPrefix(Node *root, string tok)
{
    string ans = " ";
    Node *curr = root;
    for (char ch : tok)
    {
        if (curr->child[ch - 'a'] != nullptr)
            curr = curr->child[ch - 'a'];
        if (curr->str != " ")
            return curr->str;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string dict[100], str;
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
        insert(root, dict[i]);
    }
    fflush(stdin);
    getline(cin, str);
    cout << "\n**********\n";
    // cout << str;

    string str1, ans = "";
    vs tokens;
    str_to_tok(str, ' ', tokens, str1);
    for (auto tok : tokens)
    {
        string prefix = " ";
        prefix = searchPrefix(root, tok);
        if (prefix != " ")
            ans = ans + prefix + " ";
        else
            ans = ans + tok + " ";
    }
    ans.erase(ans.size() - 1);
    cout << ans << endl;
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


4
catt
cat
bat
rat
the cattle was rattled by the battery

*/
