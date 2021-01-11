/// 0 -> a; 1 -> b
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxN 50001
#define maxA 1000000001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], b[maxN];


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) std::cin >> a[i];
    for(maxn i = 0; i < n; i++) std::cin >> b[i];

    std::sort(a, a + n);
    std::sort(b, b + n);
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("xoaso.inp","r",stdin);
    freopen("xoaso.out","w",stdout);

    Prepare();

    maxn ai = 0, bi = 0, res = 0;

    while (ai < n && bi < n) {
        while (bi < n && b[bi] <= a[ai]) bi++;
        if (bi < n && b[bi] > a[ai]) res++;
        ai++;
        bi++;
    }

    std::cout << res;
}
