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
        // grph[nb].pb(Edge(nb, sr, wt));
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

void dfs(vector<Edge> grph[], int src, int *visited, stack<int> &stk)
{
    visited[src] = true;
    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            dfs(grph, edge.nbr, visited, stk);
    stk.push(src);
}

void topologicalSort(vector<Edge> grph[], int n)
{
    int visited[100] = {0};
    stack<int> stk;

    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            dfs(grph, i, visited, stk);

    vi arr(n);

    int idx = n - 1;
    while (!stk.empty())
        arr[idx--] = stk.top(), stk.pop();

    cout << "TopicalSort order: ";
    parr(arr, n);
    cout << endl;
    cout << "Order of task completion: ";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
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
    
    topologicalSort(grph, n);
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
7
7
0 1 10
1 2 10
2 3 10
0 3 10
4 5 10
5 6 10
4 6 10


*/