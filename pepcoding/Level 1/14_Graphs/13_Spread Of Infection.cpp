// 1. You are given a graph, representing people and their connectivity.
// 2. You are also given a src person (who got infected) and time t.
// 3. You are required to find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time.

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
    int tim, node;
    Pair(int n, int t) : tim(t), node(n) {}
};

int cntInfection(vector<Edge> grph[], int node, int t, int *visited)
{
    queue<Pair> que;
    que.push(Pair(node, 1));

    int cnt = 0;
    while (!que.empty())
    {
        Pair src = que.front();
        que.pop();

        if (visited[src.node] > 0)
            continue;

        if (src.tim > t)
            break;

        visited[src.node] = src.tim;
        cnt++;

        for (auto edge : grph[src.node])
            if (visited[edge.nbr] == 0)
                que.push(Pair(edge.nbr, src.tim + 1));
    }
    return cnt;
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
    int src, t;
    cin >> src >> t;
    int visited[100];
    fill(visited, visited + 100, 0);
    cout << cntInfection(grph, src, t, visited);
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
// 6
// 3