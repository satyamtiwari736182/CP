#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
#define vi vector<int>
#define vp vector<pair<int, int>>
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

int n;
vector<vi> capacity; // contains both  residual capacity and reverse residual capacity
vector<vi> adj;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];

            capacity[prev][cur] -= new_flow; // resudual flow capacity
            capacity[cur][prev] += new_flow; // reverse resudual flow capacity

            cur = prev;
        }
    }

    return flow;
}
void flowgraph(int e)
{
    int u, v, cap;
    while (e--)
    {
        vi vec;
        cin >> u >> v >> cap;

        adj[u].pb(v);
        adj[v].pb(u);

        capacity[u][v] = cap; // capacity matrix.
    }
}

void display(vector<vi> &adj)
{
    // display the adjacency list

    for (int i = 1; i < adj.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << ", ";
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int e;
    cin >> n >> e;
    REP(1, n + 1)
    {
        vi v;
        adj.pb(v);
        vi v2(n + 1);
        capacity.pb(v2);
    }
    flowgraph(e);
    cout << "\n**************************\n";

    display(adj);
    cout << "\n**************************\n";
    display(capacity);

    cout << "\nhello! " << maxflow(1, n) << endl;

    return 0;
    // vi par(10);
    // fill(all(par), INF);
    // print(par, 0, 9);
}

// 6 9
// 1 2 7
// 1 5 4
// 5 2 3
// 5 4 2
// 2 3 5
// 2 4 3
// 4 6 5
// 4 3 3
// 3 6 8