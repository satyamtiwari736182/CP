// 1. You are given a word (may have one character repeat more than once).
// 2. You are required to generate and print all arrangements of these characters.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
//! Permutation Method.
// todo: last_occurence of a char not allows the same character to get permute among themselves.
void getWordPermutation(int cc, string str, char *spots, map<char, int> &last_occurence)
{

    if (cc > str.length() - 1)
    {
        parr(spots, str.length());
        cout << endl;
        return;
    }

    char ch = str[cc];
    // debug(ch);
    int last_occ_idx = last_occurence[ch];

    for (int i = last_occ_idx + 1; i < str.length(); i++)
    {
        if (spots[i] == '\0')
        {
            spots[i] = ch;
            last_occurence[ch] = i;
            getWordPermutation(cc + 1, str, spots, last_occurence);
            last_occurence[ch] = last_occ_idx;
            spots[i] = '\0';
        }
    }
}

void solve()
{
    string str;
    cin >> str;
    cout << endl;
    char spots[str.length()];
    memset(spots, '\0', sizeof(spots));
    map<char, int> last_occurence;
    for (char ch : str)
        last_occurence[ch] = -1;
    cout << endl;
    getWordPermutation(0, str, spots, last_occurence);
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

// aabb