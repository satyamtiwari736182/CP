// You are given a tree with n nodes (numbered from 1 to n), node 1 is the root of tree.
// Each node has a value say Vi is the value of i'th node.

// You have to perform q queries of two types:-
// 1 i v : change the value of i'th node to v,
// 2 i   : add all nodes on path from root to i'th node.

#include "../header.h"

vector<vi> childs;
int timing = 1;
vi linearTree; // Linear tree
vi depth, startTime, endTime, values, parent;
vi ftree;

void getInputs(int n)
{
    values.resize(n + 1);
    depth.resize(n + 1);
    startTime.resize(n + 1);
    endTime.resize(n + 1);
    childs.resize(n + 1);
    linearTree.resize(2 * n + 5);
    ftree.resize(linearTree.size());
    parent.resize(n + 1);
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
    startTime[node] = timing;

    linearTree[timing++] = values[node];
    for (int chld : childs[node])
    {
        depth[chld] = 1 + depth[node];
        dfs(chld);
    }
    endTime[node] = timing;
    linearTree[timing++] = -values[node];
}
void addFT(int i, int val)
{
    while (i < ftree.size())
    {
        ftree[i] += val;
        i += i & -i;
    }
}
void buildFT()
{
    for (int i = 1; i <= timing; i++)
        addFT(i, linearTree[i]);
}
int queryFT(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += ftree[i];
        i -= i & -i;
    }
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
            int v, val;
            cin >> v >> val;
            addFT(startTime[v], val - values[v]);
            addFT(endTime[v], -val + values[v]);
            values[v] = val;
        }
        else
        {
            int v;
            cin >> v;
            int sum = queryFT(startTime[v]);
            cout << sum << "  **\n";
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    getInputs(n);

    // tree flattening
    dfs(1);

    buildFT();

    query();
}
//! --------------------------------------------------------------------------------------
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
// 1 4 3
// 1 3 8
// 2 7
// 1 4 6
// 1 1 7
// 2 3
// 2 4