// An edge in an undirected graph is a Bridge iff removing it disconnects the graph. You have to print all the Bridges of the given graph.


#include "../header.h"

int tim = 0;
void dfs(vector<vi> &graph, bool *vis, int *parent, int *low, int *discov, vector<string> &articu_pt, int u)
{
    discov[u] = low[u] = tim++;

    int count = 0;
    vis[u] = true;

    for (int v : graph[u])
    {
        if (vis[v])
            low[u] = min(low[u], discov[v]);

        if (vis[v] == false)
        {
            parent[v] = u;
            count++;
            dfs(graph, vis, parent, low, discov, articu_pt, v);

            low[u] = min(low[u], low[v]);

            //-------------------------------------
            if (low[v] > discov[u])
            {
                cout << v << " ";
                string str = to_string(u) + " <-> " + to_string(v);
                articu_pt.pb(str);
            }
            //-------------------------------------
        }
    }
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
        graph[v].pb(u);
    }

    int parent[n + 1], discovered[n + 1], low[n + 1];
    bool vis[n + 1];
    vector<string> artiPt;

    memset(vis, 0, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    memset(discovered, -1, sizeof(discovered));
    memset(low, -1, sizeof(low));
    // memset(artiPt, 0, sizeof(artiPt));

    cout << "\n==========================================\n";

    dfs(graph, vis, parent, low, discovered, artiPt, 0);
    cout << artiPt.size() << endl;
    for (auto i : artiPt)
        cout << i << " ";

    cout << "\n==========================================\n";
    return 0;
}

/*
6 7
0 1
0 2
1 3
3 4
4 5
5 3
1 2

*/