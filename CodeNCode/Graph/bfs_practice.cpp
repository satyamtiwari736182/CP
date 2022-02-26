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
        // adj[v].pb({u, wt});
    }
}

void bfs(vector<pair<int, int>> adj[], int n, int src)
{
    bool visited[n + 1] = {0};
    visited[src] = true;
    queue<int> que;
    que.push(src);
    while (!que.empty())
    {
        int t = que.size();
        while (t--)
        {
            int node = que.front();
            que.pop();
            cout << node << " ";
            for (auto edge : adj[node])
            {
                if (visited[edge.first] == false)
                {
                    que.push(edge.first);
                    visited[edge.first] = true;
                }
            }
        }
        cout << endl;
    }
}

bool isValid(int n, int m, int row, int col, int visited[N][M]);

int dist[N][M];

int cnt = 1;
void dfs_2D(int n, int m, int row, int col, int visited[N][M])
{

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    // cout << row << " " << col << ", ";
    dist[row][col] = cnt++;
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if (isValid(n, m, newRow, newCol, visited))
            dfs_2D(n, m, newRow, newCol, visited);
    }
}

bool isValid(int n, int m, int row, int col, int visited[N][M])
{
    if (row >= n || col >= m || row < 0 || col < 0 || visited[row][col])
        return false;
    return true;
}

void bfs_2D(int n, int m, int row, int col)
{
    queue<pair<int, int>> que;
    int visited[N][M] = {0};

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    visited[row][col] = 1;
    dist[row][col] = 0;
    que.push({row, col});

    while (!que.empty())
    {
        int currRow = que.front().first;
        int currCol = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
            if (isValid(n, m, currRow + dx[i], currCol + dy[i], visited))
            {
                int newRow = currRow + dx[i];
                int newCol = currCol + dy[i];

                dist[newRow][newCol] = dist[currRow][currCol] + 1;

                visited[newRow][newCol] = 1;
                que.push({newRow, newCol});
            }
    }
}



//---------------------------------------------------------------------------

int counter = 0, tim = 0;
void scc(vector<pair<int, int>> adj[], int node, bool *visited, int *activeNode, int *inTime, int *lowLink, stack<int> *stk)
// Tarzen's Alorithms for Strongly Connected Components
{
    visited[node] = true;
    stk->push(node);
    activeNode[node] = 1;
    inTime[node] = lowLink[node] = tim++;

    for (auto edge : adj[node])
    {
        int child = edge.first;
        if (visited[child] == false)
        {
            scc(adj, child, visited, activeNode, inTime, lowLink, stk);
            if (activeNode[child] == true)
                lowLink[node] = min(lowLink[child], lowLink[node]);
            activeNode[child] = 0;
        }
        else
        {
            if (activeNode[child] == true)
                lowLink[node] = min(lowLink[node], inTime[child]);
        }
    }

    if (inTime[node] == lowLink[node])
    {
        counter++;
        cout << "SCC # " << counter << endl;
        while (1)
        {
            int top = stk->top();
            stk->pop(), activeNode[top] = false;
            cout << top << " ";
            if (top == node)
                break;
        }
        cout << endl;
    }

    /*int top = stk->top();
    int flag = 0;
    while (lowLink[top] == inTime[top])
    {
        stk->pop();
        activeNode[top] = 0;
        top = stk->top();
        flag = 1;
    }
    if (flag)
        counter++;*/
}

//------------------------------------------------------------------

// scc_kosaraju's Algorithms.

void build_G_T(vector<pair<int, int>> adj[], vector<pair<int, int>> trans[], int e)
{
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb(make_pair(v, wt));
        trans[v].pb({u, wt});
    }
}

vi orders, SCC;

void dfs1(vector<pair<int, int>> adj[], int node, bool *vis)
{
    vis[node] = true;
    for (auto edge : adj[node])
        if (vis[edge.first] == false)
            dfs1(adj, edge.first, vis);
    orders.pb(node);
}

void dfs2(vector<pair<int, int>> trans[], int node, bool *vis)
{
    vis[node] = true;
    for (auto edge : trans[node])
        if (vis[edge.first] == false)
            dfs2(trans, edge.first, vis);
    SCC.pb(node);
}

void scc_kosaraju(vector<pair<int, int>> adj[], vector<pair<int, int>> trans[], int n)
{
    bool visited[n + 1] = {0};
    REP(1, n)
    if (visited[i] == false)
        dfs1(adj, i, visited);

    memset(visited, 0, sizeof(visited));

    // cout << "\n--->  " << orders[orders.size() - 1] << endl;

    for (int i = orders.size(); i > 0; i--)
        if (visited[orders[i - 1]] == false)
        {
            SCC.clear();
            dfs2(trans, orders[i - 1], visited);
            cout << "dfs2() called from " << orders[i - 1] << " and printing SCC " << endl;
            for (int node : SCC)
                cout << node << " ";
            cout << endl;
        }
}

//------------------------------------------------------------------------

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1], trans[n + 1];
    build_G_T(adj, trans, e);

    int outTime[n + 1] = {-1};
    cout << "\n****************************" << endl;
    display(adj, n);
    cout << "\n****************************" << endl;
    display(trans, n);
    cout << "\n****************************" << endl;
    scc_kosaraju(adj, trans, n);

    /*int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];

    buildGraph(adj, e);
    display(adj, n);

    bool visited[n + 1] = {0};
    int inTime[n + 1] = {0}, lowLink[n + 1] = {0}, activeNode[n + 1] = {0};
    stack<int> stk;
    // bfs(adj, n, 3);
    // dist[2][2] = 0;

    // int visited[N][M];

    memset(visited, 0, sizeof(visited));
    // scc(adj, 3, visited, activeNode, inTime, lowLink, &stk);

    /*for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            scc(adj, i, visited, activeNode, inTime, lowLink, &stk);*/

    /*bfs_2D(5, 5, 2, 2);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }*/

    cout << "\nhello!" << endl;
    return 0;
}
