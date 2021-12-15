// AC

#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 200002

typedef long maxn;

const maxn INF = 1e6;

maxn n, K, par[maxN], stp[maxN], res;
bool kr[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> K;

    std::fill(kr, kr + n, 0);

    for(maxn i = 0; i < K; i++) {
        maxn r; 
        std::cin >> r; --r;
        kr[r] = 1;
    }

    for(maxn i = 0; i < n; i++) ad[i].clear();

    for(maxn i = 1; i < n; i++) {
        maxn u, v;
        std::cin >> u >> v; --u, --v;

        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


void DFS_1(const maxn u) {
    stp[u] = kr[u] ? 0 : INF;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        par[v] = u;
        DFS_1(v);
        stp[u] = std::min(stp[u], stp[v] + 1);
    }
}


int DFS_2(const maxn u, const maxn step = 0) {
    if (stp[u] <= step) return 1;
    bool leaf = 1;
    maxn re = 0;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != u) continue;

        leaf = 0;
        re = std::max(-INF, re + DFS_2(v, step + 1));
    }

    if (leaf) re = -INF;
    return re;
}


void Process() {
    std::fill(par, par + n, -1);
    par[0] = 0;

    DFS_1(0);
    res = DFS_2(0);

    if (res < 0) std::cout << "-1\n";
    else std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}