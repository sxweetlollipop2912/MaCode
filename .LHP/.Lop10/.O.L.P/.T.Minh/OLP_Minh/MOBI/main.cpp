#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000002
#define maxY 10002
#define maxR 10000000002

typedef long maxn;
typedef long long maxy;

maxn n, k, lim;
maxy a[maxN], res;


void Prepare() {
    std::cin >> n >> k;

    for(maxn i = 0; i < n; i++) {
        maxn x;
        maxy y;
        std::cin >> x >> y;

        a[x - 1] += y;
        lim = std::max(lim, x);
    }
}


void Process() {
    maxy t = 0;
    k = k * 2 + 1;

    for(maxn i = 0; i < std::min(k, lim); i++) t += a[i];
    res = t;
    //std::cout << t << '\n';

    for(maxn i = k; i < lim; i++) {
        t += a[i];
        t -= a[i - k];
        //std::cout << i << ' ' << t << '\n';

        res = std::max(res, t);
    }
}


int main() {
    freopen("mobi.inp","r",stdin);
    //freopen("mobi.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
    std::cout << res;
}
