//graph representation
// -adjecency matrix
// -adjecency list
#include <bits/stdc++.h>
using namespace std;
//adjecency list representation
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void addEdgeDirectedGraph(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void addEdgeWithWeight(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
}
void printEdges(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        for (auto it : adj[i])
            cout << it << " ";
        cout << endl;
    }
}
void BFS1(vector<int> adj[], int v, int src)
{
    queue<int> q;
    q.push(src);
    unordered_set<int> visited;
    visited.insert(src);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (auto it : adj[temp])
        {
            if (visited.find(it) == visited.end())
            {
                q.push(it);
                visited.insert(it);
            }
        }
    }
}
void bfsHelper(vector<int> adj[], int v, int src, bool visited[])
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        // cout << temp << " ";
        for (auto it : adj[temp])
        {
            if (visited[it] == false)
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}
void bfsDistinct(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            bfsHelper(adj, v, i, visited);
    }
}
int conectedComponents(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            bfsHelper(adj, v, i, visited);
            count++;
        }
    }
    return count;
}
void shortestPath(vector<int> adj[], int v, int src)
{
    vector<int> res(v, INT_MAX);
    res[src] = 0;
    int visited[v] = {false};
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : adj[u])
        {
            if (visited[it] == false)
            {
                res[it] = res[u] + 1;
                visited[it] = true;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout << res[i] << " ";
    cout << endl;
}
bool dfsRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            if (dfsRec(adj, u, visited, s) == true)
                return true;
        }
        if (u != parent)
            return true;
    }
    return false;
}

bool graphLoopDetection(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (dfsRec(adj, i, visited, -1) == true)
                return true;
        }
    }
    return false;
}
bool detectCycle(vector<int> adj[], int s, bool visited[], bool recStk[])
{
    visited[s] = true;
    recStk[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false && detectCycle(adj, u, visited, recStk))
            return true;
        else if (recStk[u] == true)
            return true;
    }
    recStk[s] = false;
    return false;
}
bool isCycleInDirectedGraph(vector<int> adj[], int v)
{
    bool visited[v] = {false};
    bool recStk[v] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (detectCycle(adj, i, visited, recStk) == true)
                return true;
        }
    }
    return false;
}

// kahn's algo
void topoLogicalSort(vector<int> adj[], int v)
{
    int inDegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto u : adj[i])
            inDegree[u] += 1;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (auto u : adj[v])
        {
            inDegree[u]--;
            if (inDegree[u] == 0)
                q.push(u);
        }
    }
    cout << endl;
}
bool isCyclekahnsAlgo(vector<int> adj[], int v)
{
    int inDegree[v] = {0};
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        for (auto u : adj[i])
            inDegree[u] += 1;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        count++;
        for (auto u : adj[v])
        {
            inDegree[u]--;
            if (inDegree[u] == 0)
                q.push(u);
        }
    }
    return count != v;
}
//dfs topologcals Sortu
void dfsForTopologcalSort(vector<int> adj[], int v, int visited[], stack<int> &stk)
{
    visited[v] = true;
    for (auto u : adj[v])
    {
        if (visited[u] == false)
            dfsForTopologcalSort(adj, u, visited, stk);
    }
    stk.push(v);
}
void topologicalSorting(vector<int> adj[], int V)
{
    int visited[V] = {false};
    stack<int> stk;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            dfsForTopologcalSort(adj, i, visited, stk);
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}
void shortestPath(vector<pair<int, int>> adj[], int V, int src)
{
    int cost[V];
    for (int i = 0; i < V; i++)
        cost[i] = INT_MAX;
    cost[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            int p = u.first;
            int c = u.second;
            cost[p] = min(c + cost[v], cost[p]);
            q.push(p);
        }
    }
    for (int i = 0; i < 6; i++)
        cout << cost[i] << " ";
    cout << endl;
}

