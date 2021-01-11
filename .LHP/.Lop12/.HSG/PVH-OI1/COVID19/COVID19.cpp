#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 500001

typedef long maxn;
typedef long long maxa;

const maxa MOD = 998244353;

maxn n, K, Q, f[maxN];
maxa hs[maxN];


void Prepare() {
    std::cin >> n >> K >> Q;

    std::fill(f, f + n, n);
    for(maxn i = 0, u; i < K; i++) std::cin >> u, --u, f[u] = 0;

    hs[0] = n + 1;
    for(maxn i = 1; i < n; i++) hs[i] = (hs[i - 1] * (n + 1)) % MOD;
}


void D(maxn u, maxn v) {
    if (f[u] < f[v]) std::swap(u, v);
    f[u] = std::min(f[u], f[v] + 1);
}


void P(const maxn l, const maxn r) {
    maxn mn = n;
    for(maxn i = l; i <= r; i++) mn = std::min(mn, f[i]);
    for(maxn i = l; i <= r; i++) f[i] = std::min(f[i], mn + 1);
}


maxa Res() {
    maxa res = 0;
    for(maxn i = 0; i < n; i++) res = (res + (((f[i] == n? (maxn)-1 : f[i]) * hs[i] + MOD) % MOD)) % MOD;//, std::cout << f[i] << ' ';
    //std::cout << '\n';
    return res;
}


void Process() {
    maxa res0 = Res();
    std::cout << res0 << '\n';
    while (Q--) {
        char opt; std::cin >> opt;
        if (opt == 'D') {
            maxn u, v; std::cin >> u >> v; --u, --v;
            if (K != 0) D(u, v);
        }
        else {
            maxn l, r; std::cin >> l >> r; --l, --r;
            if (K != 0) P(l, r);
        }
        if (K != 0) std::cout << Res() << '\n';
        else std::cout << res0 << '\n';
    }
}


int main() {
    freopen("covid19.inp", "r", stdin);
    freopen("covid19.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    Prepare();
    Process();
}
