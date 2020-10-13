#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

#define maxN 1002
#define INF (maxa)99999999999999999

typedef int maxn;
typedef double maxa;

maxn n;
maxa P, L, w[maxN], v[maxN], f[maxN];


void Prepare() {
    std::cin >> n >> P >> L;
    for(maxn i = 1; i <= n; i++) std::cin >> w[i] >> v[i];
}


void Process() {
    f[0] = 0;
    for(maxn i = 1; i <= n; i++) {
        maxa W = w[i], mn = v[i];
        f[i] = INF;
        for(maxn j = i - 1; j >= 0 && W <= P; W += w[j], mn = std::min(mn, v[j]), j--)
            f[i] = std::min(f[i], f[j] + (L / mn));
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << f[n];
}


int main() {
    freopen("cargroup.inp", "r", stdin);
    freopen("cargroup.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
