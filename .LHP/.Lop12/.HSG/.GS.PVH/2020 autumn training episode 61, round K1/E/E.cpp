// AC
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 5002
#define maxA 99999999999999999

typedef int maxn;
typedef long long maxa;

maxn n, p[maxN], sz[maxN], res;
maxa B, a[maxN], d[maxN], f[maxN][maxN][2];


void Prepare() {
    std::cin >> n >> B;

    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i] >> d[i];
        if (i) std::cin >> p[i], --p[i];
        else p[i] = 0;
    }
}


maxn Process() {
    for(maxn i = 0; i < n; i++) {
        for(maxn j = 0; j <= n; j++) f[i][j][0] = f[i][j][1] = maxA;
        sz[i] = 1;
        f[i][0][0] = 0;
        f[i][1][0] = a[i];
        f[i][1][1] = a[i] - d[i];
    }

    for(maxn v = n - 1; v > 0; v--) {
        maxn u = p[v];
        for(maxn su = sz[u]; su >= 0; su--) for(maxn sv = sz[v]; sv >= 0; sv--) {
            f[u][sv + su][0] = std::min(f[u][sv + su][0], f[u][su][0] + f[v][sv][0]);
            f[u][sv + su][1] = std::min(f[u][sv + su][1], std::min(f[v][sv][0], f[v][sv][1]) + f[u][su][1]);
        }
        sz[u] += sz[v];
    }

    for(maxn i = n; i > 0; i--) 
        if (std::min(f[0][i][0], f[0][i][1]) <= B) return i;
    return 0;
}


int main() {
    //freopen("shopping.inp", "r", stdin);
    //freopen("shopping.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process();
}
