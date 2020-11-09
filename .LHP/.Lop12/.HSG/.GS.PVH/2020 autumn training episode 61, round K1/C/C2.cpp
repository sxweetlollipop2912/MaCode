// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 300001
#define maxP 31
#define prev(x) ((((x) - 1) + P) % P)
#define next(x) (((x) + 1) % P)

typedef long maxn;

struct dp_t {
    maxn Count[maxP];

    dp_t() {
        std::fill(Count, Count + maxP, 0);
    }
};

maxn n, P, par[maxN];
std::vector <maxn> ad[maxN];
dp_t fin[maxN], fout[maxN];


void Prepare() {
    std::cin >> n >> P;

    for(maxn i = 0; i < n - 1; i++) {
        maxn x, y;
        std::cin >> x >> y;
        --x, --y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
}


void DFS_IN(const maxn u) {
    fin[u].Count[0] = 1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        par[v] = u;
        DFS_IN(v);
        for(maxn i = 0; i < P; i++) fin[u].Count[next(i)] += fin[v].Count[i];
    }
}


void DFS_OUT(const maxn u) {
    if (par[u] != u) {
        for(maxn i = 0; i < P; i++) fout[u].Count[next(i)] += fout[par[u]].Count[i];

        dp_t sum = fin[par[u]];
        for(maxn i = 0; i < P; i++) sum.Count[next(i)] -= fin[u].Count[i];
        for(maxn i = 0; i < P; i++) fout[u].Count[next(i)] += sum.Count[i];
    }

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;

        par[v] = u;
        DFS_OUT(v);
    }
}


void Process() {
    std::fill(par, par + n, -1);
    par[0] = 0;
    DFS_IN(0);
    
    std::fill(par, par + n, -1);
    par[0] = 0;
    DFS_OUT(0);

    for(maxn i = 0; i < n; i++) {
        std::cout << fin[i].Count[0] + fout[i].Count[0] << ' ';
    }
}


int main() {
    freopen("dddd.inp", "r", stdin);
    freopen("dddd.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}