#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
void input()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        sort(adj[x].begin(), adj[x].end());
        adj[y].push_back(x);
        sort(adj[y].begin(), adj[y].end());
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{

    visited[u] = true;
    for (auto v : adj[u])
    {
        parent[v] = u;
        if (visited[v] == false)
        {
            dfs(v);
        }
    }
}

void path(int u, int v)
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(u);
    if (!visited[v])
    {
        cout << "Khong tim thay duong di";
    }
    else
    {
        vector<int> path;

        while (v != u)
        {
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(u);
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x << " ";
        }
    }
}

void connectedComponent()
{
    for (int i = 1; i <= m; i++)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    int u, v;
    input();
    cin >> u >> v;
    path(u, v);
    return 0;
}