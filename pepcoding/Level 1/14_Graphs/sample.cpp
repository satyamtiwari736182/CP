// Pepcoding offers total of n courses labelled from 0 to n-1.

// Some courses may have prerequisites. you have been given m pairs ai,bi. where 1 pair means you must take the course bi before the course ai.

// Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses. If it is impossible to finish all courses print -1.



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
    graph.resize(n+1);

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

/*
6 6
1 3 
2 3 
3 4 
3 5 
4 6 
5 6 
*/

// 6 6
// 0 2
// 0 3
// 1 2
// 1 5
// 3 4
// 4 5