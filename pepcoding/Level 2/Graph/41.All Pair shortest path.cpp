#include "../header.h"

void flodyWarshall(vvi &graph)
{
    for (int k = 0; k < graph.size(); k++)
        for (int i = 0; i < graph.size(); i++)
            for (int j = 0; j < graph.size(); j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main()
{
    cout << "hello world!\n";
    int n, e;
    cin >> n >> e;
    vvi graph(n + 1, vi(n + 1, 1e9));
    while (e-- > 0)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u][v] = wt; //, graph[v][u] = wt;
        graph[v][v] = graph[u][u] = 0;
    }
    cout << "***********\n";
    flodyWarshall(graph);
    pmatrix(graph, n, n);
    return 0;
}

/*

//**undirected graph**
4 6
1 2 11
1 3 1
1 4 6
2 3 7
2 4 3
3 4 2
******************
//**directed graph**
4 6
0 1 2
1 0 1
1 2 3
3 1 5
3 2 4
3 0 3

*/