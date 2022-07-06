// 1. You are given a graph.
// 2. You are required to find and print if the graph is bipartite

// Note -> A graph is called bipartite if it is possible to split it's vertices in two sets of mutually
//                exclusive and exhaustive vertices such that all edges are across sets.

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
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto edge : grph[i])
            cout << edge.src << " " << edge.nbr << " " << edge.wt << ", ";
        cout << endl;
    }
}

//*===========================================================================
//?===========================================================================

bool chekBipartite(vector<Edge> grph[], int node, int *visited)
{
    queue<pi> que;
    que.push({node, 0});
    visited[node] = 0;
    while (!que.empty())
    {
        pi src = que.front();
        que.pop();

        if (visited[src.fs] != -1)
            if (src.se != visited[src.fs])
                return false;
        if (visited[src.fs] == -1)
            visited[src.fs] = src.se;

        for (auto edge : grph[src.fs])
            if (visited[edge.nbr] == -1)
                que.push({edge.nbr, src.se + 1});
    }
    return true;
}

bool isBipartite(vector<Edge> grph[], int n)
{
    int visited[100];
    fill(visited, visited + 100, -1);

    for (int node = 0; node < n; node++)
    {
        if (visited[node] == -1)
        {
            bool isbipart = chekBipartite(grph, node, visited);
            if (isbipart == false)
                return false;
        }
    }

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

    cout << isBipartite(grph, n - 1);
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
8
6
0 1 10
2 3 10
4 5 10
5 6 10
4 7 10
7 6 10


*/

// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10