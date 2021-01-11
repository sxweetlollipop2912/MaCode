#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002

typedef long maxn, maxa;

maxn n, Q;
maxa a[maxN];


void Prepare() {
    std::cin >> n >> Q;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
    while (Q--) {
        maxn l, r; std::cin >> l >> r;
        for(int m = 0; m < 10; m++) {
            maxn sum = 0;
            for(maxn i = l; i <= r; i++)
                if (a[i] % 10 == m) ++sum;
            std::cout << sum << ' ';
        }
        std::cout << '\n';
    }
}


int main() {
    freopen("chianhom.inp", "r", stdin);
    freopen("chianhom.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
