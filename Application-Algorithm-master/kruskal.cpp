#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// data structure for storing edge information
struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

// data structure for storing a subset for union-find
struct Subset
{
    int parent, rank;
};

// function for finding set of an element i
// (uses path compression technique)
int find(Subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// function that does union of two sets of x and y
// (uses union by rank)
void union_set(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // attach smaller rank tree under root of high rank tree
    // (union by rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        // if ranks are same, then make one as root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// function for MST using Kruskal's algorithm
int kruskal_mst(int V, vector<Edge> &edges)
{
    int mst_wt = 0; // initialize result

    // sort edges in non-decreasing order on basis of weight
    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2)
         { return e1.w < e2.w; });

    // create V subsets with single elements
    Subset *subsets = new Subset[V];
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int set_u = find(subsets, u);
        int set_v = find(subsets, v);

        // check if the selected edge is creating a cycle or not
        if (set_u != set_v)
        {
            // current edge will be in the MST
            cout << u << " - " << v << endl;

            // update MST weight
            mst_wt += edge.w;

            // merge two subsets
            union_set(subsets, set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    vector<Edge> edges;

    // add edge 0-1
    edges.push_back(Edge(1, 2, 1));
    // add edge 0-2
    edges.push_back(Edge(1, 3, 4));
    // add edge 0-3
    edges.push_back(Edge(1, 5, 1));
    // add edge 1-3
    edges.push_back(Edge(2, 4, 2));
    // add edge 2-3
    edges.push_back(Edge(2, 5, 1));
    edges.push_back(Edge(3, 4, 3));
    edges.push_back(Edge(3, 5, 3));
    edges.push_back(Edge(4, 5, 2));

    cout << "Edges of MST are \n";
    int mst_wt = kruskal_mst(V, edges);

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
}