#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

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
const int M = 100, N = 100;

int getRev(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int left_bit = (n & 1);
        rev |= left_bit;
        rev <<= 1;
        n >>= 1;
    }
    rev >>= 1;
    return rev;
}

int Nth_PalindromicBinary(int n)
{
    int count_element = 1;
    int len = 1;
    while (count_element < n)
    {
        len++;
        int num_elementsForThis_len = (1 << (len - 1) / 2);
        count_element += num_elementsForThis_len;
    }
    count_element -= (1 << (len - 1) / 2);
    int offset = n - count_element - 1;
    int ans = (1 << len - 1);
    ans |= (offset << (len / 2));
    int value_for_rev = (ans >> (len / 2));
    int rev = getRev(value_for_rev);
    ans |= rev;
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    cout << "\n========================================\n";
    int res = Nth_PalindromicBinary(n);
    bitset<10> val(res);
    cout << res << "\t" << val;
    cout << "\n========================================\n";
    return 0;
}
