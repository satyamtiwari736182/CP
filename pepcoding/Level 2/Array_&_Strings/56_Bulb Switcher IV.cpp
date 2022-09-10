// https://leetcode.com/problems/bulb-switcher-iv/

#include "../header.h"

int minFlips(string target)
{
    int future = 0, flip_cnt = 0;
    for (char bit : target)
    {
        if (future == bit - '0')
            continue;
        future = future == 1 ? 0 : 1, flip_cnt++;
    }
    return flip_cnt;
}

void solve()
{
    string str;
    cin >> str;
    cout << "--------------------" << endl;
    cout << minFlips(str);
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
001011101
*/
