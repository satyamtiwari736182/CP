# Graph
    [1] DFS
    [2] BFS
    [3] Grid as Graph
    [4] 0-1 BFS [DeQueue]
    [*]DP on Graph
        [6] DAG shortest Path using topoSort [O(V+E)]
### Hamiltonian Path / Hamiltonian-cycle
```java
    int hamiltonianPath(int grid[][],int src,int desti,Set<Integer>visited,int obsticales){
        visited.add(src);
        if(src==desti){
            if(visited.size()==grid.length*grid[0].length-obsticales) return 1;
            return 0;
        }
        int row=src/grid[0].length,col=src%grid[0].length,cnt=0;
        grid[row][col]=-1;
        for(int i=0;i<dirs.length;i++){
            int rd=row+dirs[i][0],cd=col+dirs[i][1];
            if(rd<0 || rd>=grid.length ||cd<0 || cd>=grid[0].length || grid[rd][cd]==-1)continue;
            cnt+=hamiltonianPath(grid,rd*grid[0].length+cd,desti,visited,obsticales);
        }
        grid[row][col]=0;
        visited.remove(src);
        return cnt;
    }
```
### Eular Path / Eular-cycle
```cpp
    void eular(Map<Integer,List<Integer>>graph,int src,List<int[]>res){
        while(graph.get(src)!=null && graph.get(src).size()>0){
            List<Integer> neighbour=graph.get(src);
            int nbr=neighbour.get(neighbour.size()-1);
            graph.get(src).remove(neighbour.size()-1);
            eular(graph,nbr,res);
            res.add(new int[]{src,nbr});
        }
    }
```
### Cycle detection in directed and undirected Graph.
```cpp
//For undirected Graph
bool isCyclic(vector<Edge> grph[], int n, int src)
{
    queue<int> que;
    bool visited[100];
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


//For directed Graph
bool hasCycle(vector<vi> &adj, int node, vi &visited, vi &dfsvis)
{
    visited[node] = true;
    dfsvis[node] = true;

    for (auto child : adj[node])
    {
        if (visited[child] == false)
        {
            if (hasCycle(adj, child, visited, dfsvis))
                return true;
        }

        else if (dfsvis[child])
            return true;
    }

    dfsvis[node] = false;
    return false;
}
```
### Mother Vertex and Articulation Point
> **Mother Vertex**
```cpp
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

void dfs(vector<vi> &graph, int src, bool *vis, stack<int> &stk)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs(graph, nbr, vis, stk);
    stk.push(src);
}

int motherVertex(vector<vi> graph)
{
    int n=graph.size()-1;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));

    // s1: get topological ordered node
    stack<int> stk;
    for (int i = 0; i < n; i++)
        if (vis[i] == false)
            dfs1(graph, i, vis, stk);

    int mother_vtx = stk.top();
    stack<int> st;
    memset(vis, 0, sizeof(vis));

    dfs(graph, mother_vtx, vis, st);
    for (int i = 0; i < n; i++)
        if (vis[i] == false)
        {
            mother_vtx = -1;
            break;
        }
    return mother_vtx;
}

```
> **Articulation Point**
```cpp
// A vertex in an undirected graph is an articluation point iff removing it disconnects the graph. You have to find the number of articulation point in the given graph.

int tim = 0;
void dfs(vector<vi> &graph, bool *vis, int *parent, int *low, int *discov, bool *articu_pt, int u)
{
    discov[u] = low[u] = tim++;

    int count = 0;
    vis[u] = true;

    for (int v : graph[u])
    {
        if (vis[v])
            low[u] = min(low[u], discov[v]);

        if (vis[v] == false)
        {
            parent[v] = u;
            count++;
            dfs(graph, vis, parent, low, discov, articu_pt, v);

            low[u] = min(low[u], low[v]);

            //-------------------------------------
            if (parent[u] == -1 && count >= 2)
                articu_pt[u] = true;

            if (parent[u] != -1 && low[v] >= discov[u])
                articu_pt[u] = true;
            //-------------------------------------
        }
    }
}
    // memset(parent, -1, sizeof(parent)), memset(discovered, -1, sizeof(discovered)), memset(low, -1, sizeof(low));
```
### TopoSort Kahn's Algorithm [O(V+E)]
```cpp
// Academy offers total of n courses labelled from 0 to n-1. Some courses may have prerequisites. you have been given m pairs ai,bi. where 1 pair means you must take the course bi before the course ai.Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses. If it is impossible to finish all courses print -1.

int* TopoSort_kahn(vector<vi> &graph)
{
    int n = graph.size();
    int indegree[n], ans[n];
    memset(indegree, 0, sizeof(indegree));

    for (int i = 0; i < n; i++) for (int node : graph[i])
            indegree[node]++;

    queue<int> que;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            que.push(i);

    int idx = 0;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        ans[idx++] = temp;
        
        for (int node : graph[temp])
        {
            indegree[node]--;
            if (indegree[node] == 0)
                que.push(node);
        }
    }
    return ans;
}
```
##  Disjoint Set Union
        1. Kruskal Algorithm [ Minimum Spanning Tree ]
