#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 5002
#define maxM 100002
#define maxA 99999999999999999

typedef int maxn;
typedef long long maxa;

maxn n, M;
maxa a[maxN], c[maxM], f[maxN];


void Prepare() {
    std::cin >> n >> M;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
    for(maxn i = 1; i <= M; i++) std::cin >> c[i];

    for(maxn i = M - 1; i >= 1; i--) c[i] = std::min(c[i], c[i + 1]);
    std::sort(a + 1, a + n + 1);
}


void Process() {
    std::fill(f, f + n + 1, maxA);
    f[0] = 0;
    for(maxn i = 1; i <= n; i++) for(maxn j = i; j >= 1; j--)
        f[i] = std::min(f[i], f[j - 1] + c[a[i] - a[j] + 1]);

    std::cout << f[n];
}


int main() {
    freopen("chemua.inp", "r", stdin);
    freopen("chemua.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
