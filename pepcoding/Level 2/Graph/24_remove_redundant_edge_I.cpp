// Alice and Bob have an undirected graph of n nodes and 3 types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can by traversed by both Alice and Bob.

// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
// Return the maximum number of edges you can remove, or return -1 if it's impossible for the graph to be fully traversed by Alice and Bob.


#include "../header.h"

class Pair
{
public:
    int type, u, v;
    Pair(int t, int u, int v) : type(t), u(u), v(v) {}
    Pair() = default;
};

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(int *rank, int *parent, int x, int y)
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
        {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    return false;
}

int maximum_edges_removed(vector<Pair> &edges, int n)
{

    sort(all(edges), [&](const Pair a, const Pair b)
         { return a.type > b.type; });

    int parent_alice[n + 1], parent_bob[n + 1], rank_a[n + 1], rank_b[n + 1];
    for (int i = 0; i <= n; i++)
    {
        parent_alice[i] = i;
        parent_bob[i] = i;
        rank_a[i] = 1;
        rank_b[i] = 1;
    }

    int merged_a = 1;
    int merged_b = 1;
    int cnt_removed_edge = 0;

    for (auto removed_edge : edges)
    {
        if (removed_edge.type == 3)
        {
            bool tempa = Union(rank_a, parent_alice, removed_edge.u, removed_edge.v);
            bool tempb = Union(rank_b, parent_bob, removed_edge.u, removed_edge.v);
            if (tempa == true)
                merged_a++;
            if (tempb == true)
                merged_b++;
            if (tempa == false && tempb == false)
                cnt_removed_edge++;
        }
        else if (removed_edge.type == 1)
        {
            bool tempa = Union(rank_a, parent_alice, removed_edge.u, removed_edge.v);
            if (tempa == true)
                merged_a++;
            else
                cnt_removed_edge++;
        }
        else
        {
            bool tempb = Union(rank_b, parent_bob, removed_edge.u, removed_edge.v);
            if (tempb == true)
                merged_b++;
            else
                cnt_removed_edge++;
        }
    }

    if (merged_a != n || merged_b != n)
        return -1;

    return cnt_removed_edge;
}
int main()
{
    cout << "\nHello world!" << endl;

    int n, e;
    cin >> n >> e;
    vector<Pair> edges;
    while (e--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        edges.pb(Pair(type, u, v));
    }

    cout << "\n==========================================\n";
    cout << maximum_edges_removed(edges, n);
    cout << "\n==========================================\n";
    return 0;
}

/*
4 6
3 1 2
1 1 3
1 2 4
2 3 4
1 1 2
3 2 3

*/