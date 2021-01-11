#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100001
#define PR_sz 5

typedef long maxn, maxb;
typedef long long maxa;

const maxa pr[] = { 2,3,5,7,11 };
const maxb BIT = (1 << 5) - 1;

maxn n, f[BIT + 2], res;


void Prepare() {
    std::cin >> n;
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        maxb b = 0; maxa a; std::cin >> a;
        for(int j = 0; j < PR_sz; j++) if (a % pr[j] == 0) b |= (1 << j);
        for(maxb ib = 0; ib <= BIT; ib++) {
            if ((b & ib) != 0) continue;
            f[b] = std::max(f[b], f[ib] +1);
        }
    }
    res = 0;
    for(maxn i = 0; i <= BIT; i++) res = std::max(res, f[i]);
    std::cout << res;
}


int main() {
    freopen("coprime.inp", "r", stdin);
    freopen("coprime.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
