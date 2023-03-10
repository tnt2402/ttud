#include <iostream>
#include <set>
#include <vector>

int main()
{
    int n;
    std::vector<int> result(n + 1);

    std::cin >> n;

    std::multiset<int> s;
    while (n--)
    {
        int value;
        std::cin >> value;
        s.insert(value);
    }

    std::string token;
    while (std::cin >> token)
    {
        if (token == "*")
        {
            // return 0;

            for (int i : result)
                if (i != 0) std::cout << i << "\n";
            return 0;
        }

        if (token == "insert")
        {
            int value;
            std::cin >> value;
            s.insert(value);
        }
        else
        {
            auto it = s.rbegin();
            // std::cout << (*it) << "\n";
            result.push_back(*it);
            s.erase(s.find(*it));
        }
    }
}