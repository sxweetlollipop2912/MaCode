#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 502
#define maxA 99999999999999999

typedef int maxn;
typedef long long maxa;

maxn n, p[maxN], res;
maxa B, a[maxN], aa[maxN], f[maxN][maxN];
bool daa[maxN];


void Prepare() {
    std::cin >> n >> B;

    for(maxn i = 1; i <= n; i++) {
        std::cin >> a[i] >> aa[i];
        aa[i] = a[i] - aa[i];
        if (i != 1) std::cin >> p[i];
        else p[i] = 0;
    }
}


maxn Process() {
    maxa T = 0;
    for(maxn i = 1; i <= n; i++) T += aa[i];
    if (T <= B) res = n;

    std::fill(f[0], f[0] + n + 1, maxA);
    f[0][0] = 0;

    for(maxn iaa = 1; iaa <= n; iaa++) {
        std::fill(daa, daa + n + 1, 0);
        maxa B1 = B;
        maxn re = 0;
        for(maxn i = iaa; i != 0; i = p[i]) B -= aa[i], daa[i] = 1, ++re;

        for(maxn i = 1; i <= n; i++) for(maxn q = 1; q <= i; q++) {
            f[i][q] = f[i - 1][q];
            if (daa[i]) continue;

            f[i][q] = std::min(f[i][q], f[i - 1][q - 1] + a[i]);
        }

        for(maxn i = n; i >= 1; i--)
            if (f[n][i] <= B1) {
                res = std::max(res, re + i);
                break;
            }
        if (B1 >= 0) res = std::max(res, re);
    }

    std::cout << res;
}


int main() {
    freopen("shopping.inp", "r", stdin);
    Prepare();
    Process();
}
