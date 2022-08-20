#include "../header.h"

void dfs1(vector<vi> &graph, int src, bool *vis, stack<int> &stk)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs1(graph, nbr, vis, stk);
    stk.push(src);
}

void dfs2(vector<vi> &graph, int src, bool *vis)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs2(graph, nbr, vis);
}

int main()
{

    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<vi> graph;
    graph.resize(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }

    bool *vis=new bool[n + 1];
    memset(vis, 0, sizeof(vis));

    //---------------------------------------------

    // step 1
    stack<int> stk;
    for (int i = 0; i < n; i++)
        if (vis[i] == false)
            dfs1(graph, i, vis, stk);

    // step 2
    vector<vi> revGraph;
    revGraph.resize(n + 1);

    for (int i = 0; i < n; i++)
        for (int nbr : graph[i])
            revGraph[nbr].pb(i);

    // step 3
    int count = 0;
    memset(vis, 0, sizeof(vis));
    while (!stk.empty())
    {
        int temp = stk.top();
        stk.pop();
        if (vis[temp] == false)
        {
            count++;
            dfs2(revGraph, temp, vis);
        }
    }

    //---------------------------------------------
    cout << "\n==========================================\n";
    cout << count;
    cout << "\n==========================================\n";
    return 0;
}

/*
7 5
0 1
1 2
3 4
5 6
6 5

*/