# Graph
    [1] DFS  [O(V + E)].
    [2] BFS [O(V + E)]
    [3] Grid as Graph
    [4] 0-1 BFS [DeQueue]
    [*]DP on Graph
        [6] DAG shortest Path using topoSort [O(V+E)]
```md
# Hamiltonian Path: 
    In the Hamiltonian path problem, the task is to find a path in a graph that visits each vertex exactly once. If such a path exists, it is called a Hamiltonian path. A Hamiltonian cycle is a Hamiltonian path that starts and ends at the same vertex, forming a cycle that visits each vertex exactly once.

# Traveling Salesman Problem (TSP): 
    The Traveling Salesman Problem is a classic problem in combinatorial optimization. In the TSP, the goal is to find the shortest possible tour that visits each city exactly once and returns to the starting city. The TSP is a special case of the Hamiltonian cycle problem, where the edges have weights representing distances between cities, and the objective is to minimize the total distance traveled.

# Eular Path:
    A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle.
```
### Hamiltonian Path / Hamiltonian-cycle
```md
# LeetCode - 980
You are given an m x n integer array grid where grid[i][j] could be:
    1 representing the starting square. There is exactly one starting square.
    2 representing the ending square. There is exactly one ending square.
    0 representing empty squares we can walk over.
    -1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
```
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
### Travelling Salesman Problem (TSP)
```md
# LeetCode - 943
Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.


# Now Formulate the problem as a graph problem
Let's consider each string as a node on the graph, using their overlapping range as a similarity measure, then the edge from string A to string B is defined as:

# (A,B) = len(A) - overlapping(tail of A to head of B), 
    eg    A="catg" B= "atgcatc", overlapping is "atg",which is a tail part of A, and a head part of B, therefore (A,B) = 4-3 = 1
    Notice here that we must formulate the problem setup as a digraph, as (A,B)!=(B,A)
    eg B="atgcatc" A="catg", overlapping is "c", so (B,A) = 7-1=6
```
```java
int calDist(String a,String b){
    for(int i=0;i<a.length();i++) if(b.startsWith(a.substring(i))) return b.length()-(a.length()-i);
    return b.length();
}

int tsp(int grid[][],int src,int mask,Integer dp[][],Integer path[][]){
    if(mask==(1<<grid.length)-1)return 0;
    int res=Integer.MAX_VALUE,bestNode=-1;
    if(dp[mask][src]!=null) return dp[mask][src];
    for(int desti=0;desti<grid.length;desti++) if((mask & (1<<desti))==0){
        int temp=grid[src][desti] + tsp(grid,desti,mask | (1<<desti), dp,path);
        if(res>temp){
            res=temp;
            bestNode=desti;
        }
    }
    path[mask][src]=bestNode;
    return dp[mask][src]=res;
}

String getPathString(int grid[][],Integer path[][],String words[],int parent){
    StringBuilder res=new StringBuilder(words[parent]);
    Integer mask=(1<<parent),curr=path[mask][parent];
    while(curr!=null){
        String temp=words[curr].substring(words[curr].length()-grid[parent][curr]);
        res.append(temp);
        mask|=(1<<curr);
        parent=curr;
        curr=path[mask][curr];
    }
    return res.toString();
}

public String shortestSuperstring(String[] words) {
    int n=words.length,grid[][]=new int[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)grid[i][j]=calDist(words[i],words[j]);
    String res="";int resLen=Integer.MAX_VALUE;
    for(int i=0;i<n;i++){
        Integer dp[][]=new Integer[(1<<n)][n],path[][]=new Integer[(1<<n)][n];
        tsp(grid,i,(1<<i),dp,path);
        String temp=getPathString(grid,path,words,i);
        if(temp.length()<resLen){
            res=temp;
            resLen=temp.length();
        }
    }
    return res;
}
```

### Eular Path / Eular-cycle
#### Hierholzer’s Algorithm [O(V+E)]

