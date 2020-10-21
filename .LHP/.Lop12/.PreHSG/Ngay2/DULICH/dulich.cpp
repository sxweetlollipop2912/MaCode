#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102
#define INF 9999999999999999
#define maxB 1025
#define BIT ((1 << P) - 1)
#define isOn(b, x) (((b) >> (x)) & 1)
#define Off(b, x) ((b) & (~(1 << (x))))

typedef int maxn, maxm, maxb;
typedef long long maxa;

maxn n, P;
maxm m;
maxa d[maxN][maxN], f[maxN][maxB], res;
bool done[maxN][maxB];


void Prepare() {
    std::cin >> n >> m >> P;

    for(maxn i = 0; i < n; i++) {
        std::fill(d[i], d[i] + n, INF);
        d[i][i] = 0;
    }
    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        --u; --v;
        d[u][v] = std::min(d[u][v], c);
    }
}


void Floyd() {
    for(maxn k = 0; k < n; k++) for(maxn u = 0; u < n; u++) for(maxn v = 0; v < n; v++)
        d[u][v] = std::min(d[u][v], d[u][k] + d[k][v]);
}


maxa DP(const maxn v, const maxb B) {
    if (done[v][B]) return f[v][B];
    done[v][B] = 1;

    maxb B1 = v < P && isOn(B, v)? Off(B, v) : B;
    for(maxn u = 0; u < n; u++) {
        if (u == v || d[u][v] >= INF) continue;
        f[v][B] = std::min(f[v][B], std::min(DP(u, B), DP(u, B1)) + d[u][v]);
    }

    //std::cout << v << ' ' << B << ' ' << B1 << ' ' << (B | (~(1 << (v)))) << ' ' << f[v][B] << '\n';
    return f[v][B];
}


void Process() {
    Floyd();

    for(maxn i = 0; i < n; i++) std::fill(f[i], f[i] + maxB, INF);
    f[n - 1][0] = 0;
    res = DP(n - 1, BIT);

    if (res >= INF) std::cout << "-1";
    else std::cout << res;
}


int main() {
    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
