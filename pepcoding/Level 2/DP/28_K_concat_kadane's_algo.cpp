#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];
#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];
#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 80, N = 80;

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    // arr[0] = 0;
    rarr(arr, 0, n);
    cin >> k;
    int dp[2 * n + 1] = {0}, mx = INT_MIN;
    int arr2[2 * n + 1];
    arr2[0] = 0;

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];
    for (int i = 0; i <= 2 * n; i++)
        arr2[i + 1] = arr[i % (n)];

    //-----------------------------------------------------
    // K concatinated Kadane's Algorithm for max sum subarray
    for (int i = 1; i <= 2 * n; i++)
    {
        if (dp[i - 1] + arr2[i] > arr2[i])
            dp[i] = dp[i - 1] + arr2[i];
        else
            dp[i] = arr2[i];
        if (mx < dp[i])
            mx = dp[i];
    }
    //-----------------------------------------------------
    // K concatinated Kadane's Algorithm
    int maxSubArrSum = 0;
    if (sum > 0)
        maxSubArrSum = mx + (k - 2) * sum;
    else
        maxSubArrSum = mx;
    //-----------------------------------------------------
    cout << "\nHello world! " << sum << "\n"
         << maxSubArrSum << endl;

    parr(arr2, 2 * n + 1);
    cout << endl;
    parr(dp, 2 * n + 1);
    return 0;
}

// 18
// 4 3 -2 6 -14 7 -1 4 5 7 -10 2 9 -10 -5 -9 6 1
// 4

// 5
// 3 -2 -3 1 2
// 4
