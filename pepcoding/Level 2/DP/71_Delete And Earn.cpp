// https://leetcode.com/problems/delete-and-earn/

#include "../header.h"

int deleteAndEarn(vi &nums)
{
    int incl = 0, excl = 0;
    int cnt[10001];
    memset(cnt, 0, sizeof(cnt));

    for (int val : nums)
        cnt[val]++;

    for (int i = 0; i <= 10000; i++)
    {
        int nxtIncl = excl + cnt[i] * i;
        int nxtExcl = max(incl, excl);
        incl = nxtIncl, excl = nxtExcl;
    }

    return max(incl, excl);
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    //------------------------------------------------------
    cout << deleteAndEarn(arr) << endl;

    return 0;
}

/*
6
3 2 4 2 3 3
*/
