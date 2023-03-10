#include "iostream"
#include <vector>
#include <string>

int main() {
    int n, l;
    std::cin >> n >> l;
    for (int i = 0; i < n; i++) {
        std::string tmp;
        std::cin >> tmp;
        int zero_ = l - tmp.length();
        std::string x = std::string(zero_, '0');
        std::cout << x + tmp << std::endl;
    }
    return 0;
}