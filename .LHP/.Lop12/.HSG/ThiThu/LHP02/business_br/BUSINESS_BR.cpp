#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 300001

typedef long maxn;

maxn n, K, mn[maxN], tmp[maxN], res;
bool isK[maxN], done[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> K;

    for(maxn i = 0, u; i < K; i++) {
        std::cin >> u, --u;
        isK[u] = 1;
    }

    for(maxn i = 1, u, v; i < n; i++) {
        std::cin >> u >> v; --u; --v;
        ad[u].push_back(v); ad[v].push_back(u);
    }
}


void DFS_1(const maxn u) {
    tmp[u] = isK[u]? 0 : n;
    done[u] = 1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (done[v]) continue;
        DFS_1(v); tmp[u] = std::min(tmp[u], tmp[v] + 1);
    }
}


maxn DFS_2(const maxn u, const maxn d) {
    maxn re = std::min(mn[u], d);
    done[u] = 1;
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (done[v]) continue;
        re = std::max(re, DFS_2(v, d + 1));
    }
    return re;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) {
        std::fill(done, done + n, 0);
        DFS_1(i); mn[i] = tmp[i];
        res = std::max(res, mn[i]);
    }
    //std::cout << res << '\n';
    for(maxn i = 0; i < n; i++) {
        if (isK[i]) continue;
        std::fill(done, done + n, 0);
        res = std::min(res, DFS_2(i, 0));
    }
    std::cout << res;
}


int main() {
    freopen("business.inp", "r", stdin);
    freopen("business.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}

