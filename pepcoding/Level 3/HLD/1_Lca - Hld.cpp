// https://www.spoj.com/problems/LCA/

#include "../header.h"

vector<vi> childs;

vi subTreeSize, heavy, parent, depth;
vi linearTree, chainHead, pos;
int idx = 0;

void getInputs(int n)
{
    childs.resize(n + 1);
    subTreeSize.resize(n + 1);
    heavy.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);

    chainHead.resize(n + 1);
    pos.resize(n + 1);
    linearTree.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int cnt_child;
        cin >> cnt_child;
        for (int j = 0; j < cnt_child; j++)
        {
            int chld;
            cin >> chld;
            childs[i].pb(chld);
        }
    }
}

void dfs(int node)
{
    for (int chld : childs[node])
    {
        depth[chld] = 1 + depth[node];
        parent[chld] = node;
        dfs(chld);
        subTreeSize[node] += subTreeSize[chld];
        if (subTreeSize[chld] > subTreeSize[heavy[node]])
            heavy[node] = chld;
    }
    subTreeSize[node]++;
}

void dfsHLD(int node, int chain)
{
    chainHead[node] = chain;
    // linearTree[idx]=values[node];
    idx++;
    if (heavy[node] != 0)
        dfsHLD(heavy[node], chain);

    for (int chld : childs[node])
        if (chld != heavy[node])
            dfsHLD(chld, chld);
}

int lca(int a, int b)
{
    while (chainHead[a] != chainHead[b])
    {
        if (depth[chainHead[a]] > depth[chainHead[b]])
            a = parent[chainHead[a]];
        else if (depth[chainHead[a]] < depth[chainHead[b]])
            b = parent[chainHead[b]];
    }
    return depth[a] < depth[b] ? a : b;
}

void query()
{
    int q;
    cin >> q;
    test(q)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "  **" << endl;
    }
}

void solve()
{
    int n;
    cin >> n;

    // 1. Take all inputs.
    getInputs(n);

    // 2. precomputation of depth,heavy nodes,parents,sub-tree size,etc.,
    dfs(1);

    // 3.  HLD
    dfsHLD(1, 1);

    cout << "\n-------------\n";

    // 4.  ans. the Query
    query();
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
        solve();
    return 0;
}

// 1
// 7
// 3 2 3 4
// 0
// 3 5 6 7
// 0
// 0
// 0
// 0
// 2
// 5 7
// 2 7
