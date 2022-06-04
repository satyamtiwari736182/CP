// 1. You are given three strings s1, s2 and s3.
// 2. First two are supposed to add and form third. s1 + s2 = s3
// 3. You have to map each individual character to a digit, so that the above equation holds true.

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing the signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"
int getNumber(string str, map<char, int> &hashmap)
{
    int num = 0;
    for (char ch : str)
        num = num * 10 + hashmap[ch];
    return num;
}

void cryptArithmetic(string ustr, int cc, map<char, int> &hashMap, vi &usedDigit, string s1, string s2, string s3)
{
    if (cc == ustr.length())
    {
        int num1 = getNumber(s1, hashMap);
        int num2 = getNumber(s2, hashMap);
        int num3 = getNumber(s3, hashMap);
        if (num1 + num2 == num3)
        {
            for (int i = 0; i < 26; i++)
            {
                char ch = char('a' + i);
                if (hashMap.count(ch))
                    cout << ch << "-" << hashMap[ch] << " ";
            }
            cout << endl;
        }
        return;
    }

    char ch = ustr[cc];
    int pnum = hashMap[ch];
    for (int num = 0; num <= 9; num++)
    {
        if (usedDigit[num] == false)
        {
            usedDigit[num] = true;
            hashMap[ch] = num;
            cryptArithmetic(ustr, cc + 1, hashMap, usedDigit, s1, s2, s3);
            hashMap[ch] = pnum;
            usedDigit[num] = false;
        }
    }
}

void solve()
{
    string s1, s2, s3, ustr;
    cin >> s1 >> s2 >> s3;
    map<char, int> hashMap;
    vi usedDigit(10);

    for (char ch : s1)
    {
        if (hashMap[ch] == 0)
            ustr += ch;
        hashMap[ch] = -1;
    }
    for (char ch : s2)
    {
        if (hashMap[ch] == 0)
            ustr += ch;
        hashMap[ch] = -1;
    }
    for (char ch : s3)
    {
        if (hashMap[ch] == 0)
            ustr += ch;
        hashMap[ch] = -1;
    }

    // cout << ustr << endl;
    // for (auto pr : hashMap)
    //     cout << pr.fs << " -> " << pr.se << endl;

    cryptArithmetic(ustr, 0, hashMap, usedDigit, s1, s2, s3);
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
team
pep
toppr
*/