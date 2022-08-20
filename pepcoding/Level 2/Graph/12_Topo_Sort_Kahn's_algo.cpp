#include "../header.h"

void display(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto node : graph[i])
            cout << node << ", ";
        cout << endl;
    }
}

void TopoSort_kahn(vector<vi> &graph)
{
    int n = graph.size();
    int indegree[n], ans[n];
    memset(indegree, 0, sizeof(indegree));

    for (int i = 0; i < n; i++)
        for (int node : graph[i])
            indegree[node]++;

    // for (int i = 0; i < n; i++)
    //     cout << indegree[i] << " ";

    queue<int> que;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            que.push(i);

    int idx = 0;

    while (!que.empty())
    {
        int temp = que.front();
        que.pop();

        ans[idx] = temp;
        idx++;
        for (int node : graph[temp])
        {
            indegree[node]--;

            if (indegree[node] == 0)
                que.push(node);
        }
    }

    if (idx == n)
    {
        parr(ans, n);
    }

    else
        cout << "\n"
             << idx << "\t" << n;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph;
    graph.resize(n);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        // graph[v].pb(u); // adding a reverse edge with weight 1.
    }
    cout << "\n----------------------------\n";
    display(graph);
    cout << "\n----------------------------\n";
    TopoSort_kahn(graph);
    cout << "\n----------------------------\n";

    return 0;
}

// 6 6
// 0 2
// 0 3
// 1 2
// 1 5
// 3 4
// 4 5