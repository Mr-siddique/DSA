#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dest, weight;
    // Edge(int s, int d, int w)
    // {
    //     src = s;
    //     weight = w;
    //     dest = d;
    // }
};
bool myComp(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
// parent{0,1,2,3,4}
int find(int v, int parent[])
{
    if (parent[v] != v)
        parent[v] = find(parent[v], parent);
    return parent[v];
}
void Union(int rank[],int parent[],int v1,int v2){
    int xroot = find(v1,parent); 
	int yroot = find(v2,parent); 

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (rank[xroot] < rank[yroot]) 
		parent[xroot] = yroot; 
	else if (rank[xroot] > rank[yroot]) 
		parent[yroot] = xroot; 

	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
		parent[yroot] = xroot; 
		rank[xroot]++; 
	} 
}
int kruskalsMST(Edge edges[], int parent[], int rank[], int v, int e)
{
    sort(edges, edges + e, myComp);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    int res = 0;
    for (int i = 0, s = 0; s < v - 1; i++)
    {
        Edge e = edges[i];
        int src = find(e.src, parent);
        int dest = find(e.dest,parent);
        if (src != dest)
        {
            res += e.weight;
            Union(rank,parent,src, dest);
            s++;
        }
    }
    return res;
}
main()
{
    int V = 5;
    int e = 7;
    struct Edge edges[7];
    //0->1
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 10;
    //
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 8;

    edges[2].src = 1;
    edges[2].dest = 2;
    edges[2].weight = 5;

    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 3;

    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;

    edges[5].src = 3;
    edges[5].dest = 4;
    edges[5].weight = 15;

    edges[6].src = 2;
    edges[6].dest = 4;
    edges[6].weight = 12;
    int parent[V];
    int rank[V];
    cout<<kruskalsMST(edges, parent, rank, 5, 7)<<endl;
    for (int i = 0; i < 7; i++)
    {
        cout << edges[i].src << " -> " << edges[i].dest << " -> " << edges[i].weight << endl;
    }
}