```md
procedure FindEulerPath(V)

    1. iterate through all the edges outgoing from vertex V;
        remove this edge from the graph,
        and call FindEulerPath from the second end of this edge;
    2. add vertex V to the answer.

# LeetCode - 2097
You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti. Return any valid arrangement of pairs.
Note: The inputs will be generated such that there exists a valid arrangement of pairs.
```
```cpp
void eular(Map<Integer,List<Integer>>graph,int src,List<int[]>res){
    while(graph.get(src).size()>0){
        List<Integer> neighbour=graph.get(src);
        int nbr=neighbour.get(neighbour.size()-1);
        graph.get(src).remove(neighbour.size()-1);
        eular(graph,nbr,res);
        res.add(new int[]{src,nbr});
    }
}
public int[][] validArrangement(int[][] pairs) {
    Map<Integer,List<Integer>>graph=new HashMap<>();
    Map<Integer,Integer>indeg=new HashMap<>(),outdeg=new HashMap<>();
    for(int edge[]:pairs){
        graph.putIfAbsent(edge[0],new ArrayList<>());
        graph.putIfAbsent(edge[1],new ArrayList<>());
        graph.get(edge[0]).add(edge[1]);
        indeg.put(edge[1],indeg.getOrDefault(edge[1],0)+1);
        indeg.put(edge[0],indeg.getOrDefault(edge[0],0));

        outdeg.put(edge[0],outdeg.getOrDefault(edge[0],0)+1);
        outdeg.put(edge[1],outdeg.getOrDefault(edge[1],0));
    }
    int start=-1;
    for(int node:indeg.keySet()){
        if(start==-1)start=node;
        if(outdeg.get(node)-indeg.get(node)==1)start=node;
    }
    List<int[]>res=new ArrayList<>();
    eular(graph,start,res);
    Collections.reverse(res);
    return res.toArray(new int[res.size()][]);
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

bool hasCycle(vector<vi> &adj){
    vector<int> indeg(adj.size());
    for(int i=0;i<adj.size();i++)for(int j:adj[i])indeg[j]++;
    queue<int>que;
    for(int i=0;i<indeg.size();i++)if(indeg[i]==0)que.push(i);
    int visCount=0;
    while(!que.empty()){
        int temp=que.front();que.pop();
        visCount++;
        for(int nbr:adj[temp])if(--indeg[nbr]==0)que.push(nbr);
    }
    return visCount<adj.size();
}
```
### Bipartite Graph
> **Graph Coloring** technique is used to mark nodes into two different sets A and B

    A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
