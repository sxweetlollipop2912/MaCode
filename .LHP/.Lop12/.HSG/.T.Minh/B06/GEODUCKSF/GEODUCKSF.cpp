#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <math.h>

#define maxV 102
#define maxN 1003

typedef int maxn;
typedef double maxa;

maxn n, m, na, nb, a[maxN], b[maxN], D, res_u, res_v;
maxn d[maxV][maxV], T;
bool isD[maxV];
maxa res_t;


void Prepare() {
    std::cin >> n >> m >> na >> nb >> D >> T;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; maxn c;
        std::cin >> u >> v >> c;
        d[u][v] = d[v][u] = c;
    }

    for(maxn i = 0; i < na; i++) std::cin >> a[i];
    a[na] = a[na - 1];
    for(maxn i = 0; i < nb; i++) std::cin >> b[i];
    b[nb] = b[nb - 1];

    for(maxn i = 0, u; i < D; i++) std::cin >> u, isD[u] = 1;
}


bool Crash(const maxn ta, const maxn tb, const maxn d, maxa &re) {
    if (tb > ta + d || ta > tb + d) return 0;
    re = (tb + ta + d) / (maxa)2;
    return 1;
}


bool Process() {
    if (na == 0 || nb == 0) return 0;

    res_t = -1;
    for(maxn t = 0, ta = 0, tb = 0, ia = 0, ib = 0, ua = a[ia], ub = b[ib]; (ia < na || ia < nb) && t <= T; t++) {
        maxn va = a[std::min(na, ia + 1)], vb = b[std::min(nb, ib + 1)];
        if (ta + d[ua][va] == t) ta += d[ua][va], ua = va, ++ia, va = a[std::min(na, ia + 1)];
        if (tb + d[ub][vb] == t) tb += d[ub][vb], ub = vb, ++ib, vb = b[std::min(nb, ib + 1)];

        //std::cout << t << ' ' << ta << ' ' << tb << ' ' << ua << ' ' << va << ' ' << ub << ' ' << vb << ' ' << d[ua][ub] << '\n';

        if (isD[ua] || isD[ub]) return 0;
        if (ua == ub) {
            res_t = t, res_u = res_v = ua; break;
        }
        if (ua == vb && ub == va && Crash(ta, tb, d[ua][ub], res_t)) {
            res_u = std::min(ua, ub), res_v = ua + ub - res_u; break;
        }
    }
    if (res_t == -1 || ceil(res_t) > T) return 0;

    std::cout << "YES\n";

    std::cout << std::fixed; std::cout << std::setprecision(1);
    std::cout << res_u << ' '; if (res_u != res_v) std::cout << res_v << ' '; std::cout << res_t;
    return 1;

}


int main() {
    freopen("geoducksf.inp", "r", stdin);
    freopen("geoducksf.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    if (!Process()) std::cout << "NO";
}
