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

void display(vector<pair<int, int>> adj[], int n)
{
    // display the adjacency list
    for (int i = 0; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto nbr : adj[i])
            cout << nbr.first << " " << nbr.second << ",";
        cout << endl;
    }
    cout << endl;
}

void buildGraph(vector<pair<int, int>> adj[], int e)
{
    // graph creation
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb(make_pair(v, wt));
        adj[v].pb({u, wt});
    }
}

void dfs(vector<pair<int, int>> adj[], int src, int *visited)
{
    visited[src] = 1;
    cout << src << " ";
    for (auto nbr : adj[src])
    {
        if (visited[nbr.first] == false)
            dfs(adj, nbr.first, visited);
    }
}

int cc(vector<pair<int, int>> adj[], int n)
{
    int count = 0, visited[n + 1] = {0};
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
        {
            count++;
            dfs(adj, i, visited);
        }
    return count;
}

void sssp(vector<pair<int, int>> adj[], int src, bool *visited, int *dist, int cnt)
{
    visited[src] = true;
    cout << cnt << " ";
    if (cnt < dist[src])
        dist[src] = cnt;
    for (auto edge : adj[src])
        if (visited[edge.first] == false)
            sssp(adj, edge.first, visited, dist, cnt + 1);
}

bool bipartite(vector<pair<int, int>> adj[], int u, bool *visited, int *color, int c)
{
    visited[u] = true;
    color[u] = c;
    for (auto edge : adj[u])
    {
        int v = edge.first;
        if (visited[v] == false)
            if (bipartite(adj, v, visited, color, !c) == false)
                return false;
            else if (color[v] == color[u])
                return false;
    }
    return true;
}

bool hasCycle(vector<pair<int, int>> adj[], int node, int par, bool *visited)
{
    visited[node] = 1;
    for (auto edge : adj[node])
    {
        int child = edge.first;
        if (visited[child] == false)
        {
            if (hasCycle(adj, child, node, visited))
                return true;
        }

        else
        {
            if (child != par)
                return true;
        }
    }
    return false;
}

void flattenGraph(vector<pair<int, int>> adj[], int node, int *inTime, int *outTime, bool *visited, int *timer)
{
    visited[node] = true;
    inTime[node] = (*timer)++;
    for (auto edge : adj[node])
    {
        int child = edge.first;
        if (visited[child] == false)
            flattenGraph(adj, child, inTime, outTime, visited, timer);
    }

    outTime[node] = (*timer)++;
}

int maxD, lastNode;
void dfs_diameter(vector<pair<int, int>> adj[], bool *visited, int node, int dist)
{
    if (maxD < dist)
    {
        maxD = dist;
        lastNode = node;
    }
    visited[node] = true;
    for (auto edge : adj[node])
        if (visited[edge.first] == false)
            dfs_diameter(adj, visited, edge.first, dist + 1);
}

int subSize(vector<pair<int, int>> adj[], bool *visited, int node, int *sub_size)
{
    int size = 1;
    visited[node] = true;
    for (auto edge : adj[node])
        if (visited[edge.first] == false)
            size += subSize(adj, visited, edge.first, sub_size);
    sub_size[node] = size;
    return size;
}
// 5 4
// 1 2 1
// 2 3 1
// 2 4 1
// 4 5 1
// 3 4 1

void dfs_bridge(vector<pair<int, int>> adj[], int node, int parent, bool *visited, int *inTime, int *lowTime, int *timer)
// Cut-Edges
{
    visited[node] = true;
    lowTime[node] = inTime[node] = (*timer)++;
    for (auto edge : adj[node])
    {
        int child = edge.first;
        if (visited[child] == false)
        {
            // forward-edge
            dfs_bridge(adj, child, node, visited, inTime, lowTime, timer);
            lowTime[node] = min(lowTime[node], lowTime[child]);

            // checking condition for bridge
            if (lowTime[child] > inTime[node])
                cout << node << " - " << child << endl;
        }
        else
        {
            // back-edge
            if (child == parent)
                continue;
            if (child != parent)
                lowTime[node] = min(lowTime[node], inTime[child]);
        }
    }
}

void dfs_articulationPoint(vector<pair<int, int>> adj[], int node, int parent, bool *visited, int *inTime, int *lowTime, int *timer)
// Cut-vertices
{
    visited[node] = true;
    lowTime[node] = inTime[node] = (*timer)++;
    int children = 0;
    for (auto edge : adj[node])
    {
        int child = edge.first;
        if (visited[child] == false)
        {
            // forward-edge
            dfs_articulationPoint(adj, child, node, visited, inTime, lowTime, timer);
            lowTime[node] = min(lowTime[node], lowTime[child]);

            // checking condition for bridge
            if (lowTime[child] >= inTime[node] && parent != -1)
                cout << node << ", ";
            children++;
        }
        else
        {
            // back-edge
            if (child == parent)
                continue;
            if (child != parent)
                lowTime[node] = min(lowTime[node], inTime[child]);
        }
    }
    // check for root node
    if (parent == -1 && children > 1)
        cout << node << ", ";
}
// 4 4
// 1 2 10
// 2 3 10
// 2 4 10
// 3 4 10

int main()
{
    // graph structure
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];

    buildGraph(adj, e);
    display(adj, n);

    bool visited[n + 1] = {0};
    /*int inTime[n + 1] = {0};
    int outTime[n + 1] = {0};

    int iscyclic = hasCycle(adj, 1, -1, visited);

    memset(visited, 0, sizeof(visited));
    int timer = 1;
    flattenGraph(adj, 2, inTime, outTime, visited, &timer);

    cout << endl;
    print(inTime, 1, n);
    cout << endl;

    print(outTime, 1, n);*/

    memset(visited, 0, sizeof(visited));
    // dfs_diameter(adj, visited, 1, 0);
    // cout << "\nhello! " << maxD << " " << lastNode << endl;

    int subsize[n + 1] = {0};
    subSize(adj, visited, 1, subsize);
    print(subsize, 1, n);

    int inTime[n + 1] = {0}, lowTime[n + 1] = {0}, timer = 0;
    dfs_articulationPoint(adj, 3, -1, visited, inTime, lowTime, &timer);

    cout << "\nhello! " << endl;
    return 0;
}
