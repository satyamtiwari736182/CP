// 1. Given an integer array of size 'n'.
// 2. Return an array answer such that answer[i] is equal to the product of all the elements of arr except arr[i].
// 3. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    int lpro[100], rpro[100];
    fill(lpro, lpro + n, 1);
    fill(rpro, rpro + n, 1);
    // memset(rpro, 1, sizeof(rpro));
    rarr(arr, 0, n);
    int pro = 1;
    for (int i = 1; i < n; i++)
        pro *= arr[i - 1], lpro[i] = pro;
    pro = 1;
    for (int i = n - 2; i >= 0; i--)
        pro *= arr[i + 1], rpro[i] = pro;
    // parr(lpro, n);
    cout << endl;
    // parr(rpro, n);
    for (int i = 0; i < n; i++)
        cout << lpro[i] * rpro[i] << " ";
    cout << endl;
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
6537421

4
1 2 3 4
*/