```cpp
// There are n vertices and there are edges in between some of the vertices. Find the sum  of edge weight of minimum spanning tree.

class Pair
{
public:
    int u, v, wt;
    Pair(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

int findParent(int *parent, int x)
{
    if (parent[x] == x) return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp; // path compression for optimisation.
    return temp;
}

bool unionByRank(int *parent, int *rank, int x, int y)
{
    int px = findParent(parent, x), py = findParent(parent, y);
    if (px != py)
    {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
            parent[px] = py, rank[py]++;

        return true;
    }
    return false;
}

int Kruskal_DSU(vector<Pair> &edges, int n)
{
    sort(all(edges), [&](auto first, auto second)
         { return first.wt < second.wt; });

    int *parent = new int[n + 1];
    int *rank = new int[n + 1];

    for (int i = 0; i <= n; i++)
        parent[i] = i, rank[i] = 1;

    int ans = 0;
    for (auto edge : edges)
        if (unionByRank(parent, rank, edge.u, edge.v))
            ans += edge.wt;

    return ans;
}
```

## Named Algorithm
### 1. Dijkstra Algorithm [Prio.Queue][single source sortest path] [O(v^3logV)]
```cpp
// Find the shortest path to each city (in terms of kms) from the source city along with the total distance on path from source to destinations.

#define pi pair<int, int>
#define vi vector<int>
typedef vector<pi> vp;

vi dijkstra(vector<vp> &adjList,int k){
    vi dist(adjList.size(), 1e9),visit(adjList.size());
    dist[k] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //min-heap on weight
    
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

```
### 2. Bellmanford Algorithm.
> **a. Is a *Single Source Sortest Path Algorithm* => Time complexity: O(VE) <br>
b. But when applied for every node it becomes *"All Pair Shortest Path Algorithm"*.<br>
c. It can also *detect ve- weight cycle*.**  
```cpp
// Find the shortest path from source vertex (vertex number 0) to all other vertices.
class Pair
{
public:
    int u, v, wt;
    Pair(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

int* solve(vector<Pair> edges,int n)
{
    int path[n],inf=1e9 + 7;
    fill(path, path + n, inf);
    path[0] = 0;
    for (int i = 0; i < n - 1; i++) for (Pair edge : edges)
            if (path[edge.u] + edge.wt < path[edge.v])
                path[edge.v] = path[edge.u] + edge.wt;
    return path;
}
```

### 3. Kosaraju 's Algorithm [ Strongly Connected Components ]
```cpp
void dfs1(vector<vi> &graph, int src, bool *vis, stack<int> &stk)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs1(graph, nbr, vis, stk);
    stk.push(src);
}

void dfs(vector<vi> &graph, int src, bool *vis)
{
    vis[src] = true;
    for (int nbr : graph[src])
        if (vis[nbr] == false)
            dfs(graph, nbr, vis);
}

int stronglyConnectedComponent(vector<vi> graph,int n)
{
    bool *vis = new bool[n + 1];
    memset(vis, 0, sizeof(vis));

    // step-1: getting topological order.
    stack<int> stk;
    for (int i = 0; i < n; i++)
        if (vis[i] == false)
            dfs1(graph, i, vis, stk); 

    // step-2: reverse the graph edges => transpose graph. 
    vector<vi> revGraph;
    revGraph.resize(n + 1);

    for (int i = 0; i < n; i++)
        for (int nbr : graph[i])
            revGraph[nbr].pb(i);

    // step-3: Count connected component in topological order on transpose graph using dfs
    int count = 0;
    memset(vis, 0, sizeof(vis));
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        if (vis[node] == false)
        {
            count++;
            dfs(revGraph, node, vis); 
        }
    }
    return count;
}

```
### 4. Prism Algorithm *[ Minimum Spanning Tree ]* [prio.queue]
```cpp
// Find the minimum length of wire required to connect all PCs over a network. Print the output in terms of which all PCs need to be connected, and the length of wire between them.
class Edge
{
public:
    int src, nbr, wt;
    Edge(int src, int nbr, int wt):src(src),nbr(nbr),wt(wt){}
};

bool comp(Pair p1, Pair p2)
{
    return p1.wt > p2.wt;
}

void prism(vector<Edge> grph[], int node, int *visited)
{
    priority_queue<Pair, vector<Pair>, function<bool(Pair, Pair)>> que(comp);
    que.push(Pair(-1, node, 0));
    while (!que.empty())
    {
        Pair temp = que.top();
        que.pop();
        if (visited[temp.node] == true)
            continue;
        if (temp.parent != -1)
            cout << "[" << temp.parent << "-" << temp.node << " @ " << temp.wt << "]" << endl;
        visited[temp.node] = true;
        for (auto edge : grph[temp.node])
            if (visited[edge.nbr] == false)
                que.push(Pair(temp.node, edge.nbr, edge.wt));
    }
}
```
### 5. Flody-Warshall Algorithm *[All Pair Shortest Path]*
```cpp
void flodyWarshall(vvi &graph)
{
    for (int k = 0; k < graph.size(); k++)
        for (int i = 0; i < graph.size(); i++)
            for (int j = 0; j < graph.size(); j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
```

    - Number of Edges(e) = vC2 -> O(v^2)
    e = O(v^2)
    v = O( log e )

 ## DP on Graph:
 > Is only applicable on Directed Acyclic Graph (DAG)

    - Besacuse in DP, we need to run base condition first, then the other DP values are calculated using it. So, order is important in DP.
>**Thus topological order is used**

>**Also Almost every DP problem can be represented as DAG**. where <br>
Each node would be a state<br>
And arrows are transition

