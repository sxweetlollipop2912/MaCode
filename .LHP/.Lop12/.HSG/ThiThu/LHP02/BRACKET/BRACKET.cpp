#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <string>

#define maxN 202

typedef long maxn;
typedef long long maxa;

const maxa MOD = 1e9 + 7;

maxn n, m, cr[maxN], cl[maxN];
maxa f[maxN][maxN], res;


void Prepare() {
    std::cin >> n >> m;
    for(maxn i = 0, x, y; i < m; i++) std::cin >> x >> y, cr[x] = y, cl[y] = x;
}


maxa DP(const maxn l, const maxn r) {
    //std::cout << "dp " << l << ' ' << r << '\n';
    if (l > r) return 1;
    if (((r - l + 1) & 1) || cl[l] != 0 || cr[r] != 0 || (cr[l] != 0 && cr[l] > r) || (cl[r] != 0 && cl[r] < l)) return 0;
    if (f[l][r] != -1) return f[l][r];
    maxa &res = f[l][r]; res = DP(l + 1, r - 1);

    if (cr[l] == r) return res;

    maxn lim = cl[r] == 0? r - 1 : cl[r];
    for(maxn m = std::max(l + 1, cr[l]); m < lim; m += 2) {
        res = (res + ((bool)DP(l, m) * (DP(l + 1, m - 1) * DP(m + 1, r)) % MOD)) % MOD;
        //std::cout << "res " << l << ' ' << r << ' ' << m << ' ' << res << '\n';
    }
    //std::cout << l << ' ' << r << ' ' << f[l][r] << '\n';
    return res;
}


void Process() {
    memset(f, -1, sizeof(f));
    if (n <= 200) res = DP(1, n);
    else res = 0;
    std::cout << res;
}


int main() {
    freopen("bracket.inp", "r", stdin);
    //freopen("bracket.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
