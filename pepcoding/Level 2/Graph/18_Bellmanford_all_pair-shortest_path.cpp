// You are given 2 integers N and M , N is the number of vertices, M is the number of edges. You'll also be given ai, bi and wi where ai and bi represents an edge from a vertex ai to a vertex bi and wi respresents the weight of that edge.
// Your task is to find the shortest path from source vertex (vertex number 1) to all other vertices.

// Note : use bellman ford algo.

#include "../header.h"

class Pair
{
public:
    int u, v, wt;
    Pair(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

int main()
{

    cout << "\nHello world!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Pair> edges;
    int path[n];
    fill(path, path + n, 1e9 + 7);
    // Constructing edges with the cost
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Pair(u, v, wt));
    }

    //---------------------------------------------
    // Bellman's ford algorith for single source shortest parth algorithm.
    path[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (Pair edge : edges)
        {
            // if (path[edge.u] == INF)
            //     continue;
            if (path[edge.u] + edge.wt < path[edge.v])
                path[edge.v] = path[edge.u] + edge.wt;
        }
    }
    //---------------------------------------------
    cout << "\n==========================================\n";
    parr(path, n);
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