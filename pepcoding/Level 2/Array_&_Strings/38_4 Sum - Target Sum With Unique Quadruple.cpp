// 1. Given an array nums of 'n' integers.
// 2. You have to return an array of all the unique quadruple [nums[a], nums[b], nums[c], nums[d]] such that:
//     2.1 a, b, c, and d are less than 'n' and greater than 0
//     2.2 a,. b, c, and d are Unique.
//     2.3 nums[a] + nums[b] + nums[c] + nums[d] == target.
// 3. You can return answer in any order.

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
    for (int i = left; i <= n - k; i++)
    {
        if (i != left && arr[i] == arr[i - 1])
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
    }
    return ans;
}

vvi fourSum(vi &arr, int left, int right, int target)
{
    vvi ans;
    int k = 4, n = arr.size();
    for (int i = 0; i <= n - k; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int val1 = arr[i];
        int targ = target - val1;
        vvi res = threeSum(arr, i + 1, n - 1, targ);
        if (res.size())
        {
            for (int j = 0; j < res.size(); j++)
                res[j].pb(val1), ans.pb(res[j]);

            // for (int j = 0; j < res.size(); j++)
        }
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
    vvi res = fourSum(arr, 0, n - 1, target);

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
1 0 -1 0 -2 2
0
*/
