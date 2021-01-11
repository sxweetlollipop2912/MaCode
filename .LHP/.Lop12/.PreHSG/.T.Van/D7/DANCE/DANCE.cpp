#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1000001

typedef long maxn, maxa;

maxn nf, nm, res;
maxa f[maxN], m[maxN];


void Prepare() {
    std::cin >> nm >> nf;
    for(maxn i = 0; i < nm; i++) std::cin >> m[i];
    for(maxn i = 0; i < nf; i++) std::cin >> f[i];

    std::sort(m, m + nm, std::greater<maxa>());
    std::sort(f, f + nf, std::greater<maxa>());
}


void Process() {
    for(maxn mi = 0, fi = 0; mi < nm, fi < nf; mi++, fi++) {
        while (fi < nf && m[mi] <= f[fi]) ++fi;
        res += fi < nf;
    }
    std::cout << res;
}


int main() {
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
