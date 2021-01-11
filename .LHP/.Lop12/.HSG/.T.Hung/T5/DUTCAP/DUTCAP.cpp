// 9/?
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 100001

typedef long maxn;

maxn n, m, A, B, num[maxN], low[maxN], par[maxN], CNT, res;
std::vector <maxn> ad[maxN];
bool isA[maxN], isB[maxN];


void Prepare() {
    std::cin >> n >> m >> A >> B;
    for(maxn i = 0, u; i < A; i++) std::cin >> u, --u, isA[u] = 1;
    for(maxn i = 0, u; i < B; i++) std::cin >> u, --u, isB[u] = 1;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


void Tarjan(const maxn u, maxn &uA, maxn &uB) {
    num[u] = low[u] = ++CNT;
    uA = isA[u], uB = isB[u];

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[u] == v) continue;

        if (!num[v]) {
            par[v] = u; maxn vA, vB;
            Tarjan(v, vA, vB);
            low[u] = std::min(low[u], low[v]);
            uA += vA, uB += vB;

            if (low[v] > num[u] && (!vA || !vB || vA == A || vB == B)) ++res;
        }
        else low[u] = std::min(low[u], num[v]);
    }
}


void Process() {
    maxn A0, B0;
    res = CNT = par[0] = 0;
    Tarjan(0, A0, B0);
    std::cout << res;
}


int main() {
    freopen("dutcap.inp", "r", stdin);
    freopen("dutcap.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
