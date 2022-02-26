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
    int vtx, wt;
    Pair(int vtx, int wt) : vtx(vtx), wt(wt) {}
};

int main()
{

    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<vector<Pair>> graph;
    graph.resize(n);

    // Constructing graph with cost reparing roads to connect the cities
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back(Pair(v, wt));
        graph[v].push_back(Pair(u, wt));
    }

      //---------------------------------------------

    auto cmpr = [&](const Pair &a, const Pair &b)
    { return b.wt < a.wt; };

    priority_queue<Pair, vector<Pair>, decltype(cmpr)> pque(cmpr);

    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    pque.push(Pair(0, 0));

    // Applying Prism's algo of Minimum Spanning Tree Algorithm.
    // To minimize cost for connecting cities
    while (!pque.empty())
    {
        Pair temp = pque.top();
        pque.pop();
        if (vis[temp.vtx] == true)
            continue;

        ans += temp.wt;
        vis[temp.vtx] = true;

        vector<Pair> nbrs = graph[temp.vtx];
        for (Pair nbr : nbrs)
            if (vis[nbr.vtx] == false)
                pque.push(nbr);
    }

    //---------------------------------------------
    cout << "\n==========================================\n";
    cout << ans;
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