// 1. Given an array nums of non-negative integers.
// 2. Arrange elements of array in specific order, all even elements followed by odd elements. [even -> odd]
// 3. Preserve the order of Even elements without using extra space.
// 4. Hence question is order specific so you have to match your output in order of given output.

#include "../header.h"

void solve()
{
    int n, i = 0, j = 0;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    while (i < arr.size())
    {
        if (arr[i] % 2 == 0)
            swap(arr[i], arr[j]), i++, j++;
        else
            i++;
    }
    parr(arr, n);
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

7
9 3 8 7 6 2 3

*/
