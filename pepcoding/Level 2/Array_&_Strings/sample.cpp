#include "../header.h"
vvi twoSum(vi &arr, int left, int target)
{
    vvi ans;
    int right = arr.size();
    // if (right - left + 1 < 2)
    //     return ans;

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

vvi kSum(vi &arr, int left, int target, int k)
{
    if (k == 2)
        return twoSum(arr, left, target);
        
    int n = arr.size();
    vvi res;
    if (n - k < 0)
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
