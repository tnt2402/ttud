#include <iostream>
#include <vector>

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> x(n);
    for (int &i : x)
        std::cin >> i;

    int result = 0;
    for (int i = 1; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i >> j & 1)
            {
                sum += x[j];
            }
        }
        result += a <= sum && sum <= b;
    }

    std::cout << result;
}