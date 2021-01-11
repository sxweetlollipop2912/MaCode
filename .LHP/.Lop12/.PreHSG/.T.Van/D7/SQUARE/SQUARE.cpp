#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 42

typedef int maxn;

maxn m, n, f[maxN][maxN];


void Prepare() {
    std::cin >> m >> n;
}


maxn DP(const maxn x, const maxn y) {
    if (f[x][y]) return f[x][y];
    if (x == y) return (f[x][y] = 1);

    f[x][y] = x * y;
    for(maxn i = 1; i <= x / 2; i++) f[x][y] = std::min(f[x][y], DP(i, y) + DP(x - i, y));
    for(maxn i = 1; i <= y / 2; i++) f[x][y] = std::min(f[x][y], DP(x, i) + DP(x, y - i));
    f[y][x] = f[x][y];

    return f[x][y];
}


void Process() {
    std::cout << DP(m, n);
}


int main() {
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
