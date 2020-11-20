// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

#define maxN 5001

typedef int maxn;
typedef long long maxa;

const maxa INF = 500000000000001;

maxn n, par[maxN], res;
maxa B, c[maxN], d[maxN], f[2][maxN][maxN], sz[maxN];
std::vector <maxn> child[maxN];


void Prepare() {
    std::cin >> n >> B;
    
    for(maxn i = 0; i < n; i++) {
        std::cin >> c[i] >> d[i];

        if (i != 0) {
            std::cin >> par[i];
            --par[i];
            child[par[i]].push_back(i);
        }
        else par[i] = i;
    }
}


void DP(const maxn u) {
    for(int i = 0; i <= 1; i++) std::fill(f[i][u], f[i][u] + n + 1, INF);
    sz[u] = 1; 
    f[0][u][0] = 0;
    f[0][u][1] = c[u], f[1][u][1] = c[u] - d[u];

    for(maxn i = 0; i < child[u].size(); i++) {
        maxn v = child[u][i];
        DP(v);

        for(maxn su = sz[u]; su >= 0; su--) for(maxn sv = sz[v]; sv >= 0; sv--) {
            f[0][u][su + sv] = std::min(f[0][u][su + sv], f[0][u][su] + f[0][v][sv]);
            f[1][u][su + sv] = std::min(f[1][u][su + sv], f[1][u][su] + std::min(f[0][v][sv], f[1][v][sv]));
        }
        sz[u] += sz[v];
    }
}


void Process() {
    DP(0);
    res = n;
    while(res > 0 && std::min(f[0][0][res], f[1][0][res]) > B) --res;
    std::cout << res;
}


int main() {
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}