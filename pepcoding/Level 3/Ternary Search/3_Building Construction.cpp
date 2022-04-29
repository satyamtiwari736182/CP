// https://www.spoj.com/problems/KOPC12A/

// Minimise f(x), f(x) = Σ (| x - height | *cost)

#include "../header.h"

lld func(lld x, vi &height, vi &cost)
{
    lld ans = 0;
    for (int i = 0; i < height.size(); i++)
        ans += abs(x - height[i]) * cost[i];
    return ans;
}

lld minimise_func(vi &height, vi &cost)
{
    int left = 0, right = 10000;
    while (left < right)
    {
        lld mid1 = left + (right - left) / 3;
        lld mid2 = right - (right - left) / 3;
        lld value1 = func(mid1, height, cost);
        lld value2 = func(mid2, height, cost);

        // 1.lies in left part
        if (value1 < value2)
            right = mid2 - 1;

        // 2.lies in right part
        else if (value1 > value2)
            left = mid1 + 1;

        // 3.lies in-between left and right
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    // cout << left << endl;

    return func(left, height, cost);
}

void solve()
{
    int n;
    cin >> n;
    vi height(n), cost(n);
    rarr(height, 0, n);
    rarr(cost, 0, n);
    lld ans = minimise_func(height, cost);
    cout << ans << endl;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

/*
1
3
1 2 3
10 100 1000
*/