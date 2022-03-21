#include "../header.h"

bool solve(vi &arr)
{
    set<int> hashset;
    int mn = INT_MAX, mx = INT_MIN;
    for (int val : arr)
    {
        mn = min(mn, val);
        mx = max(mx, val);
        hashset.insert(val);
    }
    // cout<<mx<<" "<<mn<<endl;
    int common_diff = (mx - mn) / (arr.size() - 1);
    int a = mn;
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << a << " ";
        if (hashset.count(a) == 0)
            return false;
        a += common_diff;
    }
    cout << endl;
    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";
        cout << solve(arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 2

// 3
// 3 5 1

// 10
// 17 9 5 29 1 25 13 37 21 33
