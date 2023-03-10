#include <iostream>
#include <vector>

int main()
{
    int n, k, m;
    std::cin >> n >> k >> m;
    std::vector<int> a(n), prefix_sum(n + 1);

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
        if (i + 1 >= k)
        {
            result += prefix_sum[i] - prefix_sum[i - k] == m;
        }
    }

    std::cout << result;
}
