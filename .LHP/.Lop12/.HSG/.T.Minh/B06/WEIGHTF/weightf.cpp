#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

#define maxC 200002
#define maxN 101
#define cost first
#define wght second

typedef int maxn, maxw;
typedef long maxa;
typedef std::pair <maxa, maxw> c_t;

const maxw maxW = 999999999;
const maxa MAXC = 200000;

maxn nc, n, a[maxN], idx[maxN];
maxw f[maxC], last[maxN][maxC], res;
maxa C;
c_t c[maxN];


bool cmp(const maxn &x, const maxn &y) {
    return c[x] < c[y];
}


void Prepare() {
    std::cin >> C >> nc >> n;

    for(maxn i = 0; i < nc; i++) {
        double W; std::cin >> c[i].cost >> W;
        c[i].wght = round(W * 100);
        idx[i] = i;
    }
    std::sort(idx, idx + nc, cmp);

    for(maxn i = 0; i < n; i++) std::cin >> a[i], --a[i], res += c[a[i]].wght;
}


maxw W_change(maxa C) {
    maxw re = 0;
    for(maxn i = nc - 1; i >= 0 && C != 0; i--) {
        maxn cnt = C / c[idx[i]].cost;
        C %= c[idx[i]].cost, re += cnt * c[idx[i]].wght;
    }
    return re;
}


bool Process() {
    std::fill(f, f + maxC, -maxW);
    f[0] = 0;
    maxa T = 0;
    for(maxn i = 0; i < n; T += c[a[i]].cost, i++) for(maxa t = std::min(T, MAXC - c[a[i]].cost); t >= 0; t--) {
        if (f[t + c[a[i]].cost] >= f[t] + c[a[i]].wght) continue;
        f[t + c[a[i]].cost] = f[t] + c[a[i]].wght;
        last[i][t + c[a[i]].cost] = f[t + c[a[i]].cost];
    }

    maxw re = maxW; maxa re_t = 0;
    for(maxa t = C; t <= T; t++)
        if (f[t] != -maxW && re > -f[t] + W_change(t - C)) re = -f[t] + W_change(t - C), re_t = t;

    if (re == maxW) return 0;

    maxw res1 = ((res + re) / 100), res2 = ((res + re) % 100);
    std::cout << res1 << ".";
    if (res2 < 10) std::cout << "0";
    std::cout << res2 << '\n';

    re = f[re_t];
    for(maxn i = n - 1; i >= 0 && re_t != 0; i--) {
        if (last[i][re_t] != re) continue;
        std::cout << a[i] + 1 << '\n';
        re_t -= c[a[i]].cost, re -= c[a[i]].wght;
    }
    return 1;
}


int main() {
    freopen("weightf.inp", "r", stdin);
    freopen("weightf.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    if (!Process()) std::cout << "-1";
}
