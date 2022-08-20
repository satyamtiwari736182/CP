// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.


#include "../header.h"

bool is_132_Pattern(vi &nums)
{
    int n = nums.size();
    vi minimum(n);
    minimum[0] = nums[0];

    for (int i = 1; i < n; i++)
        minimum[i] = min(minimum[i - 1], nums[i]);

    stack<int> stk;
    bool found = false;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= minimum[i])
            stk.pop();

        if (!stk.empty() && stk.top() < nums[i])
        {
            found = true;
            break;
        }
        
        stk.push(nums[i]);
    }

    return found;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    cout << is_132_Pattern(arr) << endl;
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
4
3 1 4 2
*/