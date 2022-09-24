// There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair a particular road. Find out the minimum cost to connect all the cities by repairing roads.

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
    graph.resize(n);

    // Constructing graph with cost reparing roads to connect the cities
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back(Pair(v, wt));
        graph[v].push_back(Pair(u, wt));
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
    // To minimize cost for connecting cities
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

*/