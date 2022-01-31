#include <bits/stdc++.h>
using namespace std;
int *parent;
int *rank;
void initialize(int n)
{
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int x)
{
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}
void Union(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b)
        return;
    parent[b] = a;
}

//find by path compression
int findByPathCompression(int x)
{
    if (x == parent[x])
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}
//union by rank
void unionByRank(int x, int y)
{
    int x_parent, y_parent;
    x_parent = find(x);
    y_parent = find(y);
    if (x_parent == y_parent)
        return;
    if (rank[x_parent] < rank[y_parent])
        parent[x_parent] = y_parent;
    else if (rank[x_parent] > rank[y_parent])
        parent[y_parent] = x_parent;
    else
    {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
class Edges
{
    int cost;
    char vertex1;
    char vertex2;
    Edges(char a, char b, int c)
    {
        vertex1 = a;
        vectex2 = b, cost = c;
    }
};
//kruskals mst naive approch
int kruskalsMST(vector<Edges> &edges, int vertices)
{
    sort(Edges.begin(), Edges.end());
    unrodered_set<char> s;
    int res = 0;
    for (int i = 0, v = 0; v < vertices - 1; i++)
    {
        if (s.find(edges[i].vertex1) != s.end() && s.find(edges[i].vertex2) != s.end())
            continue;
        else
        {
            res += edges[i].cost;

            if (s.find(edges[i].vertex1) == s.end())
            {
                v++;
                s.insert(edges[i].vertex1);
            }
            if (s.find(edges[i].vertex2) == s.end())
            {
                v++;
                s.insert(edges[i].vertex2);
            }
        }
    }
}
class Edge
{
    int cost, src, dest;
    Edge(int a, int b, int c)
    {
        cost = a;
        src = b;
        dest = c;
    }
};
bool comp(Edge a, Edge b) { return a.cost < b.cost; }
int find_mst(vector<Edge> edges, int vertices)
{
    initialize(vertices);
    int res = 0;
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0, s = 0; s < vertices - 1; i++)
    {
        int src = findByPathCompression(edges[i].src);
        int dest = findByPathCompression(edges[i].dest);
        if (src == dest)
            continue;
        else
        {
            unionByRank(src, dest);
            s++;
            res += edges[i].cost;
        }
    }
    return res;
}
main()
{
    int n = 5;
    initialize(n);
}