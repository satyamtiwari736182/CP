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

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp; // path compression for optimisation.
    return temp;
}

bool unionByRank(int *parent, int *rank, int x, int y)
{
    int px = findParent(parent, x);
    int py = findParent(parent, y);
    if (px != py)
    {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
        {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    return false;
}

int Kruskal_DSU(vector<Pair> &edges, int n)
{
    sort(all(edges), [&](auto first, auto second)
         { return first.wt < second.wt; });

    int parent[n + 1];
    int rank[n + 1];

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
    int ans = 0;
    for (auto edge : edges)
        if (unionByRank(parent, rank, edge.u, edge.v))
            ans += edge.wt;

    parr(parent, n + 1);
    cout << endl;
    parr(rank, n + 1);
    cout << endl;

    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Pair> edges;

    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Pair(u, v, wt));
        edges.push_back(Pair(v, u, wt));
    }

    //---------------------------------------------

    cout << "\n==========================================\n";
    cout << Kruskal_DSU(edges, n) << endl;

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