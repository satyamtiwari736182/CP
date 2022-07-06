// 1. You are given a graph and a source vertex. The vertices represent computers and the edges
//      represent length of LAN wire required to connect them.
// 2. You are required to find the minimum length of wire required to connect all PCs over a network.
//      Print the output in terms of which all PCs need to be connected, and the length of wire between
//      them.

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
    int parent, node, wt;

    Pair(int parent, int node, int wt) : node(node), parent(parent), wt(wt) {}
};

bool comp(Pair p1, Pair p2)
{
    return p1.wt > p2.wt;
}
void prism(vector<Edge> grph[], int node, int *visited)
{
    priority_queue<Pair, vector<Pair>, function<bool(Pair, Pair)>> que(comp);
    que.push(Pair(-1, node, 0));
    while (!que.empty())
    {
        Pair temp = que.top();
        que.pop();
        if (visited[temp.node] == true)
            continue;
        if (temp.parent != -1)
            cout << "[" << temp.parent << "-" << temp.node << " @ " << temp.wt << "]" << endl;
        visited[temp.node] = true;
        for (auto edge : grph[temp.node])
            if (visited[edge.nbr] == false)
                que.push(Pair(temp.node, edge.nbr, edge.wt));
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
    // int src;
    // cin >> src;
    int visited[100] = {0};

    prism(grph, 0, visited);
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
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8