// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 300001
#define maxP 31
#define next(p) (((p) + 1) % P)
typedef long maxn;
typedef int maxa;

maxn n, par[maxN], fin[maxN][maxP], fout[maxN][maxP];
maxa P;
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> P;

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v); ad[v].push_back(u);
    }

    std::fill(par, par + n, -1);
    par[0] = 0;
}


void DFS_IN(const maxn u) {
    fin[u][0] = 1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        par[v] = u;
        DFS_IN(v);
        for(maxa p = 0; p < P; p++) fin[u][next(p)] += fin[v][p];
    }
}


void DFS_OUT(const maxn u) {
    if (par[u] != u) {
        for(maxa p = 0; p < P; p++) fout[u][next(p)] += fout[par[u]][p];
        for(maxn p = 0; p < P; p++) fout[u][next(p)] += fin[par[u]][p];
        for(maxn p = 0; p < P; p++) fout[u][next(next(p))] -= fin[u][p];
    }

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[u] == v) continue;
        DFS_OUT(v);
    }
}


void Process() {
    DFS_IN(0);
    DFS_OUT(0);

    for(maxn i = 0; i < n; i++) std::cout << fin[i][0] + fout[i][0] << ' ';
}


int main() {
    freopen("dddd.inp", "r", stdin);
    freopen("dddd.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}