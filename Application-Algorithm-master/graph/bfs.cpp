#include <bits/stdc++.h>
using namespace std;

/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9

*/
int n, m;
vector<int> adj[1001];
bool visited[1001];
queue<int> test;
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

void bfs(int u)
{
    test.push(u);
    visited[u] = true;
    while (!test.empty())
    {
        int v;
        v = test.front();
        cout << v << " ";
        test.pop();
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                test.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    input();
    bfs(1);
    return 0;
}