#include <bits/stdc++.h>
#define a first
#define b second
using namespace std;

int n;
typedef struct pair<int, int> ii;
ii A[100001];
// A.first <-> A.a
// A.second <-> A.b
int f[100001]; // 　f[i]: số lượng các phần tử lớn nhất so cho đoạn i là đoạn kết thúc
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i].a >> A[i].b;
    }
    sort(A + 1, A + n + 1, [](ii a, ii b)
         {
        if(a.second < b.second) return true;
        if(a.second == b.second)
        {
            if(a.first <= b.first) return true;
        }
        return false; });

    int cor_last = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (A[i].a > cor_last)
        {
            res++;
            cor_last = A[i].b;
        }
    }

    cout << res;
    return 0;
}
