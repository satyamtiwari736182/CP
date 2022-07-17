
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
            mat[i].push_back(val);  \
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

void dfs(auto &graph, list<string> &ans, string src)
{
    auto &nbrs = graph[src];
    while (!nbrs.empty())
    {
        string nbr = nbrs.top();
        nbrs.pop();
        dfs(graph, ans, nbr);
    }
    ans.push_front(src);
}

list<string> findItinerary(vector<vector<string>> &tickets)
{
    map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    list<string> ans;

    for (auto ticket : tickets)
    {
        // priority_queue<string, vector<string>, greater<string>> temp;
        // temp.push(ticket[1]);
        // if (graph.find(ticket[0]) != graph.end())
        graph[ticket[0]].push(ticket[1]);
        // else
        //     graph[ticket[0]] = temp;
    }

    dfs(graph, ans, "jfk");
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    vector<vector<string>> tickets;
    int n;
    cin >> n;
    tickets.resize(n);

    for (int i = 0; i < n; i++)
    {
        string src, desti;
        cin >> src >> desti;
        tickets[i].pb(src);
        tickets[i].pb(desti);
    }

    // priority_queue<string, vector<string>, greater<string>> pque;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin >> str;
    //     pque.push(str);
    // }
    cout << "\n==========================================\n";
    auto lst = findItinerary(tickets);
    // cout << lst.size();
    for (auto i : lst)
        cout << i << " ";
    // while (!pque.empty())
    // {
    //     cout << pque.top() << " ";
    //     pque.pop();
    // }
    cout << "\n==========================================\n";
    return 0;
}

/*

5
jfk sfo
jfk atl
sfo atl
atl jfk
atl sfo

*/