#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;

void makeSet(int *parent, int e)
{
    for (int i = 0; i < e; i++)
    {
        int node, par;
        cin >> node >> par;
        parent[node] = par;
    }
}

int findParent(int *parent, int val)
{
    while (val != parent[val])
        val = parent[val];
    return val;
}

void unionSet(int *parent, int a, int b)
{
    int par1 = findParent(parent, a);
    int par2 = findParent(parent, b);
    cout << par1 << "\t" << par2 << endl;
    if (par1 != par2)
        parent[par2] = par1;
}

void noSet(int *parent, int n)
{
    int visited[n] = {0};
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int node = i;
        if (visited[node] == false)
        {
            cnt++;
            while (1)
            {
                visited[node] = true;
                if (node != parent[node])
                    node = parent[node];
                else
                    break;
            }
        }
    }
    cout << "\nNo of sets provided: " << cnt << endl;
}

//-------------------------------------------------------
//#ways of forming group

int find2(int *parent, int a)
{
    while (parent[a] > 0)
        a = parent[a];
    return a;
}

void union2(int *parent, int a, int b)
{
    a = find2(parent, a);
    b = find2(parent, b);
    if (a != b)
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
}
void unionRank(int *parent, int a, int b);
void solve()
{
    int n, e;
    cin >> n >> e;
    int parent[n + 1];
    memset(parent, -1, sizeof(parent));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        union2(parent, a, b);
    }

    int ways = 1;
    REP(1, n)
    if (parent[i] < 0)
        ways *= -parent[i];
    cout << "\nNo. of ways: " << ways << endl;
    unionRank(parent, 1, 5);
    print(parent, 1, n);
}
//-------------------------------------------------------

//------------------------------------------------------------------------
// Optimisation while finding parents

// 1. Path Compression

int find3(int *parent, int a)
{
    vi temp;
    while (parent[a] > 0)
    {
        temp.pb(a);
        a = parent[a];
    }

    REP(0, temp.size() - 1)
    parent[temp[i]] = a;

    return a;
}

// 2.Union by Rank (i-e via Set Size)

void unionRank(int *parent, int a, int b)
{
    a = find2(parent, a);
    b = find2(parent, b);
    if (a != b)
    {
        if (abs(a) > abs(b))
        {
            parent[b] += parent[b];
            parent[a] = b;
        }
        else
        {
            parent[a] += parent[a];
            parent[b] = a;
        }
    }
}

int main()
{
    /*int n, e;
    cin >> n >> e;
    int sets[n + 1];

    memset(sets, -1, sizeof(sets));

    makeSet(sets, e);
    unionSet(sets, 1, 4);
    cout << endl;
    print(sets, 1, n);
    noSet(sets, n);
    cout << "\nhello!\n"
         << findParent(sets, 1) << "\t" << findParent(sets, 4) << endl;*/

    solve();
    return 0;
}

// 5 5
// 1 3
// 3 2
// 2 2
// 4 5
// 5 5
