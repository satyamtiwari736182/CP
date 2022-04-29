#include "../header.h"

set<int> arr[100001];

//? parent holds node's parent which in turn represent a tree.
int parent[100001]; // parents of newly created decomposed tree. whose node are from 1.....n.
int subTreeSize[100001];

int dfs1(int node, int par)
// finding subtree-size of tree.
{
    subTreeSize[node] = 1;
    for (int adj : arr[node])
        if (adj != par)
            subTreeSize[node] += dfs1(adj, node);

    return subTreeSize[node];
}

int dfs(int node, int par, int tree_size)
// finding centroid of tree.
{
    for (int adj : arr[node])
        if (adj != par && subTreeSize[adj] > tree_size / 2)
            return dfs(adj, node, tree_size);

    return node;
}

void centroidDecompose(int node, int par)
{
    int sub_tree_size = dfs1(node, -1); // for first node parent=-1.
    int centroidNode = dfs(node, par, sub_tree_size);

    cout << "tree rooted at " << node << " with size " << sub_tree_size << " has centoid " << centroidNode << endl;

    parent[centroidNode] = par;

    for (int adj : arr[centroidNode])
        arr[adj].erase(centroidNode), centroidDecompose(adj, centroidNode);
}

void solve()
{
    int n, x, y;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
        cin >> x >> y, arr[x].insert(y), arr[y].insert(x);

    centroidDecompose(1, -1);

    cout << "\nParent array is as follows: \n";
    for (int i = 1; i <= n; i++)
        cout << "\t [" << i << "] = " << parent[i] << endl;
}

int main()
{
    cout << "\nHello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
    {
        solve();
    }
    return 0;
}
/*

15
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15

*/