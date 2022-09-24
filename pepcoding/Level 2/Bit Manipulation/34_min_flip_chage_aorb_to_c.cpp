// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
//! a or b = c
#include "../header.h"

int minflips(int a, int b, int c)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        int ai = a & mask ? true : 0;
        int bi = b & mask ? true : 0;
        int ci = c & mask ? true : 0;

        if (ci == true)
        {
            if (!ai && !bi) // any one must be true for ' a or b '
                ans++;
        }

        else
        {
            if (ai && bi)
                ans += 2;
            else if (ai || bi)
                ans++;
        }
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    cout << "\n========================================\n";
    cout << minflips(a, b, c);
    cout << "\n========================================\n";
    return 0;
}

// 4 2 7
// o:1

// 1 2 3
// o:0
