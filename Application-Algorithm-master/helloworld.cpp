#include <iostream>

using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void BinaryString(int a[], int n, int i)
{
    if (n == i)
    {
        printArray(a, n);
        return;
    }
    a[i] = 0;
    BinaryString(a, n, i + 1);
    a[i] = 1;
    BinaryString(a, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    BinaryString(array, n, 0);
    return 0;
}