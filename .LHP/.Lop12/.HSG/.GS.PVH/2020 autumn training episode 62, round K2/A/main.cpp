#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000002
#define INF 99999999999999999

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN][4], res;


void Prepare() {
    std::cin >> n;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
    for(maxn i = 1; i <= n; i++) f[i][0] = f[i - 1][0] + a[i];
    for(maxn i = 1; i <= n; i++) f[i][1] = std::max(f[i - 1][0], f[i - 1][1]) - a[i];
    for(maxn i = 1; i <= n; i++) f[i][2] = std::max(f[i - 1][1], f[i - 1][2]) + a[i];
    for(maxn i = 1; i <= n; i++) f[i][3] = std::max(f[i - 1][2], f[i - 1][3]) - a[i];

    maxa sum = 0;
    res = -INF;
    for(maxn i = n; i >= 0; i--) {
        res = std::max(res, sum + f[i][3]);
        sum += a[i];
    }

    std::cout << res;
}


int main() {
    freopen("divseq.inp", "r", stdin);
    freopen("divseq.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
