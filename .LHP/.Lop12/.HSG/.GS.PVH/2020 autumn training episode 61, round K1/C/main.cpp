#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 300001

typedef long maxn;

maxn n, d[maxN], P;
std::vector <maxn> ad[maxN];


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


maxn DFS(const maxn u) {
    maxn re = (d[u] % P == 0);

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (d[v] != -1) continue;
        d[v] = d[u] + 1;
        re += DFS(v);
    }

    return re;
}


void Process() {
    if (P == 1)
        for(maxn i = 0; i < n; i++) std::cout << n << '\n';

    else if (P == 2) {
        std::fill(d, d + n, -1);
        d[0] = 0;
        maxn cnt[2];
        cnt[0] = DFS(0), cnt[1] = n - cnt[0];

        for(maxn i = 0; i < n; i++) {
            std::cout << cnt[d[i] % 2] << ' ';
        }
    }

    else if (n <= 6000)
        for(maxn i = 0; i < n; i++) {
            std::fill(d, d + n, -1);
            d[i] = 0;
            std::cout << DFS(i) << ' ';
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
