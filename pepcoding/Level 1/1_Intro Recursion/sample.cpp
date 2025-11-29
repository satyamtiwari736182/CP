#include "../header.h"

void solve() {
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 5, 7, 9};
    int lwr=lower_bound(arr, arr + 10, 5) - arr; // >=
    int upr=upper_bound(arr, arr + 10, 5) - arr;  // >
    cout << lwr << ", " << upr << endl;
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}