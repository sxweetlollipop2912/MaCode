#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 9002

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN], h[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
    f[0] = h[0] = 0;

    for(maxn i = 1; i <= n; i++) {
        f[i] = f[i - 1], h[i] = a[i];

        for(maxn j = i - 1; h[i] <= h[j]; j--) {
            f[i] = (i - j) + f[j - 1];
            h[i] += a[j];
        }
    }

    std::cout << f[n];
}


int main() {
    freopen("towers.inp", "r", stdin);
    freopen("towers.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
