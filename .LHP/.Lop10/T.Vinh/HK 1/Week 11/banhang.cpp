#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 401
#define maxT 101
#define maxD 40001

typedef int maxn, maxt, maxd;

maxn n, x;
maxd d[maxN][maxN], r[maxN][maxN];


void Prepare() {
    freopen("banhang.inp","r",stdin);
    freopen("banhang.out","w",stdout);

    long m = 0;
    std::cin >> n >> m >> x;
    x--;

    for(maxn i = 0; i < n; i++) std::fill(d[i], d[i] + n, maxD);

    for(maxn i = 0; i < m; i++) {
        maxn u, v;
        std::cin >> u >> v;
        std::cin >> d[u - 1][v - 1];
    }
}


void Floyd() {
    maxd re = 0;
    d[x][x] = 0;

    for(maxn i = 0; i < n; i++)
        for(maxn j = 0; j < n; j++)
            for(maxn k = 0; k < n; k++) {

                if (d[i][j] == maxD || d[j][k] == maxD) continue;

                d[i][k] = std::min(d[i][k], d[i][j] + d[j][k]);

                if (d[k][i] != maxD) {
                    r[i][k] = r[k][i] = d[i][k] + d[k][i];
                    if (i == x) re = std::max(re, r[x][k]);
                }
            }

    std::cout << re << '\n';
}


void Optimize() {
    maxd re = maxD;
    maxn id;

    for(maxn i = 0; i < n; i++) {
        maxd m = *std::max_element(r[i], r[i] + n);
        if (m < re) {
            re = m;
            id = i;
        }
    }

    std::cout << (id + 1);
}


int main() {
    Prepare();
    Floyd();
    Optimize();
}
