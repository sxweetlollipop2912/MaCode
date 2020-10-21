#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002
#define Sum(l, r, m) (sum[r][m] - sum[l - 1][m])

typedef long maxn, maxa;

maxn n, sum[maxN][11], Q;
maxa a[maxN];


void Prepare() {
    std::cin >> n >> Q;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i], sum[i][a[i] % 10] = 1;

    for(int m = 0; m < 10; m++) for(maxn i = 1; i <= n; i++)
        sum[i][m] += sum[i - 1][m];
}


void Process() {
    while (Q--) {
        maxn l, r; std::cin >> l >> r;
        for(int m = 0; m < 10; m++)
            std::cout << Sum(l, r, m) << ' ';
        std::cout << '\n';
    }
}


int main() {
    freopen("chianhom.inp", "r", stdin);
    freopen("chianhom.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
