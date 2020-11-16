#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002

typedef long maxn;
typedef long long maxa;

const maxn N = 100000;
const maxa MOD = 1e9 + 7;

maxn n, key;
maxa f[maxN];


void Prepare() {
    f[0] = 1;
    for(maxn i = 1; i <= N; i++) f[i] = (f[i - 1] * i) % MOD;
}


maxa Try(const maxn l, const maxn r, const maxn hi, const maxn lo) {
    if (l > r) return 0;

    maxn m = (l + r + 1) / 2;
    maxa re = f[hi + lo];

    if (hi) re = (re + (hi * Try(l, m - 1, hi - 1, lo) % MOD)) % MOD;
    if (lo) re = (re + (lo * Try(m + 1, r, hi, lo - 1) % MOD)) % MOD;

    return re;
}


void Process() {
    std::cout << Try(1, n, n - key, key - 1) << '\n';
}


int main() {
    freopen("demhv.inp", "r", stdin);
    freopen("demhv.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    while (std::cin >> n >> key) Process();
}