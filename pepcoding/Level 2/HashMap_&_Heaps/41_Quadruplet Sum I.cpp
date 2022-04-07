#include "../header.h"

vs findPair(vi &arr, int idx, int sum)
{
    vs ans;
    int i = idx, j = arr.size() - 1;

    while (i < j)
    {
        int temp = arr[i] + arr[j];

        if (temp > sum)
            j--;
        else if (temp < sum)
            i++;
        else
        {
            string str = to_string(arr[i]) + " " + to_string(arr[j]);
            ans.pb(str);
            i++;
            j--;
            while (i < j && arr[i] == arr[i - 1])
                i++;
            while (i < j && arr[i] == arr[i - 1])
                j--;
        }
    }
    return ans;
}

vs findTriplet(vi &arr, int idx, int sum)
{
    vs ans;
    for (int i = idx; i < arr.size() - 1; i++)
    {
        vs temp = findPair(arr, i + 1, sum - arr[i]);

        for (string str : temp)
            ans.pb(to_string(arr[i]) + " " + str);
    }
    return ans;
}

vs findQuadruplet(vi &arr, int idx, int sum)
{
    vs ans;
    for (int i = idx; i < arr.size() - 1; i++)
    {
        vs temp = findTriplet(arr, i + 1, sum - arr[i]);
        for (string str : temp)
            ans.pb(to_string(arr[i]) + " " + str);
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n, sum;
        vi arr;
        cin >> n;
        rvarr(arr, 0, n);
        cin >> sum;

        cout << "\n============================================\n";
        sort(all(arr));
        vs ans = findQuadruplet(arr, 0, sum);
        for (string str : ans)
            cout << str << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 2

// 6
// 1 0 -1 0 -2 2
// 0

// 16
// 2 2 3 5 6 1 2 4 3 8 1 1 2 2 3 5
// 7
