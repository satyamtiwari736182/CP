// 1. You will be given an Array
//  2. You need to return width of all its subsequence, where width is defined as difference between its maximum and minimum value
//  3. Input and output is handled for you
//  4. It is a functional problem ,please do not modify main()

#include "../header.h"

int sumSubseqWidth(vi &arr)
{
    int n = arr.size();
    sort(all(arr));
    ll ans = 0;
    vector<ll> pwr(n);
    pwr[0] = 1;
    for (int i = 1; i < n; i++)
        pwr[i] = (pwr[i - 1] * 2) % mod;
    for (int i = 0; i < n; i++)
        ans = (ans + arr[i] * (pwr[i] - pwr[n - i - 1])) % mod;
    return (int)ans;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "--------------------" << endl;
    cout << sumSubseqWidth(arr);
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
7 1 5 2 3 4
*/
