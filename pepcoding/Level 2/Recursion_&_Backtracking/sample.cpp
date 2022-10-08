// 1. You are given n space separated strings, which represents a dictionary of words.
// 2. You are given another string which represents a sentence.
// 3. You have to print all possible sentences from the string, such that words of the sentence are
//      present in dictionary.

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

void wordBreak(string str, string res, unordered_set<string> &dict)
{
    if (str.length() == 0)
    {
        cout << res << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string left = Substr(str, 0, i + 1);
        if (dict.count(left))
        {
            string right = str.substr(i + 1);
            wordBreak(right, res + left + " ", dict);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    unordered_set<string> dict;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        dict.insert(str);
    }
    string sent;
    cin >> sent;
    wordBreak(sent, "", dict);
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

11
i like pep coding pepper eating mango man go in pepcoding
ilikepeppereatingmangoinpepcoding

*/