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

int tim = 0;
void dfs(vector<vi> &graph, bool *vis, int *parent, int *low, int *discov, bool *articu_pt, int u)
{
    discov[u] = low[u] = tim++;

    int count = 0;
    vis[u] = true;

    for (int v : graph[u])
    {
        if (vis[v])
            low[u] = min(low[u], discov[v]);

        if (vis[v] == false)
        {
            parent[v] = u;
            count++;
            dfs(graph, vis, parent, low, discov, articu_pt, v);

            low[u] = min(low[u], low[v]);

            //-------------------------------------
            if (parent[u] == -1 && count >= 2)
                articu_pt[u] = true;

            if (parent[u] != -1 && low[v] >= discov[u])
                articu_pt[u] = true;
            //-------------------------------------
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<vi> graph;
    graph.resize(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int parent[n + 1], discovered[n + 1], low[n + 1];
    bool vis[n + 1], artiPt[n + 1];

    memset(vis, 0, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    memset(discovered, -1, sizeof(discovered));
    memset(low, -1, sizeof(low));
    memset(artiPt, 0, sizeof(artiPt));

    cout << "\n==========================================\n";

    dfs(graph, vis, parent, low, discovered, artiPt, 0);

    cout << tim << endl;
    for (int i = 0; i <= n; i++)
        if (artiPt[i])
            cout << i << " ";

    cout << "\n==========================================\n";
    return 0;
}

/*
7 6
0 1
1 2
3 2
3 4
4 5
5 6




6 8
0 1
1 3
3 4
4 1
1 2
2 0
0 5
*/