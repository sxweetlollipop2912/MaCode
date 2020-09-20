#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000001

typedef long maxn, maxa;

maxn n, T;
maxa L, a[maxN], res_min, res_max;


void Prepare() {
    std::cin >> L >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
    res_min = 0, res_max = 0;

    for(maxn i = 0; i < n; i++) {
        res_min = std::max(res_min, std::min(a[i], L - a[i]));
        res_max = std::max(res_max, std::max(a[i], L - a[i]));
    }

    std::cout << res_min << ' ' << res_max << '\n';
}


int main() {
    freopen("10714.inp","r",stdin);
    freopen("10714.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while (T--) {
        Prepare();
        Process();
    }
}
