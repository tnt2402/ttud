#include "iostream"
#include "vector"
#include <string>
#include <algorithm>

int main() {
    std::string str;
    long long n;
    std::cin >> str >> n;
    std::string::difference_type n1 = std::count(str.begin(), str.end(), 'a');

    long long so_du = n % str.length();
    long long thuong = n / str.length();
    std::string::difference_type n2 = std::count(str.begin(), str.begin() + so_du, 'a');

    std::cout << n1 * thuong + n2 << std::endl;

    return 0;
}