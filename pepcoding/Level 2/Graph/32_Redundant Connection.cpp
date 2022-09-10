// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [xi, yi] indicates that there is an edge between nodes xi and yi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

#include "../header.h"

int parent[N];
int ranks[N];

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool Union(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if (px != py)
    {
        if (ranks[px] > ranks[py])
            parent[py] = px;
        else if (ranks[px] < ranks[py])
            parent[px] = py;
        else
            parent[px] = py, ranks[py]++;

        return true;
    }
    return false;
}

pi findRedundantConnection(vvi &edges)
{
    int n = edges.size() + 1; // No. of nodes
    for (int i = 1; i < n; i++)
        parent[i] = i, ranks[i] = 1;

    for (auto edg : edges)
    {
        int u = edg[0], v = edg[1];
        int lu = findParent(u), lv = findParent(v);
        if (lu != lv)
            Union(u, v);
        else
            return {u, v};
    }
    return {-1, -1};
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vvi edges(n, vi(2));
    rmatrix(edges, n, 2);
    cout << "\n==========================================\n";
    pi pr = findRedundantConnection(edges);
    cout << pr.fs << " " << pr.se;
    cout << "\n==========================================\n";
    return 0;
}

/*

3
1 2
1 3
2 3

*/