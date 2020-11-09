#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxN 500001

typedef long maxn;

maxn m, n;
int d[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> m;
    for(maxn i = 0; i < n; i++) std::cin >> d[i];

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


maxn Process() {
    for(maxn u = 0, i; u < n; u++) {
        if (d[u] != 0) continue;
        for(i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i];
            if (d[v] != 1) break;
        }
        if (i == ad[u].size()) return u;
    }
    return 0;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process() + 1;
}
