// 1. You are given a graph.
// 2. You are required to find and print if the graph is cyclic.

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
bool isCyclic(vector<Edge> grph[], int n, int src)
{
    queue<int> que;
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    que.push(src);
    while (que.empty() == false)
    {
        auto temp = que.front();
        if (visited[temp] == true)
            return true;
        visited[temp] = true;
        for (auto edge : grph[temp])
            if (visited[edge.nbr] == false)
                que.push(edge.nbr);
        que.pop();
    }
    return false;
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
    cout << isCyclic(grph, n, 1);
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 7
// 6
// 0 1 10
// 1 2 10
// 2 3 10
// 3 4 10
// 4 5 10
// 5 6 10