```Java
public boolean isBipartite(int[][] graph,int src,int color[]) {
    Deque<Integer> que=new LinkedList<>();
    que.addLast(src);
    color[src]=0; // only two colors 0 or 1. Not colored => -1;
    while(!que.isEmpty()){
        int temp=que.removeFirst();
        for(int nbr:graph[temp]){
            if(color[nbr]==-1){
                color[nbr]=color[temp]^1; //toggle the current color
                que.addLast(nbr);
            }
            else if(color[nbr]!=(color[temp]^1))return false;
        }
    }
    return true;
}
public boolean isBipartite(int[][] graph) {
    int color[]=new int[graph.length];
    Arrays.fill(color,-1);
    for(int i=0;i<graph.length;i++)if(color[i]==-1 && !isBipartite(graph,i,color))return false;
    return true;
}
```
### Bridge
```md
# Leetcode-1192
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.
```
>_**dfs_val =>**_ order in which the node has visited.<br>
_**dfs_low =>**_ smallest **dfs_val** value **reachable** from the node ( not through it's parent ).<br>
**dfs_low** need not to be ultimate smallest value but smaller then what it is now.

```java
int count=1;
public void criticalConnections(List<List<Integer>> graph,int src,int parent,int dfsval[],int dfslow[],boolean vis[],List<List<Integer>> res) {
    vis[src]=true;
    dfsval[src]=dfslow[src]=count++;
    for(int nbr:graph.get(src)){
        if(nbr==parent)continue;
        if(!vis[nbr]){
            criticalConnections(graph,nbr,src,dfsval,dfslow,vis,res);
            dfslow[src]=Math.min(dfslow[src],dfslow[nbr]);
            if(dfslow[nbr]>dfsval[src]) res.add(Arrays.asList(src,nbr));
        }
        else dfslow[src]=Math.min(dfslow[src],dfsval[nbr]);
    }
}
public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<List<Integer>> graph=new ArrayList<>(),res=new ArrayList<>();
    for(int i=0;i<n;i++)graph.add(new ArrayList<>());
    for(var e:connections){
        graph.get(e.get(0)).add(e.get(1));
        graph.get(e.get(1)).add(e.get(0));
    }
    int dfsval[]=new int[n],dfslow[]=new int[n];
    boolean vis[]=new boolean[n];
    criticalConnections(graph,0,-1,dfsval,dfslow,vis,res);
    return res;
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

int time=0;
public void dfs(List<Set<Integer>>graph,int src,int parent,int dfsval[],int dfslow[],boolean vis[],boolean articulationPoint[]) {
    dfsval[src]=dfslow[src]=time++;
    vis[src]=true;
    int childcnt=0;
    for(int nbr:graph.get(src)){
        if(nbr==parent)continue;
        if(!vis[nbr]){
            childcnt++;
            dfs(graph,nbr,src,dfsval,dfslow,vis,articulationPoint);
            dfslow[src]=Math.min(dfslow[src],dfslow[nbr]);
            if(parent!=-1 && dfslow[nbr]>=dfsval[src])res[src]=true;
        }
        else dfslow[src]=Math.min(dfslow[src],dfsval[nbr]);
    }
    if(parent==-1 && childcnt>1 )res[src]=true;
}
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
##  Kruskal Algorithm [ Minimum Spanning Tree ] [ O(ElogE) ]
```md
    1. Application of DSU 
    2. Sort all the edges by their weights and use union find to avoid cycle
    3. Time Complexity is O(ElogE)

# LeetCode - 1489
Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
```
```cpp
int parent[],rank[],n=0;
int findParent(int x){
    return parent[x]=parent[x]==x?x:findParent(parent[x]);
}
boolean union(int x,int y){
    int px=findParent(x),py=findParent(y);
    if(px==py) return false;
    if(rank[px]>rank[py])parent[px]=py;
    else if(rank[py]>rank[px])parent[py]=px;
    else{
        parent[py]=px;
        rank[px]++;
    }
    return true;
}

int kruskal(int[][] edges,int exclude,int include[]){
    parent =new int[n]; rank=new int[n];
    for(int i=0;i<n;i++){parent[i]=i;rank[i]=1;}
    // Arrays.sort(edges,(a,b)->a[2]-b[2]);
    int res=0;
    if(include.length>0){
        union(include[0],include[1]);
        res+=include[2];
    }
    for(int i=0;i<edges.length;i++) if(edges[i][3]!=exclude && union(edges[i][0],edges[i][1])) res+=edges[i][2];
    return res;
}

public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int nn, int[][] edges) {
    n=nn;
    int grid[][]=new int [edges.length][3];
    for(int i=0;i<edges.length;i++){
        grid[i]=new int[]{edges[i][0],edges[i][1],edges[i][2]};
        edges[i]=new int[]{edges[i][0],edges[i][1],edges[i][2],i};
    }
    
    Arrays.sort(edges,(a,b)->a[2]-b[2]);
    int mincost=kruskal(edges,-1,new int[]{});
    System.out.print(mincost);
    List<List<Integer>> res=new ArrayList<>();
    res.add(new ArrayList<>());res.add(new ArrayList<>());

    for(int i=0;i<grid.length;i++){
        if(mincost != kruskal(edges,i,new int[]{}))res.get(0).add(i);
        else if(mincost == kruskal(edges,-1,grid[i]))res.get(1).add(i);
    }
    return res;
}
```
## DSU
```md
# LeetCode - 924
You are given a network of n nodes represented as an n x n adjacency matrix graph, where the ith node is directly connected to the jth node if graph[i][j] == 1.

Some nodes initial are initially infected by malware. Whenever two nodes are directly connected, and at least one of those two nodes is infected by malware, both nodes will be infected by malware. This spread of malware will continue until no more nodes can be infected in this manner.

Suppose M(initial) is the final number of nodes infected with malware in the entire network after the spread of malware stops. We will remove exactly one node from initial.

Return the node that, if removed, would minimize M(initial). If multiple nodes could be removed to minimize M(initial), return such a node with the smallest index.
Note that if a node was removed from the initial list of infected nodes, it might still be infected later due to the malware spread.
```
```java
// We will create disjoint set and then we will try to find such a Disjoint set which has exactly one infected node and has maximum size.
// So that maximum node remains uninfected.

int parent[],rank[],size[],n=0;
int findParent(int x){
    if(parent[x]==x)return x;
    return parent[x]=findParent(parent[x]);
}
void unionByRank(int x, int y) { // for this problem unionByRank is not used rather unionBySize is used
    int px = findParent(x);
    int py = findParent(y);
    if (px == py) return;
    if (rank[py] > rank[px]) parent[px] = py;
    else if (rank[px] > rank[py])parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }
}

void unionBySize(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    if (px == py) return;
    if (size[py] > size[px]) { // here we maximize the size of set
        parent[px] = py;
        size[py] += size[px];
    }
    else {
        parent[py] = px;
        size[px] += size[py];
    }
}

