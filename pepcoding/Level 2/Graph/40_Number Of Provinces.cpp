// https://leetcode.com/problems/number-of-provinces/

#include "../header.h"

void dfs(vvi &graph, int i)
{
    graph[i][i] = 0;
    for (int j = 0; j < graph.size(); j++)
        if (graph[i][j] == 1)
        {
            graph[i][j] = 0;
            if (graph[j][j] == 1)
                dfs(graph, j);
        }
}

int findNumProvince(vvi &graph)
{
    int cnt = 0, n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (graph[i][i] == 0)
            continue;
        cnt++;
        dfs(graph, i);
    }
    return cnt;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vvi grph(n, vi(n));
    rmatrix(grph, n, n);
    cout << "\n==========================================\n";
    cout << findNumProvince(grph);
    cout << "\n==========================================\n";
    return 0;
}

/*

3
0 1 0
1 1 0
0 0 1

*/