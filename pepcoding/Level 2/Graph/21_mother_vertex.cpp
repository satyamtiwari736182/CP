// Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.


#include "../header.h"

void dfs1(vector<vi> &graph, int src, bool *vis, stack<int> &stk)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs1(graph, nbr, vis, stk);
    stk.push(src);
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

    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));

    //---------------------------------------------
    stack<int> stk;
    for (int i = 0; i < n; i++)
        if (vis[i] == false)
            dfs1(graph, i, vis, stk);
    //---------------------------------------------
    cout << "\n==========================================\n";
    cout << stk.top();
    cout << "\n==========================================\n";
    return 0;
}

/*
7 6
0 1
1 2
3 2
3 4
4 5
5 6

*/