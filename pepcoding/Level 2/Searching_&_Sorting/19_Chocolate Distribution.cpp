// 1. Given an array A[] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 2. Each student gets exactly one packet.
// 3. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.



#include "../header.h"

int solve(vi &arr, int m)
{
    int ans = INT_MAX;
    sort(all(arr));
    int i = 0, j = m - 1;
    while (j < arr.size())
    {
        ans = min(ans, arr[j] - arr[i]);
        i++;
        j++;
    }
    return ans;
}
int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> m;

        cout << "\n============================================\n";

        cout << solve(arr, m);

        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 8
// 3 4 1 9 56 7 9 12
// 5