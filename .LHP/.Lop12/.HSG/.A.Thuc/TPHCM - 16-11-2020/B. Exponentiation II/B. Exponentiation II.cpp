#include <iostream>
#include <cstdio>
#include <algorithm>
 
typedef long long maxa;
 
const maxa MOD = 1e9 + 7;
 
maxa a, b, c, res;
 
 
void Prepare() {
    std::cin >> a >> b >> c;
}
 
 
maxa pow(const maxa a, maxa p, const maxa MOD) {
    maxa re = 1, x = a;
    for(; p != 0; p >>= 1) {
        if (p & 1) re = (re * x) % MOD;
        x = (x * x) % MOD;
    }
    return re;
}
 
 
void Process() {
    maxa x = pow(b, c, MOD - 1);
    res = pow(a, x, MOD);
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