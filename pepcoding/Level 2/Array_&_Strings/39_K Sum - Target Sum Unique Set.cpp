// 1. Given an array nums of 'n' integers and a variable 'K'.
// 2. You have to return an array of all the unique set [nums[a], nums[b], nums[c], nums[d] . . . K Elements] such that:
//     2.1 a, b, c, d . . . K Elements are less than 'n' and greater than 0.
//     2.2 a,. b, c, d upto K different indexes are Unique.
//     2.3 nums[a] + nums[b] + nums[c] + nums[d] + . . . + nums[K distinct indexes] == target.
// 3. You can return answer in any order.

#include "../header.h"
vvi twoSum(vi &arr, int si, int target)
{
    vvi ans;
    int n = arr.size();
    if (n - si < 2)
        return ans;

    int right = arr.size() - 1;
    int left = si;
    while (left < right)
    {
        if (left != si && arr[left] == arr[left - 1])
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

vvi kSum(vi &arr, int left, int target, int k)
{
    if (k == 2)
        return twoSum(arr, left, target);

    int n = arr.size();
    vvi res;
    if (n - left < 0)
        return res;

    for (int i = left; i <= n - k; i++)
    {
        if (i != left && arr[i] == arr[i - 1])
            continue;

        int val1 = arr[i];
        vvi subRes = kSum(arr, i + 1, target - val1, k - 1);

        for (auto lst : subRes)
            lst.pb(val1), res.pb(lst);
    }

    return res;
}

void solve()
{
    int n, target, k;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> target >> k;
    sort(all(arr));
    int left = 0, right = n - 1;

    vvi res = kSum(arr, 0, target, k);

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
-1 0 1 2 -1 -4
0
3

*/
