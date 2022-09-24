// 1. You are given two numbers which represent the numerator and denominator of a fraction.
// 2. You have to convert this fraction into a decimal.
// 3. If the decimals are repeating recursively, then you have to put the recurring sequence inside a bracket.

#include "../header.h"

string solve(int num, int den)
{
    string ans = "";
    int q = num / den;
    int r = num % den;
    ans = ans + to_string(q);
    if (r == 0)
        return ans;
    else
    {
        ans = ans + ".";
        map<int, int> hashmap;
        while (r != 0)
        {
            if (hashmap.count(r))
            {
                int len = hashmap[r];
                ans = Substr(ans, 0, len) + "(" + Substr(ans, len, ans.length()) + ")";
                break;
            }
            else
            {
                hashmap[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans = ans + to_string(q);
            }
        }
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int num, den;
        cin >> num >> den;

        cout << "\n============================================\n";
        cout << solve(num, den);

        cout << "\n============================================\n";
    }

    return 0;
}

// 6
// 8 4
// 37 2
// 428 125
// 14 3
// 47 18
// 93 7