public int minMalwareSpread(int[][] graph, int[] initial) {
    n=graph.length;
    parent=new int[n];rank=new int[n];size=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;  rank[i]=1;  size[i]=1;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i!=j && graph[i][j]==1)unionBySize(i,j);
    // Parent of infectedNode => no. of infectedNode, infectedNode, sizeOfset
    int infectedinfo[][]=new int[n][4];
    for(int i:initial){
        int pi=findParent(i);
        infectedinfo[pi][0]++;   infectedinfo[pi][1]=i;   infectedinfo[pi][2]=size[pi];
    }
    int res=Integer.MAX_VALUE,sz=-1;
    for(int i=0;i<n;i++){
        if(infectedinfo[i][0]==1 && infectedinfo[i][2]>sz){
            res=infectedinfo[i][1];
            sz=infectedinfo[i][2];
        }
        if(infectedinfo[i][0]==1 && infectedinfo[i][2]==sz)res=Math.min(res,infectedinfo[i][1]);
    }
    Arrays.sort(initial);
    if(res==Integer.MAX_VALUE)return initial[0];
    return res;
}
```

## Named Algorithm
### 1. Dijkstra Algorithm [Prio.Queue][single source sortest path] [O(ElogV)]
> **Dijkstra's** algorithm is a **Greedy** BFS Algorithm.

    1. Used only if weights are non-negative
    2. Similar to BFS but has below difference
    3. Used Priority Queue with Integer Array instead of Queue with Integer
    4. Used Distance array instead of boolean visited array.
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

        if(dist[u]<temp.first)continue;

        for(int i=0;i<adjList[u].size();i++){
            int v = adjList[u][i].first, weight = adjList[u][i].second;

            if(visit[v]==false && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight,q.push({dist[v], v});
        }
    }
    
    return dist;
}
```
####  Modified Dijkstra Algorithm.
```md
# Leetcode - 1514
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
```
```java
public double maxProbability(int n, int[][] edges, double[] succProb, int src, int desti) {
    List<List<double[]>>graph=new ArrayList<>();
    for(int i=0;i<n;i++)graph.add(new ArrayList<>());
    for(int i=0;i<edges.length;i++){
        graph.get(edges[i][0]).add(new double[]{edges[i][1],succProb[i]});
        graph.get(edges[i][1]).add(new double[]{edges[i][0],succProb[i]});
    }
    Queue<double[]>que=new PriorityQueue<>((a,b)->(int)((b[1]-a[1])*1000));
    que.add(new double[]{src,1}); //node, priority
    double totalPriority[]=new double[n];
    totalPriority[src]=1;
    boolean vis[]=new boolean[n];
    while(!que.isEmpty()){
        int temp=(int)que.peek()[0];double dtemp=que.poll()[1];
        
        if(dist[temp]<dtemp)continue;
        
        vis[temp]=true;
        for(double nbh[]:graph.get(temp)){
            int nbr=(int)nbh[0];double prio=nbh[1];
            if(!vis[nbr] && totalPriority[nbr] < (totalPriority[temp]*prio) ){
                totalPriority[nbr]=totalPriority[temp]*prio;
                que.add(new double[]{nbr,totalPriority[nbr]});
            }
        }
    }
    return totalPriority[desti];
}
```

### 2. Bellmanford Algorithm.[O(VE)]
> **a. It is an Dynamic Algorithm(DP-based).<br>
b. Is a *Single Source Sortest Path Algorithm* => Time complexity: O(VE) <br>
c. But when applied for every node it becomes *"All Pair Shortest Path Algorithm"*. provided there is no ve- wt. edge: [V*O(VE)]=> O(v^4)<br>
d. It can also *detect ve- weight cycle*.<br>
e. It is not preferred over Dijkstra as time complexity of bellman ford is O(VE).**  
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
###  <hr>

>**TopoSort** can Also be used to find **single source shorted path**.
```md
# Traverse graph in topo sort order. ie. Pick start vertex from top sort and explore its neighbours and keep maintaining shortest distance.
```
###  <hr>


