// 1. Given an array arr of size n, you need to write a program to find if there exists a pair of elements in the array whose difference is equals to target.
// 2. If there exists such a pair print it, otherwise print -1.

#include "../header.h"

vector<pi> solve(vi &arr, int diff)
{
    vector<pi> ans;
    sort(all(arr));

    int left = 0, right = 1;
    while (left < arr.size() && right < arr.size())
    {
        if ((arr[right] - arr[left]) == diff)
        {
            ans.pb({arr[left++], arr[right++]});

            while (left < arr.size() && arr[left] == arr[left - 1])
                left++;
            while (right < arr.size() && arr[right] == arr[right - 1])
                right++;
        }
        else if ((arr[right] - arr[left]) > diff)
            left++;
        else
            right++;
    }
    cout << endl;
    return ans;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, diff;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> diff;
        cout << "\n============================================\n";

        vector<pi> ans = solve(arr, diff);
        for (pi itm : ans)
            cout << itm.fs << " " << itm.se << endl;
        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 10
// 4 5 2 3 80 2 5 20 80 82
// 78