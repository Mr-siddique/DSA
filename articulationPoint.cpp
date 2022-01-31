#include <bits/stdc++.h>
#define NIL -1
using namespace std;
class articulationPoint
{
    int V;
    list<int> *adj;

public:
    articulationPoint(int capacity)
    {
        V = capacity;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void add_edge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (auto v : adj[i])
                cout << v << " ";
            cout << endl;
        }
    }
    void find_articulation_point(int u, bool visited[], int disc[], int low[], int parent[], bool ap[], int &time)
    {
        int children = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (visited[v] == false)
            {
                children++;
                parent[v] = u;
                find_articulation_point(v, visited, disc, low, parent, ap, time);
                low[u] = min(low[u], low[v]);
                if (parent[u] == NIL && children > 1)
                    ap[u] = true;
                if (parent[u] != NIL && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }
    void articulation_point()
    {
        bool visited[V], ap[V];
        int disc[V], low[V], parent[V];
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            parent[i] = NIL;
            visited[i] = ap[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                find_articulation_point(i, visited, disc, low, parent, ap, time);
        }
        for (int i = 0; i < V; i++)
            if (ap[i] == true)
                cout << i << " ";
        cout << endl;
    }
    void find_bridges(int u, bool visited[], int disc[], int low[], int parent[], int &time)
    {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = *i;
            if (visited[v] == false)
            {
                parent[v] = u;
                find_bridges(v, visited, disc, low, parent, time);
                low[u] = min(low[v], low[u]);
                if (low[v] > disc[u])
                cout << "edge : " << u << " -> " << v << " is a bridge" << endl;
            }
            else if (v != parent[u])
                low[u] = min(low[u], disc[v]);
        }
    }
    void bridges()
    {
        bool visited[V] = {false};
        int disc[V], low[V], parent[V];
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                find_bridges(i, visited, disc, low, parent, time);
        }
    }
    //tarjans algo to find strongly connected componenet;
    void strongly_connected_component(int u, int disc[], int low[], bool stackMember[], int &time, stack<int> &stk)
    {
        stackMember[u] = true;
        disc[u] = low[u] = ++time;
        stk.push(u);
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int v = *it;
            if (disc[v] == NIL)
            {
                strongly_connected_component(v, disc, low, stackMember, time, stk);
                low[u] = min(low[u], low[v]);
            }
            else if (stackMember[v] == true)
                low[u] = min(low[u], disc[v]);
        }
        // cout<<stk.size()<<endl;
        if (low[u] == disc[u])
        {
            while (stk.top() != u)
            {
                cout << stk.top() << " ";
                stackMember[stk.top()]=false;
                stk.pop();
            }
            cout << stk.top() << " " << endl;
            stackMember[stk.top()]=false;
            stk.pop();
        }
    }
    void strongConnection()
    {
        bool stackMember[V];
        int disc[V];
        int low[V];
        int time = 0;
        stack<int> stk;
        for (int i = 0; i < V; i++)
        {
            disc[i] = low[i] = NIL;
            stackMember[i] = false;
        }
        for (int i = 0; i < V; i++)
            if (disc[i] == NIL)
                strongly_connected_component(i, disc, low, stackMember, time, stk);
    }
};
main()
{
    articulationPoint g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.printGraph();
    g.articulation_point();
    g.bridges();
    articulationPoint Graph(5);
    Graph.add_edge(0, 2);
    Graph.add_edge(0,3);
    Graph.add_edge(1, 0);
    Graph.add_edge(2, 1);
    Graph.add_edge(3, 4);
    Graph.add_edge(3, 2);

    Graph.printGraph();
    Graph.strongConnection();
}