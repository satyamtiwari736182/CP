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
            mat[i].push_back(val);  \
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
    int u, v, wt;
    Pair(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

// Function object called as Functor.
class cmprWT
{
public:
    bool operator()(const Pair &first, const Pair &second) const
    {
        return first.wt > second.wt;
    }
};

class Foo
{
};

bool Compare(Foo, Foo)
{
    return true;
}

bool cmprs(const Pair a, const Pair b)
{
    return b.wt < a.wt;
}

int main()
{
    priority_queue<Foo, vector<Foo>, decltype(&Compare)> pq(Compare);
    priority_queue<Foo, vector<Foo>, function<bool(Foo, Foo)>> pq2(Compare);
    priority_queue<Foo, vector<Foo>, bool (*)(Foo, Foo)> pq23(Compare);

    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Pair> edges;

    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Pair(u, v, wt));
        // edges.push_back(Pair(v, u, wt));
    }
    auto cmpr = [&](const Pair &a, const Pair &b)
    { return a.wt < b.wt; };

    // priority_queue<Pair, vector<Pair>, decltype(cmpr)> que(cmpr);
    priority_queue<Pair, vector<Pair>, bool (*)(Pair, Pair)> que(cmprs);

    //---------------------------------------------

    int cnt = edges.size(), i = 0;
    while (cnt--)
    {
        que.push(edges[i++]);
    }

    cout << "\n==========================================\n";
    while (!que.empty())
    {
        cout << que.top().wt << " ";
        que.pop();
    }
    cout << "\n==========================================\n";
    return 0;
}

/*
4 5
0 1 10
1 2 12
2 3 14
0 3 16
0 2 13
*/