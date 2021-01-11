#include <iostream>
#include <cstdio>

#define maxN 100001
#define maxL 1000000001

typedef long maxn;
typedef long long maxl;

maxn n;
maxl a[maxN], k = 1, r;


void Prepare() {
    std::cin >> n >> k;

    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i];
        r += a[i];
    }

    r /= k;
}


bool check(maxl x) {
    if (!x) return 1;
    maxl re = 0;

    for(maxn i = 0; i < n; i++) re += a[i] / x;
    return re >= k;
}


maxl smax() {
    maxl l = 0;

    while (l != r) {
        maxl m = (l + r + 1) / 2;
        if (!check(m)) r = m - 1;
        else l = m;
    }

    if (!r) return -1;
    return r;
}


int main() {
    //std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("wires.inp","r",stdin);
    //freopen("wires.out","w",stdout);

    Prepare();
    maxl res = smax();
    std::cout << res;
}
