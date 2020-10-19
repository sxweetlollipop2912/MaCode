#include <iostream>
#include <algorithm>

typedef long long maxa;

maxa x1, y1, x2, y2, res;


int main() {
    int t; std::cin >> t;
    while (t--) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) res = std::abs(y2 - y1);
        else if (y1 == y2) res = std::abs(x2 - x1);
        else res = std::abs(x2 - x1) + std::abs(y2 - y1) + 2;
        std::cout << res << '\n';
    }
}