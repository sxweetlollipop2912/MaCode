#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 300001

typedef long maxn;

maxn n, K, res, k[maxN], par[maxN];
std::vector <maxn> ad[maxN];


void Init() {
    for(maxn i = 0; i < n; i++) ad[i].clear();
    std::fill(k, k + n, 0);
}


void Prepare() {
    for(maxn i = 0, x; i < K; i++) std::cin >> x, --x, k[x] = 1;

    for(maxn i = 0; i < n - 1; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


maxn DFS(const maxn u) {
    maxn cnt = 0, child = 0;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        ++child;
        par[v] = u;
        maxn dfs = DFS(v);
        if (dfs == -1) return -1;

        cnt += dfs;
    }

    if (!cnt) return k[u];
    if (k[u]) return -1;
    if (par[u] != u && k[par[u]]) {
        ++res;
        return 0;
    }
    if (child > 1 && cnt > 1) {
        ++res;
        return 0;
    }
    return cnt;
}


void Process() {
    std::fill(par, par + n, -1);
    par[0] = 0;
    res = 0;

    if (DFS(0) == -1) std::cout << "-1\n";
    else std::cout << res << '\n';
}


int main() {
    freopen("dienbien.inp", "r", stdin);
    freopen("dienbien.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int opt; std::cin >> opt;
    while (std::cin >> n >> K && n != -1) {
        Init();
        Prepare();
        Process();
    }
}
