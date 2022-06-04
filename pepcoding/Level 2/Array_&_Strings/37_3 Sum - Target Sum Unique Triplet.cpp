// 1. Given an integer array 'nums', and a 'target', return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k.
// 2. Another thing is nums[i] + nums[j] + nums[k] == target.
// 3. Notice that the solution set must not contain duplicate triplets.


#include "../header.h"
vii twoSum(vi &arr, int left, int right, int target)
{
    vii ans;
    while (left < right)
    {
        if (left != 0 && arr[left] == arr[left - 1])
        {
            left++;
            continue;
        }

        int sum = arr[left] + arr[right];
        if (sum == target)
            ans.pb({arr[left], arr[right]}), left++, right--;

        else if (sum > target)
            right--;
        else
            left++;
    }
    return ans;
}

vvi threeSum(vi &arr, int left, int right, int target)
{
    vvi ans;
    int k = 3, n = arr.size();
    for (int i = 0; i <= n - k; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int val1 = arr[i];
        int targ = target - val1;
        vii res = twoSum(arr, i, n - 1, targ);
        if (res.size())
            for (auto pr : res)
            {
                vi tempAns;
                tempAns.pb(val1), tempAns.pb(pr.fs), tempAns.pb(pr.se);
                ans.pb(tempAns);
            }
        // if (tempAns.size())
    }
    return ans;
}

void solve()
{
    int n, target;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> target;
    sort(all(arr));
    int left = 0, right = n - 1;
    vvi res = threeSum(arr, 0, n - 1, target);

    for (int i = 0; i < res.size(); i++)
    {
        for (int val : res[i])
            cout << val << " ";
        cout << endl;
    }
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
6
10 10 30 40 50 20
60

//**********

6
-1 0 1 2 -1 -4
0
*/
