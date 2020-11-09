#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

#define maxN 300001
#define maxL 21
#define L 19
#define V first
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t;

maxn n, par[maxL][maxN], h[maxN];
maxa d[maxN];
std::vector <ad_t> ad[maxN];

void Prepare() {
    int opt;
    std::cin >> opt >> n;

    for(maxn i = 0; i < n - 1; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        --u, --v;
        ad[u].push_back(ad_t(v, c));
        ad[v].push_back(ad_t(u, c));
    }
}


void DFS(const maxn u) {
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V;
        maxa c = ad[u][i].cost;
        if (par[0][v] != -1) continue;
        par[0][v] = u, h[v] = h[u] + 1, d[v] = d[u] + c;
        DFS(v);
    }
}


maxn LCA(maxn x, maxn y) {
    if (h[x] < h[y]) std::swap(x, y);

    while (h[x] != h[y]) {
        int lg = log2(h[x] - h[y]);
        x = par[lg][x];
    }
    if (x == y) return x;

    for(int lg = L; lg >= 0; lg--) {
        if (par[lg][x] == -1 || par[lg][x] == par[lg][y]) continue;
        x = par[lg][x], y = par[lg][y];
    }

    return par[0][x];
}


void Process() {
    std::fill(par[0], par[0] + n, -1);
    par[0][0] = h[0] = 0;
    DFS(0);

    par[0][0] = -1;
    for(int l = 1; l <= L; l++) for(maxn i = 0; i < n; i++)
        par[l][i] = par[l - 1][par[l - 1][i]];

    maxn Q; std::cin >> Q;
    while (Q--) {
        maxn x, y; std::cin >> x >> y;
        --x, --y;
        maxn lca = LCA(x, y);
        std::cout << d[x] + d[y] - 2 * d[lca] << '\n';
    }
}


int main() {
    freopen("distance.inp", "r", stdin);
    freopen("distance.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
