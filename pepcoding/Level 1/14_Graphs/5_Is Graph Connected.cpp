// 1. You are given a graph.
// 2. You are required to find and print if the graph is connected (there is a path from
//      every vertex to every other).

#include "../header.h"

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

void makeGraph(vector<Edge> grph[], int e)
{
    for (int i = 0; i < e; i++)
    {
        int sr, nb, wt;
        cin >> sr >> nb >> wt;
        grph[sr].pb(Edge(sr, nb, wt));
        grph[nb].pb(Edge(nb, sr, wt));
    }
}

void display(vector<Edge> grph[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto edge : grph[i])
            cout << edge.src << " " << edge.nbr << " " << edge.wt << ", ";
        cout << endl;
    }
}

//*===========================================================================
//?===========================================================================

void getComponents(vector<Edge> grph[], int n, int node, bool *visited)
{
    visited[node] = true;
    for (auto edge : grph[node])
        if (visited[edge.nbr] == false)
            getComponents(grph, n, edge.nbr, visited);
}

bool isConnected(vector<Edge> grph[], int n, int src)
{
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    getComponents(grph, n, src, visited);
    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            return false;
    return true;
}

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> grph[100];
    makeGraph(grph, e);
    cout << "\n*******\n";
    display(grph, n);
    cout << "\n*******\n";
    cout << isConnected(grph, n, 1);
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 7
// 5
// 0 1 10
// 2 3 10
// 4 5 10
// 5 6 10
// 4 6 10