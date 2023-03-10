#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[21];
int x[21];
int res = 0;
long long sum = 0;
int s[21];
void Try(int index)
{

    if (index > n)
    {
        if (sum == m)
            res++;
        return;
    }
    int limit = (m - sum - s[index + 1]) / a[index];

    for (int i = 1; i <= limit; i++)
    {
        x[index] = i;
        long long prev_sum = sum;
        sum += x[index] * a[index];
        Try(index + 1);
        // reset
        sum = prev_sum;
        x[index] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        s[i] = s[i + 1] + a[i];
    }
    Try(1);
    cout << res;
    return 0;
}