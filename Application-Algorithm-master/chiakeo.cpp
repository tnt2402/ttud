#include <iostream>

using namespace std;

int x[10];
int f = 0, m0, n, m;
void printArray(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void Try(int k)
{
    if (k == n)
    {
        x[k] = m - f;
        printArray(x, n);
    }
    m0 = m - f - (n - k);
    for (int v = 1; v <= m0; v++)
    {
        x[k] = v;
        f = f + v;
        if (k < n)
            Try(k + 1);
        f = f - v;
    }
}

int main()
{
    m = 5;
    n = 3;
    Try(1);
    return 0;
}