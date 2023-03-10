#include <iostream>
#include <vector>

int main() {
    int n; std::cin >> n;
    std::vector<int> a(n), dp(n);
    for (int &i : a) std::cin >> i; 
    dp[0] = a[0];
    dp[1] = std::max(a[0], a[1]);
    for (int i = 2; i < n; ++i) dp[i]  = std::max(dp[i - 2] + a[i], dp[i - 1]);
    std::cout << dp[n - 1];
}