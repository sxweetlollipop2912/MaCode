#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define maxN 200001
#define X first
#define Y second

typedef long maxn;
typedef std::pair <maxn, maxn> e_t;

maxn n, m, par[maxN];
int f[maxN];
std::vector <maxn> ad[maxN];
std::vector <e_t> e;
std::map <e_t, int> map;


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);

        e.push_back(e_t(u, v));
    }
}


bool DFS(const maxn u, const int x) {
    if (f[u] != -1 && f[u] != x) return 0;
    if (f[u] == x) return 1;
    f[u] = x;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[u] == v) continue;
        map[e_t(u, v)] = f[u];
        map[e_t(v, u)] = 1 - f[u];
        if (!DFS(v, 1 - f[u])) return 0;
    }

    return 1;
}


void Process() {
    std::fill(f, f + n, -1);

    if (DFS(0, 0)) {
        std::cout << "YES\n";
        for(maxn i = 0; i < m; i++) std::cout << map[e_t(e[i].X, e[i].Y)];
    }
    else std::cout << "NO";
}


int main() {
    //freopen("B.inp", "r", stdin);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
