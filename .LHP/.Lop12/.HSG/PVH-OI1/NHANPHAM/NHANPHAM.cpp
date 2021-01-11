#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 100001

typedef long maxn;
typedef long long maxa;
typedef double db;

maxn n;
maxa K, a[maxN], T;


void Prepare() {
    std::cin >> n >> K;
    T = 0;
    for(maxn i = 0; i < n; i++) std::cin >> a[i], T += a[i];
}


bool Check(const maxa m, const maxa X) {
    db x = ((n * (n + 1)) / 2) - T; x += ((m - 1) / (db)2) * (db)(n * n);
    return x >= (X / (db)m);
}


maxa Process() {
    maxa day = 2, x = 1 - a[0];
    for(maxn i = 1; i < n && x < K; day++, i++) x += day - a[i];//, std::cout << day << ' ' << x << ' ' << i << ' ' << a[i] << '\n';
    if (x >= K) return day - 1;

    maxa l = ceil((((db)T + ((n * n) / (db)2) - (db)((n * (n + 1)) / 2)) / (db)2) / ((n * n) / (db)2)), r = 1e18;
    //std::cout << "l " << l << '\n';
    while (l != r) {
        maxa m = (l + r) / 2;
        if (Check(m, K)) r = m;
        else l = m + 1;
    }

    maxa re = l * n, res = re; x = 0;
    for(maxn i = 2 * n - 1; i >= 0 && re > 1; i--, re--) {
        //std::cout << i << ' ' << x << ' ' << (res - (n - i - 1)) << ' ' << n << ' ' << res << '\n',
        x = x - a[i % n] + re;
        if (Check(l, K + x)) res = re - 1;
    }
    return res;
}


int main() {
    freopen("nhanpham.inp", "r", stdin);
    freopen("nhanpham.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process();
}
