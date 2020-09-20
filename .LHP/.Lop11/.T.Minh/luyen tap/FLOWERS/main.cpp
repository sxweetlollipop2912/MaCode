#include <iostream>
#include <cstdio>

#define maxN 201

typedef int maxn;

maxn n, res, res_u;
bool g[maxN][maxN];


void Prepare() {
    std::cin >> n;
    maxn u, v;
    while (std::cin >> u >> v) --u, --v, g[u][v] = true;
}


void Process() {
    for(maxn k = 0; k < n; k++) for(maxn u = 0; u < n; u++) for(maxn v = 0; v < n; v++)
        g[u][v] |= (g[u][k] & g[k][v]);

    res = n; res_u = 0;
    for(maxn u = 0; u < n; u++) {
        maxn cnt = 1;
        for(maxn v = 0; v < n; v++) cnt += (maxn)(u != v && g[u][v]);
        if (cnt < res) res = cnt, res_u = u;
    }

    std::cout << res << '\n' << res_u + 1 << ' ';
    for(maxn v = 0; v < n; v++) if (v != res_u && g[res_u][v]) std::cout << v + 1 << ' ';
}


int main() {
    freopen("FLOWERS.inp","r",stdin);
    //freopen("FLOWERS.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}