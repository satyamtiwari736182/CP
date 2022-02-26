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

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
    {                               \
        vi vec;                     \
        for (int j = 0; j < m; j++) \
        {                           \
            int x;                  \
            cin >> x;               \
            vec.pb(x);              \
        }                           \
        arr.pb(vec);                \
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

class Pair
{
public:
    int val, idx;
    Pair(int val, int idx) : val(val), idx(idx) {}
};

bool comparable(Pair first, Pair second)
{
    return first.val < second.val;
}

int min_swap(vi &arr)
{
    int n = arr.size();
    vector<Pair> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(Pair(arr[i], i));

    sort(all(vec), comparable);

    int swap_count = 0;

    bool visited[n] = {0};

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true || vec[i].idx == i)
            continue;

        int cycle_len = 0;
        int j = i;

        while (visited[j] == false)
        {
            visited[j] = true;
            cycle_len++;
            j = vec[j].idx;
        }

        swap_count += cycle_len - 1;
    }

    return swap_count;
}

int main()
{
    cout << "\nhello!" << endl;

    int n;
    cin >> n;
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.pb(val);
    }
    cout << "\n--------------------------\n";
    cout << min_swap(arr);
    cout << "\n--------------------------\n";
    parr(arr, n);
    return 0;
}

// 2 3
// 4 1 2
// 5 0 3