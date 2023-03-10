#include <bits/stdc++.h>

using namespace std;

int n, c;
int x[100001];
int t;
bool check(int min_dis)
{
    int last = x[1];
    int num_element = 1;
    for (int i = 2; i <= n; i++)
    {
        if (last + min_dis <= x[i])
        {
            last = x[i];
            num_element++;
        }
    }

    if (num_element >= c)
        return true;
    return false;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        sort(x + 1, x + n + 1);
        int res = 0;
        int l = 1;
        int r = x[n] - x[1];
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int D = mid;
            if (check(D) == true)
            {
                res = mid;
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
            l++;
        }
        cout << res << "\n";
    }
    return 0;
}