### 3. Kosaraju 's Algorithm [ Strongly Connected Components ] [O(V+E)]
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
### 4. Tarzen's Alorithms [Strongly Connected Components] [O(V+E)]
```md
# This is used to find scc, articulation point, bridge in graph.
```
```java
int time=0,counter=1,ans=0;
void SCC(List<List<Integer>> graph,int src,int dfsval[],int dfslow[],Stack<Integer>stk,boolean vis[],boolean instk[]){
    dfsval[src]=dfslow[src]=time++;
    vis[src]=instk[src]=true;
    stk.push(src);
    for(int nbr:graph.get(src)){
        if(!vis[nbr]){
            SCC(graph,nbr,dfsval,dfslow,stk,vis,instk);
            if(instk[nbr]) dfslow[src]=Math.min(dfslow[src],dfslow[nbr]);
        }
        else if(instk[nbr]) dfslow[src]=Math.min(dfslow[src],dfsval[nbr]);
    }
    if(dfsval[src]==dfslow[src]){
        System.out.print("#"+counter+" -> ");
        counter++;
        while(true){
            int node=stk.pop();
            System.out.print(node+", ");
            res++;
            instk[node]=false;
            if(node==src)break;
        }
        System.out.println();
    }
    ans=Math.max(cnt,ans);
}
```
### 5. Prism Algorithm *[ Minimum Spanning Tree ]* [prio.queue] [O(ElogV)]
    1. Start with any vertex. Use Priority Queue to process the smallest edge.
    2. Use visited array or distance array.

    3. Difference between Prims and Dijkstra is “Don’t add current vertex distance to calculate neighbour distance”.
    
        Example : u, v
            Dijkstra - dis[v] = dis[u] + graph[u][v];
            Prims - dis[v] = graph[u][v]
    4. Time Complexity is O(ElogV)
```cpp
// Find the minimum length of wire required to connect all PCs over a network. Print the output in terms of which all PCs need to be connected, and the length of wire between them.

int prism(List<List<int[]>>graph){
    PriorityQueue<int[]>que=new PriorityQueue<>((a,b)->a[1]-b[1]);
    int res=0;
    que.offer(new int[]{0,0});//node,wt
    boolean vis[]=new boolean[graph.size()];
    while(!que.isEmpty()){
        int temp[]=que.poll();
        if(vis[temp[0]])continue;
        res+=temp[1];vis[temp[0]]=true;
        for(int nbr[]:graph.get(temp[0])) if(!vis[nbr[0]]) que.offer(new int[]{nbr[0],nbr[1]});
    }
    return res;
}

```
### 6. Flody-Warshall Algorithm *[All Pair Shortest Path]*  [O(V^3)]
>**It is an Dynamic Algorithm(DP-based).**

    a. It prefers adjacency matrix over adjacency list
    b. Time Complexity is O(V^3)

    c. Run this algo one more time if a negative cycle check is required. If the shortest distance of a vertex is reduced, then the graph has a negative cycle.

```md
# Leetcode-1334
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
```
```Java
public int findTheCity(int n, int[][] edges, int distanceThreshold) {
    long graph[][]=new long [n][n]; //tips: keep long type
    for(int i=0;i<n;i++){
        Arrays.fill(graph[i],Integer.MAX_VALUE); //it ensure that there is no path between two nodes
        graph[i][i]=0;
    }
    for(int e[]:edges){
        graph[e[0]][e[1]]=e[2];
        graph[e[1]][e[0]]=e[2];
    }

    for(int temp=0;temp<n;temp++)
        for(int src=0;src<n;src++) for(int desti=0;desti<n;desti++)
                graph[src][desti]=Math.min( graph[src][desti], graph[src][temp] + graph[temp][desti]);
    
    int res=0,count=Integer.MAX_VALUE;
    for(int src=0;src<n;src++) {
        int cnt=0;
        for(int desti=0;desti<n;desti++)if(graph[src][desti]<=distanceThreshold) cnt++;
        if(cnt<=count){
            res=src;
            count=cnt;
        }
    }
    return res;
}
```

    - Number of Edges(e) = vC2 -> O(v^2)
    e = O(v^2)
    v = O( log e )
## 7. Maximum flow - Ford-Fulkerson and Edmonds-Karp
>The **Edmonds-Karp algorithm** is an **implementation** of the **Ford-Fulkerson method** for computing a maximal flow in a flow network.

