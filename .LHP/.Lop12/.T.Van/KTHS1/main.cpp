#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 101

typedef int maxn;
typedef long long maxt;

maxn n, m, d[maxN][maxN];
std::vector <maxn> V[maxN];


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        d[u][v] = d[v][u] = 1;
    }
}


void Process() {
    for(maxn k = 0; k < n; k++) for(maxn u = 0; u < n; u++) for(maxn v = 0; v < n; v++)
        if (d[u][k] && d[k][v] && u != v)
            d[u][v] = !d[u][v]? d[u][k] + d[k][v] : std::min(d[u][v], d[u][k] + d[k][v]);

    for(maxn u = 0; u < n; u++) {
            for(maxn v = 0; v < n; v++)
                if (d[u][v]) V[u].push_back(d[u][v]);
            V[u].push_back(0);
        std::sort(V[u].begin(), V[u].end());
    }

    maxn u;
    maxt t;
    while (std::cin >> u >> t && u) {
        --u;
        maxn res = n - (std::upper_bound(V[u].begin(), V[u].end(), t) - V[u].begin());
        std::cout << res << '\n';
    }
}


int main() {
    freopen("goitin.inp", "r", stdin);
    //freopen("goitin.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
