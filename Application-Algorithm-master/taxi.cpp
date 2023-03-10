#include <bits/stdc++.h>

using namespace std;
int n;
int c[30][30];
int visited[30];
int x[30];
int fo = 1000000;
int f = 0;

void Try(int k)
{
    for (int v = 1; v <= n; ++v)
    {
        if (!visited[v] && !visited[v + n])
        {
            x[k] = v;
            x[k + 1] = v + n;
            visited[v] = 1;
            visited[v + n] = 1;
            f = f + c[x[k - 1]][v] + c[v][v + n];
            if (k == 2 * n - 1)
            {

                if (fo > f + c[v + n][0])
                {
                    fo = f = f + c[v + n][0];
                }
            }
            else
            {
                Try(k + 2);
            }
            f = f - c[x[k - 1]][v] - c[v][v + n];
            x[k] = 0;
            x[k + 1] = 0;
            visited[v] = 0;
            visited[v + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 2 * n + 1; ++i)
    {
        for (int j = 0; j < 2 * n + 1; ++j)
        {
            cin >> c[i][j];
        }
    }

    Try(1);

    cout << fo;

    return 0;
}