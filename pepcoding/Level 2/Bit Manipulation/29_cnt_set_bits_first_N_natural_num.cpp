// 1. You are given a number n.
// 2. You have to print the count of set bits of first n natural numbers.



#include "../header.h"

int largestPowerOf_2_inRange(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        ++x;
    return x - 1; // returns the index not the original count from 1 insted from 0 as bollowed in binary number inddexing
}
int sol(int n)
{
    if (n == 0)
        return 0;
    int x = largestPowerOf_2_inRange(n);
    int bit_cnt_2x = (1 << (x - 1)) * x;
    int cnt_msbit_of_rest = n - (1 << x) + 1;
    int rest = n - (1 << x);

    int ans = bit_cnt_2x + cnt_msbit_of_rest + sol(rest);
    return ans;
}
int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    cout << "\n========================================\n";
    cout << sol(n);
    cout << "\n========================================\n";
    return 0;
}


// 17