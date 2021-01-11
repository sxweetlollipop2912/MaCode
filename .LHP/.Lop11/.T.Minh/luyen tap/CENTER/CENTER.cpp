#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 201
//#define maxM 10002
#define maxA 1000000002

typedef int maxn;
typedef long maxm, maxa;

maxn n;
maxm m;
maxa g[maxN][maxN], res_amp, res_cnt;


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < n; i++) std::fill(g[i], g[i] + n, maxA);

    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa d;
        std::cin >> u >> v >> d;
        --u, --v, d *= 10, g[u][v] = std::min(g[u][v], d);
    }
}


void Floyd() {
    for(maxn k = 0; k < n; k++) for(maxn u = 0; u < n; u++) for(maxn v = 0; v < n; v++)
        g[u][v] = std::min(g[u][v], g[u][k] + g[k][v]);
}


void Process() {
    Floyd();

    res_amp = maxA; res_cnt = 0;
    for(maxn u = 0; u < n; u++) {
        maxa amp = 0;
        for(maxn v = 0; v < n; v++)
            if (u != v) amp = std::max(amp, (g[u][v] + g[v][u]) / 2);

        if (amp == res_amp) ++res_cnt;
        else if (amp < res_amp) res_amp = amp, res_cnt = 1;
    }

    std::cout << res_cnt << '\n' << (res_amp / 10) << "." << (res_amp % 10);
}


int main() {
    freopen("center.inp","r",stdin);
    freopen("center.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}