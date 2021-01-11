#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 13
#define BIT ((1 << n) - 1)

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN][maxN], res;


void Prepare() {
    std::cin >> n;
    for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


void Backtrack(const int rw, const int ld, const int rd, const maxn row, const maxa re) {
    if (rw == BIT) {
        res = std::max(res, re);
        return;
    }
    int bit = BIT & (~(rw | ld | rd));
    while (bit != 0) {
        maxn pos = bit & (-bit);
        bit -= pos;
        Backtrack(rw | pos, (ld | pos) >> 1, (rd | pos) << 1, row + 1, re + a[row][(maxn)log2(pos)]);
    }
}


void Process() {
    res = 0;
    Backtrack(0, 0, 0, 0, 0);
    std::cout << res;
}


int main() {
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