//shortestPat using topological Sort
void dfsForTopologcalSort(vector<pair<int, int>> adj[], int v, int visited[], stack<int> &stk)
{
    visited[v] = true;
    for (auto u : adj[v])
    {
        if (visited[u.first] == false)
            dfsForTopologcalSort(adj, u.first, visited, stk);
    }
    stk.push(v);
}
stack<int> topologicalSorting(vector<pair<int, int>> adj[], int V)
{
    int visited[V] = {false};
    stack<int> stk;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            dfsForTopologcalSort(adj, i, visited, stk);
    }
    return stk;
}
void find_shortestPath(vector<pair<int, int>> adj[], int V, int src)
{
    int cost[V];
    for (int i = 0; i < V; i++)
        cost[i] = INT_MAX;
    cost[src] = 0;
    stack<int> stk = topologicalSorting(adj, V);
    vector<int> topological_sort;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        for (auto v : adj[u])
        {
            if (cost[v.first] > cost[u] + v.second)
                cost[v.first] = cost[u] + v.second;
        }
    }
    for (int i = 0; i < V; i++)
        cout << cost[i] << " ";
    cout << endl;
}

//addEdge in adjecency matrix
void addEdge(vector<vector<int>> &adj, int u, int v, int weight)
{
    adj[u][v] = weight;
    adj[v][u] = weight;
}
// prims minimum spanning tree algorithm
int primsMST(vector<vector<int>> adj)
{
    int key[adj.size()], res = 0;
    fill(key, key + adj.size(), INT_MAX);
    key[0] = 0;
    bool mSet[adj.size()] = {false};
    for (int count = 0; count < adj.size(); count++)
    {
        int u = -1;
        for (int i = 0; i < adj.size(); i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        mSet[u] = true;
        res += key[u];
        for (int v = 0; v < adj.size(); v++)
        {
            if (!mSet[v] && adj[u][v] != 0)
                key[v] = min(key[v], adj[u][v]);
        }
    }
    return res;
}

//dijkastra algorithm
void dijkastra(vector<vector<int>> adj, int src)
{
    int n = adj.size();
    bool visited[n] = {false};
    int distance[n];
    for (int i = 0; i < n; i++)
        distance[i] = INT_MAX;
    distance[src] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false && (u == -1 || distance[i] < distance[u]))
                u = i;
        }
        visited[u] = true;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false && adj[u][i] != 0)
                distance[i] = min(distance[i], distance[u] + adj[u][i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << distance[i] << " ";
    cout << endl;
}
void dijksatraQueue(vector<vector<int>> adj, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = adj.size();
    bool visited[n] = {false};
    pq.push({0, 0});
    for (int i = 1; i < n; i++)
        pq.push({INT_MAX, i});
    int res = 0;
    while (!pq.empty())
    {
        pair<int, int> u = pq.top();
        pq.pop();
        visited[u.second] = true;
        for (int i = 0; i < n; i++)
        {
            // if(visited[i]==false&&)
        }
    }
}
void add_edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u][v] = 1;
}
void add_edge(vector<vector<int>> &adj, int u, int v, int w)
{
    adj[u][v] = w;
}
//kosaraju implementation
// step1
void KdfsTraversal(vector<vector<int>> adj, int u, bool visited[], stack<int> &stk)
{
    visited[u] = true;
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false && adj[u][i] != 0)
            KdfsTraversal(adj, i, visited, stk);
    }
    stk.push(u);
}
stack<int> KrajuDfs(vector<vector<int>> adj)
{
    stack<int> stk;
    int n = adj.size();
    bool visited[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            KdfsTraversal(adj, i, visited, stk);
    }
    return stk;
}
//step2
vector<vector<int>> getTranspose(vector<vector<int>> adj)
{
    vector<vector<int>> res;
    for (int i = 0; i < adj.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < adj.size(); j++)
            temp.push_back(adj[j][i]);
        res.push_back(temp);
    }
    return res;
}
void Kdfs(vector<vector<int>> adj, int u, bool visited[])
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false && adj[u][i] != 0)
            Kdfs(adj, i, visited);
    }
}
// visited{true,true,true,false,false,false}
void kosaRaju(vector<vector<int>> &adj)
{
    stack<int> stk = KrajuDfs(adj);
    vector<vector<int>> graph = getTranspose(adj);
    bool visited[adj.size()] = {false};
    while (!stk.empty())
    {
        int num = stk.top();
        stk.pop();
        if (visited[num] == false)
        {
            Kdfs(graph, num, visited);
            cout << endl;
        }
    }
}

