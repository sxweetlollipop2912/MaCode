#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 102
#define INF 9999999999999999

typedef int maxn, maxm;
typedef long long maxa;

maxn n, P;
maxm m;
maxa d[maxN][maxN], res;


void Prepare() {
    std::cin >> n >> m >> P;

    for(maxn i = 0; i < n; i++) {
        std::fill(d[i], d[i] + maxN, INF);
        d[i][i] = 0;
    }
    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        --u; --v;
        d[u][v] = std::min(d[u][v], c);
    }
}


void Floyd() {
    for(maxn k = 0; k < n; k++) for(maxn u = 0; u < n; u++) for(maxn v = 0; v < n; v++)
        d[u][v] = std::min(d[u][v], d[u][k] + d[k][v]);
}


void Process() {
    Floyd();

    std::vector <maxn> p;
    for(maxn i = 0; i < P; i++) p.push_back(i);

    res = INF;
    do {
        maxa re = d[n - 1][p[0]] + d[p[P - 1]][n - 1];
        for(maxn i = 1; i < P; i++) re += d[p[i - 1]][p[i]];
        res = std::min(res, re);
    } while (std::next_permutation(p.begin(), p.end()));

    if (res == INF) std::cout << "-1";
    else std::cout << res;
}


int main() {
    freopen("dulich.inp", "r", stdin);
    freopen("dulich.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
