// You are given a tree of n nodes numbered from 0 to n-1 and is rooted at 0.
// You are given an array parent of length n where parent[i] denotes parent of i'th node (in case of root it's parent is itself).

// Now you have to answer q queries of format:
// a k
// answer to this query is k'th ancistor of node a if k'th ancistor does not exist simply print root.
// In simple words you have to find k'th ancistor of a node.

// Task: could u do it in log(n) or better time complexity.

#include "../header.h"

int maxRow = 0; // log2(n)
vi parent;
int table[N][N];

void getInputs(int n)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        cin >> parent[i];
}

void buildSparceTable()
{
    memset(table, 0, sizeof(table));
    int n = parent.size();
    maxRow = log2(n);
    for (int i = 0; i < n; i++)
        table[0][i] = parent[i];

    for (int i = 1; i <= maxRow; i++)
        for (int j = 0; j < n; j++)
            table[i][j] = table[i - 1][table[i - 1][j]];
}

int queryTable(int a, int k)
{
    for (int i = 0; i < maxRow; i++)
    {
        int mask = (1 << i);
        if ((mask & k) > 0)
            a = table[i][a];
    }
    return a;
}

void query()
// finding ans. by binary-lifting.
{
    int q;
    cin >> q;
    test(q)
    {
        int node, k;
        cin >> node >> k;
        int ans = queryTable(node, k);
        cout << ans << "  **\n";
    }
}

void solve()
{
    int n;
    cin >> n;
    getInputs(n);
    buildSparceTable();
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

/*
7
0 0 0 1 3 2 3
6
5 1
6 2
3 2
3 3
6 3
4 1
*/