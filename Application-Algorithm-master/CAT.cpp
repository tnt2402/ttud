#include <iostream>

using namespace std;

int A[100];
int n = 3;
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
    cout << endl;
}
void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        A[k] = i;
        if (k == n)
            print();
        else
            Try(k + 1);
    }
}

int main()
{
    Try(0);
    return 0;
}
