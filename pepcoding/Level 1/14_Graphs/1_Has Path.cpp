// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are required to find if a path exists between src and dest. If it does, print true
//      otherwise print false.

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

class Pair
{
public:
    int v;
    string psf;
    Pair(int v, string psf)
    {
        this->v = v;
        this->psf = psf;
    }
};

void makeGraph(vector<Edge> grph[], int n, int e)
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

bool hasPath(vector<Edge> grph[], int src, int desti, int *visited)
{
    visited[src] = true;
    if (src == desti)
        return true;
    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
        {
            bool pathfound = hasPath(grph, edge.nbr, desti, visited);
            if (pathfound == true)
                return true;
        }

    return false;
}

int main()
{
    cout << "hello!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Edge> grph[100];
    makeGraph(grph, n, e);
    cout << "\n----------------" << endl;
    display(grph, n);
    cout << "\n----------------" << endl;
    //---------------------------------------------------

    int src, desti;
    int visited[100] = {0};
    cin >> src >> desti;
    cout << hasPath(grph, src, desti, visited);
    //---------------------------------------------------

    cout << "\nhello!" << endl;
    return 0;
}

// 7
// 7
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 4 5 10
// 5 6 10
// 4 6 10
// 0
// 6