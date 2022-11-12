// 1. You are given a graph and a source vertex. The vertices represent cities and the edges represent
//     distance in kms.
// 2. You are required to find the shortest path to each city (in terms of kms) from the source city along
//     with the total distance on path from source to destinations.

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
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto edge : grph[i])
            cout << edge.src << " " << edge.nbr << " " << edge.wt << ", ";
        cout << endl;
    }
}

//*===========================================================================
//?===========================================================================

class Pair
{
public:
    int wsf, node;
    string psf;
    Pair(int node, int wsf, string psf) : node(node), wsf(wsf), psf(psf) {}
};

bool comp(Pair p1, Pair p2)
{
    return p1.wsf > p2.wsf;
}
void dijkstra(vector<Edge> grph[], int node, int *visited)
{
    priority_queue<Pair, vector<Pair>, function<bool(Pair, Pair)>> que(comp);
    que.push(Pair(node, 0, "0"));
    while (!que.empty())
    {
        Pair temp = que.top();
        que.pop();
        if (visited[temp.node] == true)
            continue;
        cout << temp.node << " via: " << temp.psf << " @ " << temp.wsf << "km\n";
        visited[temp.node] = true;
        for (auto edge : grph[temp.node])
            if (visited[edge.nbr] == false)
                que.push(Pair(edge.nbr, temp.wsf + edge.wt, temp.psf + " " + to_string(edge.nbr)));
    }
}
//*******************************
    vi dijkstra(vector<vp> &adjList,int k){
        vi dist(adjList.size(), 1e9),visit(adjList.size());
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
        
        q.push({0,k});
        while(!q.empty()){
            pi temp = q.top();
            q.pop();
            int u = temp.second;
            visit[u] = true;
            for(int i=0;i<adjList[u].size();i++){
                int v = adjList[u][i].first, weight = adjList[u][i].second;

                if(visit[v]==false && dist[v] > dist[u] + weight)
                    dist[v] = dist[u] + weight,q.push({dist[v], v});
            }
        }
        
        return dist;
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
    int src;
    cin >> src;
    int visited[100] = {0};

    dijkstra(grph, src, visited);
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
8
6
0 1 10
2 3 10
4 5 10
5 6 10
4 7 10
7 6 10


*/

// 7
// 9
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8
// 2 5 5
// 0