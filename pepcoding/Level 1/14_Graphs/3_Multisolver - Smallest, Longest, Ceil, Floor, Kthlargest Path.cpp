// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are give a number named "criteria" and a number "k".
// 3. You are required to find and print the values of
// 3.1 Smallest path and it's weight separated by an "@"
// 3.2 Largest path and it's weight separated by an "@"
// 3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.5 Kth largest path and it's weight separated by an "@"

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
int static lwt = INT_MAX, hwt = INT_MIN, cwtpath = INT_MAX, fwtpath = INT_MIN;
static string lwtpath = "", hwtpath = "", cpath = "", fpath = "";

priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> static pq;

void multiSolver(vector<Edge> grph[], int src, int dest, bool *visited, string psf, int budget, int k, int wtsf)
{
    if (src == dest)
    {
        cout << psf << " @ " << wtsf << endl;

        if (wtsf < lwt)
        {
            lwt = wtsf;
            lwtpath = psf + " @ " + to_string(lwt);
        }

        if (wtsf > hwt)
        {
            hwt = wtsf;
            hwtpath = psf + " @ " + to_string(hwt);
        }

        if (wtsf > budget && wtsf < cwtpath)
        {
            cwtpath = wtsf;
            cpath = psf + " @ " + to_string(cwtpath);
        }

        if (wtsf < budget && wtsf > fwtpath)
        {
            fwtpath = wtsf;
            fpath = psf + " @ " + to_string(fwtpath);
        }

        if (pq.size() < k)
            pq.push({wtsf, psf});
        else
        {
            if (pq.top().first < wtsf)
            {
                pq.pop();
                pq.push({wtsf, psf});
            }
        }
        return;
    }

    visited[src] = true;

    for (auto edge : grph[src])
        if (visited[edge.nbr] == false)
            multiSolver(grph, edge.nbr, dest, visited, psf + " " + to_string(edge.nbr), budget, k, wtsf + edge.wt);

    visited[src] = false;
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
    bool visited[100];
    memset(visited, 0, sizeof(visited));
    int src, desti, criteria, k;
    cin >> src >> desti >> criteria >> k;
    multiSolver(grph, src, desti, visited, to_string(0), criteria, k, 0);
    cout << endl
         << "Least Cost path: " << lwtpath << endl
         << "Costly path: " << hwtpath << endl
         << "k largest path: " << pq.top().second << " @ " << pq.top().first << endl
         << "Ceil path: " << cpath << endl
         << "Floor path: " << fpath << endl;
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
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0
6
30
4
*/