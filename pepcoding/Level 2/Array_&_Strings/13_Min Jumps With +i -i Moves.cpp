// 1. Given an integers X. 
// 2. The task is to find the minimum number of jumps to reach a point X in the number line starting from zero.
// 3. The first jump made can be of length one unit and each successive jump will be exactly one unit longer than the previous jump in length. 
// 4. It is allowed to go either left or right in each jump.

#include "../header.h"

void solve()
{
    int n, jump_cnt = 1, sum = 0;
    cin >> n;

    while (sum < n)
        sum += jump_cnt, jump_cnt++;

    if ((sum - n) % 2 == 0)
        jump_cnt = jump_cnt - 1;

    else if ((sum + jump_cnt - n) % 2 == 0)
        jump_cnt = jump_cnt;

    else
        jump_cnt = jump_cnt + 1;

    cout << "\n"
         << jump_cnt << endl;
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
9

*/
