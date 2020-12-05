#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 1000001

typedef long maxn;

maxn n, K, a[maxN];
int T;


bool cmp(maxn x, maxn y) {
    maxn tx = 0, ty = 0; bool isX = x < y;
    for(; x != 0; x /= 10) tx += x % 10;
    for(; y != 0; y /= 10) ty += y % 10;
    return tx < ty || (tx == ty && isX);
}


void Prepare() {
    std::cin >> T >> n >> K;
    for(maxn i = 0; i < n; i++) a[i] = i + 1;
    std::sort(a, a + n, cmp);
}


void Process() {
    if (T == 1) std::cout << a[K - 1] << '\n';
    else
    for(maxn i = 0; i < n; i++) if (a[i] == K) {
        std::cout << i + 1 << '\n';
        return;
    }
}


int main() {
    freopen("bach.inp", "r", stdin);
    freopen("bach.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}
