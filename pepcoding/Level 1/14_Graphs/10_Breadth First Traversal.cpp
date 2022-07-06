// 1. You are given a graph, and a src vertex.
// 2. You are required to do a breadth first traversal and print which vertex is reached via which path,
//      starting from the src.

// Note -> for output, check the sample output and question video.

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

void BFS(vector<Edge> grph[], int src)
{
    queue<Pair> que;
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    que.push(Pair(src, to_string(src)));
    visited[src] = true;
    while (que.empty() == false)
    {
        auto temp = que.front();
        cout << temp.v << " @ " << temp.psf << endl;
        for (auto edge : grph[temp.v])
            if (visited[edge.nbr] == false)
            {
                que.push(Pair(edge.nbr, temp.psf + " " + to_string(edge.nbr)));
                visited[edge.nbr] = true;
            }
        que.pop();
    }
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
    BFS(grph, src);
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
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 2