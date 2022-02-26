#include <bits/stdc++.h>
#include <iostream>
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

class Edge
{
public:
    int src, nbr, wt;
    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void display(vector<Edge> grph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "--> ";
        for (auto data : grph[i])
            cout << data.src << " " << data.nbr << " " << data.wt << ", ";
        cout << endl;
    }
}

void insert(vector<Edge> grph[], int n)
{
    cout << "Enter edges src nbr wt:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\tNo. of edge from node " << i << " : ";
        int edg;
        cin >> edg;
        while (edg > 0)
        {
            int src, nbr, wt;
            cin >> src >> nbr >> wt;
            Edge edge(src, nbr, wt);
            grph[i].pb(edge);
            edg--;
        }
    }
}

void mygraph(vector<Edge> grph[], int n)
{
    grph[0].pb(Edge(0, 1, 10));
    grph[0].pb(Edge(0, 3, 40));

    grph[1].pb(Edge(1, 0, 10));
    grph[1].pb(Edge(1, 2, 10));

    grph[2].pb(Edge(2, 1, 10));
    grph[2].pb(Edge(2, 3, 10));
    // grph[2].pb(Edge(2, 4, 5));

    grph[3].pb(Edge(3, 0, 40));
    grph[3].pb(Edge(3, 2, 10));
    // grph[3].pb(Edge(3, 4, 2));

    // grph[4].pb(Edge(4, 3, 2));
    // grph[2].pb(Edge(4, 2, 5));
    grph[4].pb(Edge(4, 5, 3));
    grph[4].pb(Edge(4, 6, 8));

    grph[5].pb(Edge(5, 4, 3));
    grph[5].pb(Edge(5, 6, 3));

    grph[6].pb(Edge(6, 4, 8));
    grph[6].pb(Edge(6, 5, 3));

    grph[7].pb(Edge(7, 8, -15));
    grph[8].pb(Edge(8, 7, -15));
}

bool hasPath(vector<Edge> grph[], int src, int dest, bool *visited)
{
    if (src == dest)
        return true;

    visited[src] = true;
    for (auto source : grph[src])
    {
        if (visited[source.nbr] == false)
        {
            bool hasNbrPath = hasPath(grph, source.nbr, dest, visited);
            if (hasNbrPath)
                return true;
        }
    }
    visited[src] = false;
    return false;
}

void printPath(vector<Edge> grph[], int src, int dest, bool *visited, string psf)
{
    if (src == dest)
    {
        cout << psf << endl;
        return;
    }

    visited[src] = true;

    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            printPath(grph, edge.nbr, dest, visited, psf + " " + to_string(edge.nbr));

    visited[src] = false;
}

int static lwt = INT_MAX, hwt = INT_MIN, cwtpath = INT_MAX, fwtpath = INT_MIN;
static string lwtpath = "", hwtpath = "", cpath = "", fpath = "";

priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> static pq;

void multiSolver(vector<Edge> grph[], int src, int dest, bool *visited, string psf, int budget, int k, int wtsf)
{
    if (src == dest)
    {
        cout << psf << " @ " << wtsf << endl;

        if (wtsf < lwt)
        {
            lwt = wtsf;
            lwtpath = psf + " @ " + to_string(lwt);
        }

        if (wtsf > hwt)
        {
            hwt = wtsf;
            hwtpath = psf + " @ " + to_string(hwt);
        }

        if (wtsf > budget && wtsf < cwtpath)
        {
            cwtpath = wtsf;
            cpath = psf + " @ " + to_string(cwtpath);
        }

        if (wtsf < budget && wtsf > fwtpath)
        {
            fwtpath = wtsf;
            fpath = psf + " @ " + to_string(fwtpath);
        }

        if (pq.size() < k)
        {
            pq.push({wtsf, psf});
        }
        else
        {
            if (pq.top().first < wtsf)
            {
                pq.pop();
                pq.push({wtsf, psf});
            }
        }
        return;
    }

    visited[src] = true;

    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            multiSolver(grph, edge.nbr, dest, visited, psf + " " + to_string(edge.nbr), budget, k, wtsf + edge.wt);

    visited[src] = false;
}
void getComponent(vector<Edge> grph[], int src, bool *visited, vector<int> component[], int count)
{
    visited[src] = true;
    for (auto edge : grph[src])
    {
        if (visited[edge.nbr] == false)
        {
            component[count].push_back(edge.nbr);
            getComponent(grph, edge.nbr, visited, component, count);
        }
    }
}
void getConnectedComponent(vector<Edge> grph[], int n)
{
    int count = -1;
    bool visited[n];
    vector<int> component[3];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            count++;
            component[count].push_back(i);
            getComponent(grph, i, visited, component, count);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "[ ";
        for (auto node : component[i])
            cout << node << ", ";
        cout << " ]" << endl;
    }
}

void isConnected(vector<Edge> *grph, int n, int src, bool *visited)
{
    visited[src] = true;
    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            isConnected(grph, n, edge.nbr, visited);
}

int noConnectedComponent(vector<Edge> grph[], int n)
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            count = count + 1;
            isConnected(grph, n, i, visited);
        }
    }
    return count;
}

void markIsland(int grph[M][N], int n, int m, int sr, int sc, bool visited[M][N])
{

    if (sr >= n || sc >= m || sr < 0 || sc < 0 || grph[sr][sc] == 1 || visited[sr][sc] == true)
        return;
    visited[sr][sc] = true;

    markIsland(grph, n, m, sr, sc + 1, visited);
    markIsland(grph, n, m, sr, sc - 1, visited);
    markIsland(grph, n, m, sr + 1, sc, visited);
    markIsland(grph, n, m, sr - 1, sc, visited);
}

int noIsland(int grph[M][N], int n, int m)
{
    int count = 0;
    bool visited[M][N];
    memset(visited, 0, sizeof(visited));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grph[row][col] == 0 && visited[row][col] == false)
            {
                count++;
                markIsland(grph, n, m, row, col, visited);
            }
        }
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[M][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << endl
         << noIsland(arr, n, m) << endl;
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);

    // cout << "No. of Node: " << endl;
    // int n = 9;
    // // cin >> n;
    // vector<Edge> grph[n];
    // // insert(grph, n);

    // mygraph(grph, n);
    // // display(grph, n);

    // cout << endl;

    // bool visited[n];
    // memset(visited, 0, sizeof(visited));

    // cout << "has path: " << hasPath(grph, 4, 7, visited) << endl
    //      << endl;

    // memset(visited, 0, sizeof(visited));

    // printPath(grph, 0, 5, visited, to_string(0));

    //---------------------------------------------------------------------------------------
    // multiSolver(grph, 0, 6, visited, to_string(0), 56, 2, 0);
    // cout << endl
    //      << "Least Cost path" << lwtpath << endl
    //      << "Costly path: " << hwtpath << endl
    //      << "k largest path: " << pq.top().second << " @ " << pq.top().first << endl
    //      << "Ceil path: " << cpath << endl
    //      << "Floor path: " << fpath << endl;
    //---------------------------------------------------------------------------------------

    // getConnectedComponent(grph, n);

    // isConnected(grph, n, 5, visited);

    // bool isconn = true;
    // for (int i = 0; i < n; i++)
    //     if (visited[i] == false)
    //         isconn = false;

    // print(visited, 0, n - 1);

    // cout << endl
    //      << "Is connected: " << isconn << endl;

    // cout << "No. of connected component : " << noConnectedComponent(grph, n) << endl;

    cout << endl
         << "hello!" << endl;

    return 0;
}
