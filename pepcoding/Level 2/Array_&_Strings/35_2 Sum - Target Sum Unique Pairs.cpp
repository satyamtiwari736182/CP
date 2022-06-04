// 1. Given an Array of size 'n' have may or may not be repeated elements.
// 2. A 'target' is provided.
// 3. Return Pair of target sum in which all pairs are unique, for example : [1, 2], [2, 1] are consider as same pair.
// 4. If array have repeated element then return only unique pair, for example : if array is arr = [2, 2, 4, 4], and target = 6 then res have only one pair, i.e. [2, 4]

#include "../header.h"

void solve()
{
    int n, target;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> target;
    sort(all(arr));
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (left != 0 && arr[left] == arr[left - 1])
        {
            left++;
            continue;
        }

        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << arr[left] << " + " << arr[right] << " = " << sum << endl;
            left++, right--;
        }

        else if (sum > target)
            right--;
        else
            left++;
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
*/


