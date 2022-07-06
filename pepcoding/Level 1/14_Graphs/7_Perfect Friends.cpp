// 1. You are given a number n (representing the number of students). Each student will have an id
//      from 0 to n - 1.
// 2. You are given a number k (representing the number of clubs)
// 3. In the next k lines, two numbers are given separated by a space. The numbers are ids of
//      students belonging to same club.
// 4. You have to find in how many ways can we select a pair of students such that both students are
//      from different clubs.

#include "../header.h"

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

void makeGraph(vector<Edge> grph[], int e)
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
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto edge : grph[i])
            cout << edge.src << " " << edge.nbr << " " << edge.wt << ", ";
        cout << endl;
    }
}

//*===========================================================================
//?===========================================================================

void getComponents(vector<Edge> grph[], int n, int node, bool *visited, vector<int> &comp)
{
    comp.push_back(node);
    visited[node] = true;
    for (auto edge : grph[node])
        if (visited[edge.nbr] == false)
            getComponents(grph, n, edge.nbr, visited, comp);
}

void getConnectComponent(vector<Edge> grph[], int n, vector<vector<int>> &components)
{
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        vector<int> comp;
        if (visited[i] == false)
            getComponents(grph, n, i, visited, comp);
        if (comp.size() != 0)
            components.push_back(comp);
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> grph[100];
    makeGraph(grph, e);
    cout << "\n*******\n";
    display(grph, n);
    cout << "\n*******\n";
    vector<vector<int>> components;
    getConnectComponent(grph, n - 1, components);

    int sum = 0;
    for (int i = 0; i < components.size(); i++)
        for (int j = i + 1; j < components.size(); j++)
            sum += components[i].size() * components[j].size();

    cout << sum;
}

int main()
{
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10


*/