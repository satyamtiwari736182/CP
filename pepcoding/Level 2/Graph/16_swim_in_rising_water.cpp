#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

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

class Pair
{
public:
    int row, col, mxSum_sofar;
    Pair(int i, int j, int mssf) : row(i), col(j), mxSum_sofar(mssf) {}
};

int swim_in_water(vector<vi> &graph)
{
    int dirs[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool vis[graph.size()][graph[0].size()];
    memset(vis, 0, sizeof(vis));

    auto byweight = [&](Pair a, Pair b)
    { return b.mxSum_sofar < a.mxSum_sofar; };

    priority_queue<Pair, vector<Pair>, decltype(byweight)> pque(byweight);

    pque.push(Pair(0, 0, graph[0][0]));

    while (!pque.empty())
    {
        Pair temp = pque.top();
        pque.pop();

        if (temp.row == graph.size() - 1 && temp.col == graph[0].size() - 1)
            return temp.mxSum_sofar;

        if (vis[temp.row][temp.col] == true)
            continue;

        vis[temp.row][temp.col] = true;

        for (int i = 0; i < 4; i++)
        {
            int rowdash = temp.row + dirs[i][0];
            int coldash = temp.col + dirs[i][1];

            if (rowdash < 0 || coldash < 0 || rowdash >= graph.size() || coldash >= graph[0].size() || vis[rowdash][coldash] == true)
                continue;
            pque.push(Pair(rowdash, coldash, max(temp.mxSum_sofar, graph[rowdash][coldash])));
        }
    }
    return 0;
}

int main()
{

    cout << "\nHello world!" << endl;
    int n, m;
    cin >> n >> m;
    vector<vi> graph;
    graph.resize(n);
    rvmatrix(graph, n, m);

    //---------------------------------------------
    //---------------------------------------------
    cout << "\n==========================================\n";
    cout << swim_in_water(graph);
    cout << "\n==========================================\n";
    return 0;
}

/*
5 5
0 1 2 25 7
22 26 27 28 8
23 17 18 20 26
24 3 9 12 15
32 31 30 33 19
*/
