#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1001
#define X first
#define Y second

typedef long long maxn;
typedef long maxm;

maxn n, cnt[maxN], res;
maxm m;
bool d[maxN][maxN];


void Prepare() {
    std::cin >> n >> m;

    for (maxm i = 0; i < m; i++) {
        maxn x, y; std::cin >> x >> y;
        --x, --y;

        if (x == y || d[x][y] || d[y][x]) continue;
        d[x][y] = d[y][x] = 1;
        ++cnt[x], ++cnt[y];
    }
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) res += (cnt[i] * (n - cnt[i] - 1));

    res = (n * (n - 1) * (n - 2) / 6) - (res / 2);
    std::cout << res;
}


int main() {
    freopen("colotria.inp", "r", stdin);
    freopen("colotria.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
