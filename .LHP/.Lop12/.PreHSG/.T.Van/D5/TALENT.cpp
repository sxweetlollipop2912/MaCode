#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 252
#define maxW 1002
#define maxR 250001
#define MIN_INT -9999999999999999

typedef int maxn;
typedef long long maxa;

maxn n;
maxa W, f[maxW], w[maxN], t[maxN];


void Prepare() {
    std::cin >> n >> W;
    for(maxn i = 0; i < n; i++) std::cin >> w[i] >> t[i], t[i] *= 1000;
}


maxa Cal(const maxa X) {
    std::fill(f, f + maxW, MIN_INT);
    f[0] = 0;

    for(maxn i = 1; i <= n; i++) {
        for(maxn m = W; m >= 0; m--) {
            if (f[m] == MIN_INT) continue;

            maxa cal = f[m] + t[i - 1] - X * w[i - 1];
            if (m + w[i - 1] > W)
                f[W] = std::max(f[W], cal);
            else
                f[m + w[i - 1]] = std::max(f[m + w[i - 1]], cal);
        }
    }

    return f[W];
}


void Process() {
    maxa l = 0, r = maxR;
    while (l != r) {
        maxa m = (l + r + 1) / 2;
        if (Cal(m) >= 0) l = m;
        else r = m - 1;
    }

    std::cout << l;
}


int main() {
    freopen("talent.inp", "r", stdin);
    freopen("talent.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