```cpp
#include "header.h"

int n;
vector<vi> capacity; // contains both  residual capacity and reverse residual capacity
vector<vi> graph;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        int src = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int nbr : graph[src])
        {
            if (parent[nbr] == -1 && capacity[src][nbr])
            {
                parent[nbr] = src;
                int new_flow = min(flow, capacity[src][nbr]);
                if (nbr == t)
                    return new_flow;
                q.push({nbr, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int src = t;
        while (src != s)
        {
            int prev = parent[src];

            capacity[prev][src] -= new_flow; // resudual flow capacity
            capacity[src][prev] += new_flow; // reverse resudual flow capacity

            src = prev;
        }
    }

    return flow;
}
void flowgraph(int e)
{
    int u, v, cap;
    while (e--)
    {
        vi vec;
        cin >> u >> v >> cap;

        graph[u].pb(v);
        graph[v].pb(u);

        capacity[u][v] = cap; // capacity matrix.
    }
}

int main()
{
    int e;
    cin >> n >> e;
    for(int i=1;i<=n+1;i++)
    {
        vi v;
        graph.pb(v);
        vi v2(n + 1);
        capacity.pb(v2);
    }
    flowgraph(e);

    cout << "\nhello! " << maxflow(1, n) << endl;

    return 0;

}

// 6 9
// 1 2 7
// 1 5 4
// 5 2 3
// 5 4 2
// 2 3 5
// 2 4 3
// 4 6 5
// 4 3 3
// 3 6 8
```


 ## DP on Graph [ Directed Acyclic Graph (DAG) ]
 > Is only applicable on Directed Acyclic Graph (DAG)

    - Besacuse in DP, we need to run base condition first, then the other DP values are calculated using it. So, order is important in DP as it ensures that the repeated subproblems get solved first.
>**Thus topological order is used**

>**Also Almost every DP problem can be represented as DAG**. where <br>
Each node would be a state<br>
And arrows are transition
```md
# LeetCode - 1494
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.

In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.

Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.
```
#### 1. Strenthening the understing of bitmasking 😁
```cpp
int count_setbit(int mask) {
    if (mask == 0) return 0;
    return 1 + count_setbit(mask & (mask - 1));
}
int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    // dependency[i]: dependency mask of course i, the set bits is dependent
    vector<int> dependency(n, 0);
    for (size_t i = 0; i < dependencies.size(); ++i) {
        int course = dependencies[i][1] - 1,prerequisite = dependencies[i][0] - 1; // converting into 0-indexed.
        dependency[course] |= 1 << prerequisite;
    }

    // prerequisites[i]: prerequisites mask of mask i, the set bits is prerequisites
    vector<int> prerequisites(1 << n, 0);
    // iterate all mask and generate prerequisites mask of each mask
    for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < n; ++j) 
            if (i & (1 << j))  prerequisites[i] |= dependency[j];

    // dp[i]: minimum number of semesters of mask i, the set bits are courses that have not been taken
    vector<int> dp(1 << n, n + 1);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        // iterate all submask of mask i, and this mask is the mask of last semester
        // see: https://cp-algorithms.com/algebra/all-submasks.html
        for (int j = i; j; j = (j - 1) & i) {
            if (count_setbit(j) > k) continue;

            int already_taken = i ^ ((1 << n) - 1);
            if ((already_taken & prerequisites[j]) == prerequisites[j]) 
                dp[i] = min(dp[i], dp[i ^ j] + 1); // dp[i^j] => sem. req. for remaining cources
            
        }
    }

    return dp[(1 << n) - 1];
}
```
#### 2. Backtracking + DP gives TLE
```java
Integer dp[];
int countSetBit(int n){
    int res=0;
    for(int i=n;i>0; i &= (i-1))res++;
    return res;
}
int minNumberOfSemesters(List<Integer>graph[],int n,int k,int mask,int indeg[]) {
    if(mask==0) return 0;
    if(dp[mask]!=null) return dp[mask];
    int res=Integer.MAX_VALUE;
    for(int i=mask;i>0;i = (i-1) & mask){
        if(countSetBit(i)>k)continue;
        int temp=0;
        for(int j=0;j<n;j++) if((i & (1<<j))!=0) for(int nbr:graph[j]){
            indeg[nbr]--;
            if(indeg[nbr]==0) temp |= (1<<nbr);  
        }
        res=Math.min(res,1+minNumberOfSemesters(graph,n,k,(mask^i)|temp,indeg));
        for(int j=0;j<n;j++) if((i & (1<<j))!=0)for(int nbr:graph[j])indeg[nbr]++;
    }

    return dp[mask]=res;
}
public int minNumberOfSemesters(int n, int[][] relations, int k) {
    dp=new Integer[(1<<n)];
    List<Integer>graph[]=new List[n];
    for(int i=0;i<n;i++)graph[i]=new ArrayList<>();
    int indeg[]=new int[n];
    for(int relation[]:relations) {
        graph[relation[0]-1].add(relation[1]-1);
        indeg[relation[1]-1]++;
    }
    int mask=0;
    for(int i=0;i<n;i++)if(indeg[i]==0)mask |=(1<<i);
    return minNumberOfSemesters(graph,n,k,mask,indeg);
}
```
#### 3. Optimised solution
```java
Integer dp[];
int countSetBit(int n){
    int res=0;
    for(int i=n;i>0; i &= (i-1))res++;
    return res;
}
int minNumberOfSemesters(List<Integer>graph[],int n,int k,int mask) {
    if(mask==(1<<n)-1) return 0;
    int res=Integer.MAX_VALUE,indeg[]=new int[n],temp=0;
    
    if(dp[mask]!=null) return dp[mask];
    for(int i=0;i<n;i++){
        if((mask & (1<<i))!=0) continue;
        for(int j:graph[i]) indeg[j]++;
    }
    for(int i=0;i<n;i++) if(indeg[i]==0 && (mask & (1<<i))==0) temp |= (1<<i);

    if(countSetBit(temp)>k)for(int i=temp;i>0;i = (i-1) & temp){
        if(countSetBit(i)!=k) continue;
        res=Math.min(res,1+minNumberOfSemesters(graph,n,k,mask|i));
    }
    else res=Math.min(res,1+minNumberOfSemesters(graph,n,k,mask|temp));

    return dp[mask]=res;
}
public int minNumberOfSemesters(int n, int[][] relations, int k) {
    dp=new Integer[(1<<n)];
    List<Integer>graph[]=new List[n];
    for(int i=0;i<n;i++)graph[i]=new ArrayList<>();
    for(int relation[]:relations) graph[relation[0]-1].add(relation[1]-1);
    
    return minNumberOfSemesters(graph,n,k,0);
}
```
---
```md
# LeetCode - 1857
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
```
```cpp
int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size(),ans=n>0,visCount=0;
    vector<int> adj[n];
    
    unordered_map<int,int> indegree;
    for(vector<int>&v : edges){
        adj[v[0]].push_back(v[1]);
        indegree[v[1]]++;
    }
    
    queue<int> q;
    vector<vector<int>> dp(n,vector<int> (26,0));
    for(int i=0;i<n;i++)if(indegree[i] == 0) q.push(i), dp[i][colors[i] - 'a'] = 1;
    
    while(!q.empty()){
        int node = q.front();q.pop();
        visCount++;
        for(int child : adj[node]){
            for(int i=0;i<26;i++){
                dp[child][i] = max(dp[child][i],dp[node][i] + (i == (colors[child] - 'a')));
                ans=max(ans,dp[child][i]);
            }
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);              
        }
    }
    
    return visCount<n?-1:ans;
}
```
---
```md
# LeetCode - 329
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

a cell in the matrix as a node,
a directed edge from node x to node y if x and y are adjacent and x's value < y's value
Then a graph is formed.

No cycles can exist in the graph, i.e. a DAG is formed.

The problem becomes to get the longest path in the DAG.
```

