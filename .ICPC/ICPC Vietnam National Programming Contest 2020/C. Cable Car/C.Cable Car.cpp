// WA
#include <iostream>
#include <algorithm>

typedef int maxn;

maxn n, k;


void Prepare() {
    std::cin >> n >> k;
}


bool Process() {
    if (k > n - 2) return 0;

    std::cout << "YES\n";
    for(maxn i = 1; i <= k; i++) std::cout << i << ' ' << i + 1 << '\n';
    for(maxn i = 1; i <= k; i++) std::cout << i << ' ' << i + 2 << '\n';
    return 1;
}


int main() {
    Prepare();
    if (!Process()) std::cout << "NO";
}