#include <iostream>

using namespace std;
long long Try(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        return n * Try(n - 1);
    }
}

int main()
{
    printf("Result: %lld\n", Try(20));
    return 0;
}