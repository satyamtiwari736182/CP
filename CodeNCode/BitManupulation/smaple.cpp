#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
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
const int M = 100, N = 100;

int nextIndex(int arr[], int target, int end)
{
    // Minimum size of the array should be 1
    if (end == 0)
        return -1;
    // If target lies beyond the max element, than the index of strictly smaller
    // value than target should be (end - 1)
    if (target > arr[end - 1])
        return end - 1;

    int start = 0;

    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // Move to the left side if the target is smaller
        if (arr[mid] >= target)
        {
            end = mid - 1;
        }

        // Move right side
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cout << "hello" << endl;
    vi teamA = {6, 9, 12, 8};

    int teamB[] = {5, 7};
    sort(all(teamA));
    for (int i = 0; i < 2; i++)
    {
        // nextIndex(teamA,teamB[i],4);
        cout << (end(teamA) - lower_bound(all(teamA), teamB[i])) << " ";
    }
    cout << endl;
    print(teamA, 0, 3);

    //----------------------------------------

    // int n = 37;
    // int lnt = log2(n) + 1;
    // vector<int> ans;
    // ans.push_back(0);
    // while (n > 0)
    // {
    //     ans[0]++;
    //     int mask = n & -n;
    //     n = n - mask;
    //     int val = mask == 1 ? 1 : (log2(mask) + 1);
    //     ans.push_back(lnt - val + 1);
    // }
    // reverse(ans.begin() + 1, ans.end());
    // print(ans, 0, ans.size() - 1);

    //----------------------------------------------

    return 0;
}

// 1101