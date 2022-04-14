// Given a string S, print the hash code of that string using Polynomial Hashing.
// Note: Use prime number = 31 and print the answer mod 1000000007.

#include "../header.h"

ll poly_hash(string str)
{
    ll p = 31, pow = 31;
    ll hash_value = str[0] - 'a' + 1;
    for (int i = 1; i < str.length(); i++)
    {
        hash_value = (hash_value + (str[i] - 'a' + 1) * pow) % mod;
        pow = (pow * p) % mod;
    }
    return hash_value;
}

void solve()
{
    string str;
    cin >> str;
    cout << poly_hash(str);
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 8

// satyam
// aabaabaa
// ab
// abc
// abcd
// abc
// xyz
// pqr