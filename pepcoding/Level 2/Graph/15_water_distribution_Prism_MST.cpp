// There are n construction sites in a town. We want to supply water for all the construction sites by building wells and laying pipes.

// For each site i, we can either build a well inside it directly with cost wells[i-1], or pipe in water from another well to it. The costs to lay pipes between
// sites are given by the 2d array cost, where each row of cost contains 3 numbers ai,bi and wi where wi is the cost to connect ai to bi. connections are bidirectional.

// Return the minimum total cost to supply water to all the construction sites.

#include "../header.h"

class Pair
{
public:
    int vtx, wt;
    Pair(int vtx, int wt) : vtx(vtx), wt(wt) {}
};

int main()
{

    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<vector<Pair>> graph;
    graph.resize(n + 1);

    // Constructing graph with cost of water distribution pipeline
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back(Pair(v, wt));
        graph[v].push_back(Pair(u, wt));
    }

    // Cost of digging well in that city
    vi wells;
    wells.pb(0);
    for (int i = 1; i <= n; i++)
    {
        int cst;
        cin >> cst;
        wells.push_back(cst);
    }

    // Reframing graph, by making dummy node '0' as water source.
    // Adding cost from water souce to city eqivalent to it's well digging cost.

    for (int i = 1; i <= n; i++)
    {
        graph[i].push_back(Pair(0, wells[i]));
        graph[0].push_back(Pair(i, wells[i]));
    }

    //---------------------------------------------

    auto cmpr = [&](const Pair &a, const Pair &b)
    { return b.wt < a.wt; };

    priority_queue<Pair, vector<Pair>, decltype(cmpr)> pque(cmpr);

    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    pque.push(Pair(0, 0));

    // Applying Prism's algo of Minimum Spanning Tree Algorithm.
    // To minimum cost for water supply
    while (!pque.empty())
    {
        Pair temp = pque.top();
        pque.pop();
        if (vis[temp.vtx] == true)
            continue;

        ans += temp.wt;
        vis[temp.vtx] = true;

        vector<Pair> nbrs = graph[temp.vtx];
        for (Pair nbr : nbrs)
            if (vis[nbr.vtx] == false)
                pque.push(nbr);
    }

    //---------------------------------------------
    cout << "\n==========================================\n";
    cout << ans;
    cout << "\n==========================================\n";
    return 0;
}

/*
4 5
0 1 10
1 2 12
2 3 14
0 3 16
0 2 13
40 50 60 70
*/