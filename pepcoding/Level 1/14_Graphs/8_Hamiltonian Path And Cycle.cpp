// 1. You are given a graph and a src vertex.
// 2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

// Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
// Note -> Print in lexicographically increasing order.



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

void hamiltonianPath(vector<Edge> grph[], int n, int src, set<int> &visited, string psf, int isrc)
{
    if (visited.size() == n - 1)
    {
        char ch = '.';
        for (auto node : grph[src])
            if (node.nbr == isrc)
                ch = '@';
        cout << psf << " " << ch << endl;
    }
    visited.insert(src);
    for (auto edge : grph[src])
        if (visited.count(edge.nbr) == 0)
            hamiltonianPath(grph, n, edge.nbr, visited, psf + " " + to_string(edge.nbr), isrc);
    visited.erase(src);
}

void solve()
{
    int n, e, src;
    cin >> n >> e;
    vector<Edge> grph[100];
    makeGraph(grph, e);
    cin >> src;
    cout << "\n*******\n";
    display(grph, n);
    cout << "\n*******\n";
    set<int> visited;
    hamiltonianPath(grph, n, src, visited, to_string(src), src);
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
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 2 5 10
// 0