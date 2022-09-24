// There are n vertices and there are edges in between some of the vertices. Find the sum  of edge weight of minimum spanning tree.

#include "../header.h"

class Pair
{
public:
    int u, v, wt;
    Pair(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp; // path compression for optimisation.
    return temp;
}

bool unionByRank(int *parent, int *rank, int x, int y)
{
    int px = findParent(parent, x);
    int py = findParent(parent, y);
    if (px != py)
    {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
            parent[px] = py, rank[py]++;

        return true;
    }
    return false;
}

int Kruskal_DSU(vector<Pair> &edges, int n)
{
    sort(all(edges), [&](auto first, auto second)
         { return first.wt < second.wt; });

    int *parent = new int[n + 1];
    int *rank = new int[n + 1];

    for (int i = 0; i <= n; i++)
        parent[i] = i, rank[i] = 1;

    int ans = 0;
    for (auto edge : edges)
        if (unionByRank(parent, rank, edge.u, edge.v))
            ans += edge.wt;

    parr(parent, n + 1);
    cout << endl;
    parr(rank, n + 1);
    cout << endl;

    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Pair> edges;

    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Pair(u, v, wt));
        edges.push_back(Pair(v, u, wt));
    }

    //---------------------------------------------

    cout << "\n==========================================\n";
    cout << Kruskal_DSU(edges, n) << endl;

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