//bellmanford shortest Path
void bellmanFord(vector<vector<int>> adj, int src)
{
    // int cost[adj.size()];
    // fill(cost, cost + adj.size(), INT_MAX);
    // cost[src] = 0;
    // for (int count = 0; count < adj.size() - 1; count++)
    // {
    //     for(int u=src;u<adj.size();u++){
    //         for(int v=0;v<adj.size();v++){
    //             if(adj[u][v]!=0)
    //             cost[v]=min(cost[v],cost[u]+adj[u][v]);
    //         }
    //     }
    // }
    // for (int i = 0; i < adj.size(); i++)
    //     cout << cost[i] << " ";
}
main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    printEdges(adj, v);
    BFS1(adj, v, 2);
    cout << endl;
    cout << conectedComponents(adj, v) << endl;
    shortestPath(adj, v, 0);
    cout << graphLoopDetection(adj, v) << endl;
    vector<int> directed[4];
    addEdgeDirectedGraph(directed, 0, 1);
    addEdgeDirectedGraph(directed, 1, 3);
    addEdgeDirectedGraph(directed, 2, 3);
    addEdgeDirectedGraph(directed, 2, 1);
    cout << isCycleInDirectedGraph(adj, v) << endl;
    vector<int> TS[5];
    addEdgeDirectedGraph(TS, 0, 2);
    addEdgeDirectedGraph(TS, 0, 3);
    addEdgeDirectedGraph(TS, 2, 3);
    addEdgeDirectedGraph(TS, 1, 3);
    addEdgeDirectedGraph(TS, 1, 4);
    topoLogicalSort(TS, 5);
    // topologicalSorting(TS,5);
    cout << endl;
    vector<pair<int, int>> weghtedGraph[6];
    addEdgeWithWeight(weghtedGraph, 0, 1, 2);
    addEdgeWithWeight(weghtedGraph, 1, 2, 3);
    addEdgeWithWeight(weghtedGraph, 2, 3, 6);
    addEdgeWithWeight(weghtedGraph, 0, 4, 1);
    addEdgeWithWeight(weghtedGraph, 4, 2, 2);
    addEdgeWithWeight(weghtedGraph, 4, 5, 4);
    addEdgeWithWeight(weghtedGraph, 5, 3, 1);
    shortestPath(weghtedGraph, 6, 0);
    find_shortestPath(weghtedGraph, 6, 0);
    vector<vector<int>> adjMat;
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
            temp[j] = 0;
        adjMat.push_back(temp);
    }
    addEdge(adjMat, 0, 1, 5);
    addEdge(adjMat, 0, 2, 8);
    addEdge(adjMat, 1, 2, 10);
    addEdge(adjMat, 2, 3, 20);
    addEdge(adjMat, 1, 3, 15);
    for (int i = 0; i < adjMat.size(); i++)
    {
        for (int j = 0; j < adjMat.size(); j++)
            cout << adjMat[i][j] << " ";
        cout << endl;
    }
    cout << primsMST(adjMat) << endl;
    dijkastra(adjMat, 0);
    dijksatraQueue(adjMat, 0);
    vector<vector<int>> raju;
    for (int i = 0; i < 6; i++)
    {
        vector<int> temp(6);
        for (int j = 0; j < 6; j++)
            temp[j] = 0;
        raju.push_back(temp);
    }
    add_edge(raju, 0, 1);
    add_edge(raju, 1, 2);
    add_edge(raju, 2, 3);
    add_edge(raju, 3, 0);
    add_edge(raju, 3, 4);
    add_edge(raju, 4, 5);
    add_edge(raju, 5, 4);
    cout<<"strongly connected component"<<endl;
    kosaRaju(raju);
    vector<vector<int>> bFord;
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 4; j++)
            temp.push_back(0);
        bFord.push_back(temp);
    }
    add_edge(bFord, 0, 1, 1);
    add_edge(bFord, 0, 2, 4);
    add_edge(bFord, 2, 3, 3);
    add_edge(bFord, 1, 2, -3);
    add_edge(bFord, 1, 3, 2);
    add_edge(bFord, 3, 0, 1);
    for (int i = 0; i < bFord.size(); i++)
    {
        for (int j = 0; j < bFord.size(); j++)
            cout << bFord[i][j] << " ";
        cout << endl;
    }
    bellmanFord(bFord, 2);
    string str="aamir";
    cout<<string(str.begin()+1,str.begin()+3);
}