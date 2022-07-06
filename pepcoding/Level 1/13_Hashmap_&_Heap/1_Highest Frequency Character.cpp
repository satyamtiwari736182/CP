// 1. You are given a string str.
// 2. You are required to find the character with maximum frequency.

#include "../header.h"

void solve()
{
    string str;
    unordered_map<char, int> hashmap;
    cin >> str;
    for (char ch : str)
        hashmap[ch]++;
    int cnt = 0;
    char ch;
    for (auto pr : hashmap)
        if (cnt < pr.se)
            cnt = pr.se, ch = pr.fs;
    cout << ch << endl;
}

int main()
{
    cout << "hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc
