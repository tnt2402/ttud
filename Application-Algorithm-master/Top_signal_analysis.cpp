#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int count = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i - 1] && A[i] > A[i + 1])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}