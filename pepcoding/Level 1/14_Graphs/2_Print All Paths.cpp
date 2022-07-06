// 1. You are given a graph, a source vertex and a destination vertex.
// 2. You are required to find and print all paths between source and destination. Print
//      them in lexicographical order.

//     E.g. Check the following paths
//              012546
//              01256
//              032546
//              03256

//     The lexicographically smaller path is printed first.

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

void printAllPath(vector<Edge> grph[], int src, int desti, int *visited, string psf)
{
    if (src == desti)
        cout << psf << "\n";

    visited[src] = true;

    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            printAllPath(grph, edge.nbr, desti, visited, psf + " " + to_string(edge.nbr));

    visited[src] = false;
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
    printAllPath(grph, src, desti, visited, to_string(src));
    //---------------------------------------------------

    cout << "\nhello!" << endl;
    return 0;
}

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
// 0
// 6