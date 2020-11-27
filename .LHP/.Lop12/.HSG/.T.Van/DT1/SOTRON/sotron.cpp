#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

typedef long long maxa;

maxa x;
std::string res;


void Prepare() {
    std::cin >> x;
}


void Process() {
    --x;
    if (x == 0) res = "0";

    for(; x != 0; x >>= 1) {
        if (x & 1) res += "5";
        else res += "0";
    }

    for(maxa i = res.size() - 1; i >= 0; i--) std::cout << res[i];
}


int main() {
    freopen("sotron.inp", "r", stdin);
    freopen("sotron.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
