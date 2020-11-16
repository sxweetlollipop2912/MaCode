// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 300001
#define FAIL (-999999)

typedef long maxn;

maxn n, K, par[maxN], res;
bool isK[maxN];
std::vector <maxn> ad[maxN];
int opt;


void Init() {
    std::fill(isK, isK + n, 0);
    for(maxn i = 0; i < n; i++) ad[i].clear();
}

void Prepare() {
    for(maxn i = 0, u; i < K; i++) std::cin >> u, --u, isK[u] = 1;

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    std::fill(par, par + n, -1);
}


maxn DFS(const maxn u) {
    maxn cnt = 0;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        par[v] = u;
        cnt += DFS(v);
        if (cnt < 0) return FAIL;
    }

    if (cnt == 0) return isK[u];
    if (isK[u]) return FAIL;
    if (isK[par[u]] || cnt > 1) ++res, cnt = 0;
    return cnt;
}


void Process() {
    par[0] = 0;
    res = 0;
    if (DFS(0) == FAIL) std::cout << "-1\n";
    else std::cout << res << '\n';
}


int main() {
    freopen("dienbien.inp", "r", stdin);
    freopen("dienbien.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> opt;
    while (std::cin >> n >> K && n != -1) {
        Init();
        Prepare();
        Process();
    }
}