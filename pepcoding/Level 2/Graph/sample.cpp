#include "../header.h"

int parent[N];
int Size[N];

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
        if (Size[px] > Size[py])
            parent[py] = px, Size[py] += Size[px];
        else if (Size[px] < Size[py])
            parent[px] = py, Size[px] += Size[py];
        else
            parent[px] = py, Size[px] += Size[py];

        return true;
    }
    return false;
}

int minimizeMalwareSpread(vvi &graph, vi &initials)
{
    int n = graph.size(); // No. of nodes

    for (int i = 0; i < n; i++)
        parent[i] = i, Size[i] = 1;

    set<int> infectedSet;
    for (int node : initials)
        infectedSet.insert(node);

    // grouping or making the components using DSU
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (graph[u][v] == true && infectedSet.count(u) == false && u != v)
            {
                int lu = findParent(u);
                int lv = findParent(v);
                if (lu != lv)
                    Union(u, v);
            }

    // counting maximum node will be infected by node
    //*********************************************************
    vi infected(n);
    unordered_map<int, set<int>> infectedNeighbour; // leader=>{nbr of infected node}
    for (int node : initials)
    {
        for (int nbr = 0; nbr < n; nbr++)
            if (graph[node][nbr] == true && node != nbr && infectedSet.count(nbr) == false)
            {
                int leader = findParent(nbr);
                if (infectedNeighbour[node].count(leader) == false)
                    infectedNeighbour[node].insert(leader),
                        infected[leader]++;
            }
    }

    // finding infected to be removed
    int toRemove = -1, maxSize = -1;
    for (int node : initials)
    {
        
        int cnt = 0;
        for (int nbr : infectedNeighbour[node])
            if (infected[nbr] == 1)
                cnt += Size[nbr];

        if (cnt >= maxSize)
        {
            if (cnt == maxSize)
                toRemove = min(toRemove, node);
            else
                toRemove = node;
            maxSize = cnt;
        }
    }
    //*********************************************************
    if (toRemove == -1)
    {
        int MIN = n + 1;
        for (int node : initials)
            MIN = min(MIN, node);
        return MIN;
    }

    return toRemove;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vvi graph(n, vi(n));
    rmatrix(graph, n, n);
    cin >> n;
    vi initials(n);
    rarr(initials, 0, n);
    cout << "\n==========================================\n";
    cout << minimizeMalwareSpread(graph, initials);
    cout << "\n==========================================\n";
    return 0;
}

/*

3
1 1 0
1 1 0
0 0 1
2
0 1

*/