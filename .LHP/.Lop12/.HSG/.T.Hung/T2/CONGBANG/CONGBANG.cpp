#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102

typedef int maxn;
typedef long maxa;

maxn n, idx[maxN];
maxa P, a[maxN], res[maxN];


bool cmp(const maxn &idx1, const maxn &idx2) {
    return a[idx1] < a[idx2] || (a[idx1] == a[idx2] && idx1 > idx2);
}


void Prepare() {
    std::cin >> P >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i], idx[i] = i;
    std::sort(idx, idx + n, cmp);
}


void Process() {
    for(maxn ii = 0; ii < n; ii++) {
        maxn i = idx[ii];
        res[i] = std::min(a[i], P / (n - ii));
        P -= res[i];
    }

    if (P == 0)
        for(maxn i = 0; i < n; i++) std::cout << res[i] << ' ';
    else std::cout << "IMPOSSIBLE";
    std::cout << '\n';
}


int main() {
    freopen("congbang.inp", "r", stdin);
    freopen("congbang.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}