```java
public int longestIncreasingPath(int[][] matrix) {
    int res=0,m=matrix.length,n=matrix[0].length, dirs[]={0,1,0,-1,0},indegree[][]=new int[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) for (int k=0;k<4;k++) {
        int nx = i + dirs[k],ny = j + dirs[k+1];
        if (nx<0 || nx>=m || ny<0 || ny>=n) continue; 
        if (matrix[nx][ny] > matrix[i][j]) indegree[nx][ny]++;
    }
    Queue<int[]> queue = new LinkedList<>();
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)if (indegree[i][j] == 0) queue.add(new int[]{i, j});

    while (!queue.isEmpty()) {
        int size = queue.size();
        while(size-->0) {
            int cur[] = queue.poll(),x = cur[0],y = cur[1];
            for (int k=0;k<4;k++) {
                int nx = x + dirs[k],ny = y + dirs[k+1];
                if (nx<0 || nx>=m || ny<0 || ny>=n) continue; 
                if (matrix[x][y] < matrix[nx][ny] && --indegree[nx][ny] == 0) queue.offer(new int[]{nx, ny});
            }
        }
        res++;
    }
    return res;
}
```
### Purning serach-space
```md
# LeetCode - 787
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
```
> 1. Simple **BFS** gives TLE
```java
public int findCheapestPrice(List<List<int[]>>graph, int src, int desti, int k) {
    Deque<int[]>que=new LinkedList<>();
    que.addLast(new int[]{src,0});//node,cost so far
    int res=Integer.MAX_VALUE,stop=-1;
    while(!que.isEmpty()){
        int size=que.size();
        stop++;
        while(size-->0){
            int temp[]=que.removeFirst();
            for(int nbr[]:graph.get(temp[0]))if(stop<=k ) {
                que.addLast(new int[]{nbr[0],temp[1]+nbr[1]});
                if(nbr[0]==desti)res=Math.min(res,(temp[1]+nbr[1]));
            }                
        }
    }
    return res==Integer.MAX_VALUE?-1:res;
}
public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<List<int[]>>graph=new ArrayList<>();
    for(int i=0;i<n;i++)graph.add(new ArrayList<>());
    for(int e[]:flights)graph.get(e[0]).add(new int[]{e[1],e[2]});

    return findCheapestPrice(graph,src,dst,k);
}
```
> 2. Using **BFS** and **Puring** technique. This not _**DP**_
```java
public int findCheapestPrice(List<List<int[]>>graph, int src, int desti, int k) {
    Deque<int[]>que=new LinkedList<>();
    que.addLast(new int[]{src,0});//node,cost so far
    int dp[]=new int[graph.size()];
    Arrays.fill(dp,Integer.MAX_VALUE);
    int jump=-1;//res=Integer.MAX_VALUE
    while(!que.isEmpty()){
        int size=que.size();
        jump++;
        while(size-->0){
            int temp[]=que.removeFirst();
            for(int nbr[]:graph.get(temp[0]))if(jump<=k && (nbr[1]+temp[1])<dp[nbr[0]]) {
                que.addLast(new int[]{nbr[0],temp[1]+nbr[1]});
                dp[nbr[0]]=nbr[1]+temp[1];
                // if(nbr[0]==desti)res=Math.min(res,(temp[1]+nbr[1]));
            }                
        }
    }
    return dp[desti]==Integer.MAX_VALUE?-1:dp[desti];
}
public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<List<int[]>>graph=new ArrayList<>();
    for(int i=0;i<n;i++)graph.add(new ArrayList<>());
    for(int e[]:flights)graph.get(e[0]).add(new int[]{e[1],e[2]});

    return findCheapestPrice(graph,src,dst,k);
}
```
## Tries + Graph
```md
# LeetCode-212
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
```

