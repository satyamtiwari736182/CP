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
    int type, u, v;
    Pair(int t, int u, int v) : type(t), u(u), v(v) {}
    Pair() = default;
};

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(int *rank, int *parent, int x, int y)
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

int maximum_edges_removed(vector<Pair> &edges, int n)
{

    sort(all(edges), [&](const Pair a, const Pair b)
         { return a.type > b.type; });

    int parent_alice[n + 1], parent_bob[n + 1], rank_a[n + 1], rank_b[n + 1];
    for (int i = 0; i <= n; i++)
    {
        parent_alice[i] = i;
        parent_bob[i] = i;
        rank_a[i] = 1;
        rank_b[i] = 1;
    }

    int merged_a = 1;
    int merged_b = 1;
    int cnt_removed_edge = 0;

    for (auto removed_edge : edges)
    {
        if (removed_edge.type == 3)
        {
            bool tempa = Union(rank_a, parent_alice, removed_edge.u, removed_edge.v);
            bool tempb = Union(rank_b, parent_bob, removed_edge.u, removed_edge.v);
            if (tempa == true)
                merged_a++;
            if (tempb == true)
                merged_b++;
            if (tempa == false && tempb == false)
                cnt_removed_edge++;
        }
        else if (removed_edge.type == 1)
        {
            bool tempa = Union(rank_a, parent_alice, removed_edge.u, removed_edge.v);
            if (tempa == true)
                merged_a++;
            else
                cnt_removed_edge++;
        }
        else
        {
            bool tempb = Union(rank_b, parent_bob, removed_edge.u, removed_edge.v);
            if (tempb == true)
                merged_b++;
            else
                cnt_removed_edge++;
        }
    }

    if (merged_a != n || merged_b != n)
        return -1;

    return cnt_removed_edge;
}
int main()
{
    cout << "\nHello world!" << endl;

    int n, e;
    cin >> n >> e;
    vector<Pair> edges;
    while (e--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        edges.pb(Pair(type, u, v));
    }

    cout << "\n==========================================\n";
    cout << maximum_edges_removed(edges, n);
    cout << "\n==========================================\n";
    return 0;
}

/*
4 6
3 1 2
1 1 3
1 2 4
2 3 4
1 1 2
3 2 3

*/