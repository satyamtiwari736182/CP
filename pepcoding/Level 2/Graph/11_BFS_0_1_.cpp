// You are given 2 integers N and M , N is the number of vertices, M is the number of edges. You'll also be given ai and bi where ai and bi represents an edge from a vertex ai to a vertex bi.

// You have to find the minimum number of edges you have to reverse in order to have atleast one path from vertex 1 to N, where the vertices are numbered from 1 to N.

#include "../header.h"

class Edge
{
public:
    int vtx, wt;
    Edge(int v, int wt) : vtx(v), wt(wt) {}
};

void display(vector<vector<Edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto edge : graph[i])
            cout << edge.vtx << " " << edge.wt << ", ";
        cout << endl;
    }
}

void BFS_0_1(vector<vector<Edge>> &graph)
{
    int n = graph.size();
    deque<Edge> que;

    bool visited[n];
    memset(visited, 0, sizeof(visited));

    que.push_back(Edge(1, 0));

    while (!que.empty())
    {
        Edge temp = que.front();

        que.pop_front();

        visited[temp.vtx] = true;

        if (temp.vtx == n - 1)
        {
            cout << temp.wt << " ";
            return;
        }

        for (Edge edge : graph[temp.vtx])
        {
            if (visited[edge.vtx] == false)
            {
                if (edge.wt == 0)
                    que.push_front(Edge(edge.vtx, temp.wt + 0));
                else
                    que.push_back(Edge(edge.vtx, temp.wt + 1));
            }
        }
    }

    cout << "-1";
}

int main()
{
    cout << "\nHello world!" << endl;

    int n, e;
    cin >> n >> e;
    vector<vector<Edge>> graph;
    graph.resize(n + 1);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(Edge(v, 0));
        graph[v].pb(Edge(u, 1)); // adding a reverse edge with weight 1.
    }
    cout << "\n----------------------------\n";
    display(graph);
    cout << "\n----------------------------\n";
    BFS_0_1(graph);
    cout << "\n----------------------------\n";

    return 0;
}

// 7 7
// 1 2
// 3 2
// 3 4
// 7 4
// 7 5
// 5 6
// 6 2

//! ==============================================================================================

/*

void display(vector<vector<pi>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto edge : graph[i])
            cout << edge.fs << " " << edge.se << ", ";
        cout << endl;
    }
}

void BFS_0_1(vector<vector<pi>> &graph)
{
    int n = graph.size();
    deque<pi> que;

    bool visited[n];
    memset(visited, 0, sizeof(visited));

    que.push_back({1, 0});

    while (!que.empty())
    {
        pi temp = que.front();

        que.pop_front();

        visited[temp.fs] = true;

        if (temp.fs == n - 1)
        {
            cout << temp.se << " ";
            return;
        }

        for (pi edge : graph[temp.fs])
        {
            if (visited[edge.fs] == false)
            {
                if (edge.se == 0)
                    que.push_front(mp(edge.fs, temp.se + 0));
                else
                    que.push_back(mp(edge.fs, temp.se + 1));
            }
        }
    }

    cout << "-1";
}

int main()
{
    cout << "\nHello world!" << endl;

    int n, e;
    cin >> n >> e;
    vector<vector<pi>> graph;
    graph.resize(n + 1);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(mp(v, 0));
        graph[v].pb(mp(u, 1)); // adding a reverse edge with weight 1.
    }
    cout << "\n----------------------------\n";
    display(graph);
    cout << "\n----------------------------\n";
    BFS_0_1(graph);
    cout << "\n----------------------------\n";

    return 0;
}

*/