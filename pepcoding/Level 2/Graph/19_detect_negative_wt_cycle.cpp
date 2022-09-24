// You are given 2 integers N and M , N is the number of vertices, M is the number of edges. You'll also be given ai, bi and wi where ai and bi represents an edge from a vertex ai to a vertex bi and wi respresents the weight of that edge.

// Task is to find if it contains a negative weight cycle or not.

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
    // Bellman's ford algorith for negative weight cycle detection
    int flag = 0;
    path[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (Pair edge : edges)
        {
            // if (path[edge.u] == INF)
            //     continue;
            if (path[edge.u] + edge.wt < path[edge.v])
            {
                if (i == n - 1)
                    flag = true;

                path[edge.v] = path[edge.u] + edge.wt;
            }
        }
    }
    //---------------------------------------------
    cout << "\n==========================================\n";
    if (flag)
        cout << "Contains negative weight cycle" << endl;
    else
        cout << "NO negative weight cycle present" << endl;
    parr(path, n);
    cout << "\n==========================================\n";
    return 0;
}

/*
4 5
0 1 -10
1 2 -12
2 3 14
0 3 16
2 0 -13

*/