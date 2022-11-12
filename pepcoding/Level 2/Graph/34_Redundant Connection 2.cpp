// You are given a directed graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [xi, yi] indicates that there is a directed edge between nodes xi and yi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

// Note : The difference between redundant connection and redundant connection 2 is that in later the graph is directed and in the former graph is undirected.

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
    int n = edges.size(); // No. of nodes
    vi indegree(n + 1, -1);
    int blkListEdge1 = -1, blkListEdge2 = -1;

    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0], v = edges[i][1];
        if (indegree[v] == -1)
            indegree[v] = i;
        else
        {
            blkListEdge1 = i;
            blkListEdge2 = indegree[v];
            break;
        }
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i, ranks[i] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i == blkListEdge1)
            continue;
        int u = edges[i][0];
        int v = edges[i][1];
        if (Union(u, v) == false)
        {
            if (blkListEdge1 == -1)
                return {u, v};
            else
                return {edges[blkListEdge2][0], edges[blkListEdge2][1]};
        }
    }

    return {edges[blkListEdge1][0], edges[blkListEdge1][1]};
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

7
1 2
1 3
2 4
2 5
2 6
3 6
3 7

*/

// 3
// 1 2
// 1 3
// 2 3