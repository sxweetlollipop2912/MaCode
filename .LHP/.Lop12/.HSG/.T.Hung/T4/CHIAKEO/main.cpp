// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>

#define maxN 352
#define a(x) ((x) + 1)

typedef int maxn;
typedef long long maxa;

const maxa MOD = 1e9 + 7;

maxn n;
maxa C[maxN][maxN], f[maxN][maxN][2], res;


void Prepare() {
    std::cin >> n;
}


maxa DP(const maxn idx, const maxn cnt, const maxn happy) {
    if (idx == -1) return cnt == 0 && happy == 0;
    if (cnt < 0) return 0;
    maxa &re = f[idx][cnt][happy];
    if (re != -1) return re;
    re = 0;

    if (happy) re = (C[cnt][a(idx)] * ((DP(idx - 1, cnt - a(idx), 0) + DP(idx - 1, cnt - a(idx), 1)) % MOD)) % MOD;

    for(maxn i = 0; i <= cnt; i++) {
        if (i == a(idx)) continue;
        re = (re + ((C[cnt][i] * DP(idx - 1, cnt - i, happy)) % MOD)) % MOD;
    }
    return re;
}


void Process() {
    C[0][0] = 1;
    for(maxn in = 0; in <= n; in++) {
        C[in][0] = 1;
        for(maxn k = 1; k <= in; k++) C[in][k] = (C[in - 1][k - 1] + C[in - 1][k]) % MOD;
    }

    memset(f, -1, sizeof(f));
    res = DP(n - 1, n, 1);
    std::cout << res;
}


int main() {
    freopen("chiakeo.inp", "r", stdin);
    freopen("chiakeo.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
