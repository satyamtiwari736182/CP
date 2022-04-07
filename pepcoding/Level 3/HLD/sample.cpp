#include "../header.h"

vector<vi> childs;
vi subTreeSize, heavy, parent, depth;
vi linearTree, chainHead, pos, values;
vi ftree;
int idx = 1;

void getInputs(int n)
{
    childs.resize(n + 1);
    values.resize(n + 1);
    subTreeSize.resize(n + 1);
    heavy.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);

    chainHead.resize(n + 1);
    pos.resize(n + 1);
    linearTree.resize(n + 1);

    parent.resize(n + 1);

    ftree.resize(n + 1);
    // building input tree
    for (int i = 1; i <= n; i++)
        cin >> values[i];

    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        childs[p].pb(i);
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
    linearTree[idx] = values[node];
    pos[node] = idx;
    idx++;
    if (heavy[node] != 0)
        dfsHLD(heavy[node], chain);

    for (int chld : childs[node])
        if (chld != heavy[node])
            dfsHLD(chld, chld);
}

void addft(int i, int val)
{
    while (i < ftree.size())
    {
        ftree[i] += val;
        i += i & -i;
    }
}

int queryft(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += ftree[i];
        i -= i & -i;
    }
    return sum;
}

void buildft()
{
    for (int i = 1; i < ftree.size(); i++)
        addft(i, linearTree[i]);
}

int lca(int a, int b)
{
    int sum = 0;

    while (chainHead[a] != chainHead[b])
    {
        if (depth[chainHead[a]] < depth[chainHead[b]])
            swap(a, b);
        sum += queryft(pos[a]) - queryft(chainHead[pos[a]] - 1);
        a = parent[chainHead[a]];
    }

    if (depth[a] < depth[b])
        swap(a, b);

    sum += queryft(pos[a]) - queryft(pos[b] - 1);

    return sum;
}

void query()
{
    int q;
    cin >> q;
    test(q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, val, delta;
            cin >> v >> val;
            delta = -linearTree[pos[v]] + val;
            addft(pos[v], delta);
            linearTree[pos[v]] = val;
            values[v] = val;

            cout << "\n--------------------------------\n";
            for (int i = 0; i < childs.size(); i++)
            {
                cout << i << " -> ";
                for (int val : childs[i])
                    cout << val << " " << linearTree[pos[val]] << ",  ";
                cout << endl;
            }
        }

        else
        {
            int a, b;
            cin >> a >> b;
            cout << lca(a, b) << " **\n";
        }
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

    // 4. Build fenwick tree on linearize tree.
    buildft();

    cout << "\n-------------\n";

    // 5.  ans. the Query
    query();
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}

// 8
// 4 7 9 5 2 1 3 5
// 1 1 1 4 3 4 1
// 7
// 2 2 6
// 1 6 2
// 2 2 6
// 2 5 7
// 1 3 12
// 2 6 8
// 2 7 6