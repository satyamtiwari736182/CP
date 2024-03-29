// 1. You are given a graph.
// 2. You are required to find and print all connected components of the graph.

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

void getComponents(vector<Edge> grph[], int n, int node, bool *visited, vector<int> &comp)
{
    visited[node] = true;
    comp.push_back(node);
    for (auto edge : grph[node])
        if (visited[edge.nbr] == false)
            getComponents(grph, n, edge.nbr, visited, comp);
}

void getConnectComponent(vector<Edge> grph[], int n, vector<vector<int>> &components)
{
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        vector<int> comp;
        if (visited[i] == false)
            getComponents(grph, n, i, visited, comp);
        if (comp.size())
            components.push_back(comp);
    }
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
    vector<vector<int>> components;
    getConnectComponent(grph, n, components);
    for (auto comp : components)
    {
        parr(comp, comp.size());
        cout << endl;
    }
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
8 8
1 2 10
2 3 10
3 1 10
8 4 1
4 8 1
5 7 1
7 6 1
6 5 1
*/

// 7
// 5
// 0 1 10
// 2 3 10
// 4 5 10
// 5 6 10
// 4 6 10