```java
class Node{
    Node child[]=new Node[26];
    String str="";
}
void add(Node root,String word){
    for(char ch:word.toCharArray()) {
        if(root.child[ch-'a']==null)
            root.child[ch-'a']=new Node();
        root=root.child[ch-'a'];
    }
    root.str=word;
}

int dirs[]=new int[]{0,1,0,-1,0};
void search(char[][] board,Node root,int r,int c,boolean vis[][],List<String>res){
    int ch=board[r][c]-'a';
    root=root.child[ch];
    if(root==null)return;

    if(root.str.length()>0){
        res.add(root.str);
        root.str="";
    }

    vis[r][c]=true;
    for(int i=0;i<4;i++){
        int rd=r+dirs[i],cd=c+dirs[i+1];
        if(rd<0 || cd<0 || rd>=vis.length || cd>=vis[0].length || vis[rd][cd])continue;
        search(board,root,rd,cd,vis,res);
    }
    vis[r][c]=false;
}
public List<String> findWords(char[][] board, String[] words) {
    List<String>res=new ArrayList<>();
    Node root=new Node();
    for(String word:words)add(root,word);
    boolean vis[][]=new boolean[board.length][board[0].length];
    for(int i=0;i<board.length;i++)for(int j=0;j<board[0].length;j++) search(board,root,i,j,vis,res);
    return res;
}
```

### Important Questions

#### 1. State based question
```md
# LeetCode - 847
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
```
```java
public int shortestPathLength(int[][] graph) {
    int res=Integer.MAX_VALUE,allVisited=(1<<graph.length)-1;
    Deque<int[]>que=new LinkedList<>();
    Set<Integer> visitedState=new HashSet<>();
    for(int i=0;i<graph.length;i++){
        que.addFirst(new int[]{1<<i,i,0});//visited node set,src,path(dist);
        visitedState.add((1<<i)*16+i);
    }
    while(!que.isEmpty()){
        int temp[]=que.removeFirst();
        if(temp[0]==allVisited) return temp[2];
        for(int nbr:graph[temp[1]]){
            int state=(temp[0] | (1<<nbr))*16+nbr;
            if(!visitedState.contains(state)){
                que.addLast(new int[]{temp[0] | (1<<nbr),nbr,temp[2]+1});
                visitedState.add(state);
            }
        }
    }
    return -1;
}
```
