// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. Complete the body of printTargetSumSubsets function - without changing signature - to calculate and print all subsets of given elements, the contents of which sum to "tar". Use sample input and output to get more idea.

#include "../header.h"

void subsetsum(int *arr, int n, int tar, string ans)
{
    if (n < 0)
        return;
    if (n == 0)
    {
        if (tar == 0)
            cout << ans << endl;
        else if (tar - arr[n] == 0)
        {
            ans = to_string(arr[n]) + ", " + ans;
            cout << ans << endl;
        }
        return;
    }
    subsetsum(arr, n - 1, tar - arr[n], to_string(arr[n]) + ", " + ans);
    subsetsum(arr, n - 1, tar, ans);
}

void solve()
{
    int arr[N];
    int n, tar;
    cin >> n;
    rarr(arr, 0, n);
    cin >> tar;
    cout << "\n***********\n";
    subsetsum(arr, n, tar, "");
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

// 5
// 10
// 20
// 30
// 40
// 50
// 60