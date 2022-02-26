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

class Edge
{
public:
    int src, nbr, wt;
    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

class Pair
{
public:
    int v;
    string psf;
    Pair(int v, string psf)
    {
        this->v = v;
        this->psf = psf;
    }
};

void makeGraph(vector<Edge> grph[], int n, int e)
{
    for (int i = 0; i < e; i++)
    {
        int sr, nb, wt;
        cin >> sr >> nb >> wt;
        grph[sr].pb(Edge(sr, nb, wt));
        grph[nb].pb(Edge(nb, sr, wt));
    }
}

void display(vector<Edge> grph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto edge : grph[i])
            cout << edge.src << " " << edge.nbr << " " << edge.wt << ", ";
        cout << endl;
    }
}

void getComponents(vector<Edge> grph[], int n, int node, bool *visited, vector<int> &comp)
{
    visited[node] = true;
    comp.push_back(node);
    for (auto edge : grph[node])
        if (visited[edge.nbr] == false)
            getComponents(grph, n, edge.nbr, visited, comp);
}

void getConnectComponent(vector<Edge> grph[], int n, vector<vector<int>> &components)
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        vector<int> comp;
        if (visited[i] == false)
            getComponents(grph, n, i, visited, comp);
        if (comp.size())
            components.push_back(comp);
    }
}

void hamiltonianPath(vector<Edge> grph[], int n, int src, set<int> &visited, string psf, int isrc)
{
    if (visited.size() == n - 1)
    {
        char ch = '.';
        for (auto node : grph[src])
            if (node.nbr == isrc)
                ch = '@';
        cout << psf << " " << ch << endl;
    }
    visited.insert(src);
    for (auto edge : grph[src])
        if (visited.count(edge.nbr) == 0)
            hamiltonianPath(grph, n, edge.nbr, visited, psf + " " + to_string(edge.nbr), isrc);
    visited.erase(src);
}

void BFS(vector<Edge> grph[], int n, int src)
{
    queue<Pair> que;
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    que.push(Pair(src, to_string(src)));
    visited[src] = true;
    while (que.empty() == false)
    {
        auto temp = que.front();
        cout << temp.v << " @ " << temp.psf << endl;
        for (auto edge : grph[temp.v])
            if (visited[edge.nbr] == false)
            {
                que.push(Pair(edge.nbr, temp.psf + " " + to_string(edge.nbr)));
                visited[edge.nbr] = true;
            }
        que.pop();
    }
}

bool isCyclic(vector<Edge> grph[], int n, int src)
{
    queue<int> que;
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    que.push(src);
    while (que.empty() == false)
    {
        auto temp = que.front();
        if (visited[temp] == true)
            return true;
        visited[temp] = true;
        for (auto edge : grph[temp])
            if (visited[edge.nbr] == false)
                que.push(edge.nbr);
        que.pop();
    }
    return false;
}

int main()
{
    cout << endl
         << "hello!" << endl;
    int n, e;
    cin >> n >> e;
    vector<Edge> grph[n];
    makeGraph(grph, n, e);
    cout << endl
         << "----------------" << endl;
    int src;
    set<int> visited;
    cin >> src;
    display(grph, n);
    cout << endl
         << "----------------" << endl;
    hamiltonianPath(grph, n, src, visited, to_string(src), src);

    cout << endl
         << "----------------" << endl;
    cout << isCyclic(grph, n, src) << endl;

    // vector<vector<int>> components;
    // getConnectComponent(grph, n, components);

    //---------------------------------------------------
    // for (int i = 0; i < components.size(); i++)
    // {
    //     for (int j = 0; j < components[i].size(); j++)
    //         cout << components[i][j] << ", ";
    //     cout << endl;
    // }
    //---------------------------------------------------
    // 4
    // 3
    // 0 1 10
    // 1 2 10
    // 0 3 10
    // 2

    //---------------------------------------------------

    // int sum = 0;
    // for (int i = 0; i < components.size(); i++)
    //     sum += components[i].size() * components[(i + 1) % components.size()].size();
    // cout << endl
    //      << sum;

    //---------------------------------------------------

    cout << endl
         << "hello!" << endl;
    return 0;
}
