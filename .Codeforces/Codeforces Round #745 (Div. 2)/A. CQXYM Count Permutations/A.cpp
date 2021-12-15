#include <iostream>
#include <algorithm>

typedef long long maxa;

const maxa MOD = 1e9 + 7;

maxa n, res;


void Prepare() {
    std::cin >> n;
}


void Process() {
    res = 1;
    for(maxa i = 1; i < 2 * n; i++) {
        res = (res * i) % MOD;
    }
    res = (res * n) % MOD;
    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}