// 1. You are given a string str.
// 2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
// For abbc -> there are 3 subsequences. abc, abc, abbc
// For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.

#include "../header.h"

void solve()
{
    string str;
    cin >> str;
    int a = 0, ab = 0, abc = 0;
    for (char ch : str)
    {
        if (ch == 'a')
            a = 2 * a + 1;
        else if (ch == 'b')
            ab = 2 * ab + a;
        else if (ch == 'c')
            abc = 2 * abc + ab;
    }

    cout << abc << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
abcabc
*/

// abcabc
