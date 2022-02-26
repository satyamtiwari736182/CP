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

void makeGraph(vector<string> words, map<char, set<char>> &graph, map<char, int> &indegree)
{
    for (string word : words)
        for (char ch : word)
            indegree[ch] = 0;

    for (int i = 0; i < words.size() - 1; i++)
    {
        string curr = words[i];
        string next = words[i + 1];

        int len = min(curr.length(), next.length());

        for (int j = 0; j < len; j++)
        {
            char ch1 = curr[j];
            char ch2 = next[j];
            if (ch1 != ch2)
            {
                set<char> hashset;
                hashset.insert(ch2);
                if (graph.find(ch1) == graph.end())
                    graph[ch1] = hashset;
                else
                    graph[ch1].insert(ch2);
                indegree[ch2]++;

                break;
            }
        }
    }
}

void TopoSort_kahn(map<char, set<char>> &graph, map<char, int> &indegree)
{
    int n = graph.size();

    queue<char> que;

    for (auto indeg : indegree)
        if (indeg.second == 0)
            que.push(indeg.first);

    int idx = 0;
    char ans[n];

    while (!que.empty())
    {
        char temp = que.front();
        que.pop();

        ans[idx] = temp;
        idx++;

        for (auto node : graph[temp])
        {
            indegree[node]--;

            if (indegree[node] == 0)
                que.push(node);
        }
    }

        parr(ans, idx);

}

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.pb(word);
    }

    map<char, set<char>> graph;
    map<char, int> indegree;

    makeGraph(words, graph, indegree);
    cout << "\n==========================================\n";
    // parr(words, n);
    // cout << graph.size() << "\t" << indegree.size();
    for (auto node : indegree)
        cout << node.first << " -> " << node.second << endl;
    cout << "\n==========================================\n";
    for (auto node : graph)
    {
        cout << node.first << " -> ";
        for (char ch : node.second)
            cout << ch << " ";
        cout << endl;
    }

    cout << "\n==========================================\n";
    TopoSort_kahn(graph, indegree);
    cout << "\n==========================================\n";
    return 0;
}

// 5
// wrt wrfz er ett rftt