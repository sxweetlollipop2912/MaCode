#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 500002

typedef long maxn;

maxn n, a[3][maxN], bit[maxN], idx[maxN], res;


bool cmp(const maxn x, const maxn y) {
    return a[0][x] < a[0][y];
}

void Prepare() {
    std::cin >> n;
    for(int k = 0; k < 3; k++) for(maxn i = 1, u; i <= n; i++) std::cin >> u, --u, a[k][u] = i, idx[u] = u;
    std::sort(idx, idx + n, cmp);
    std::fill(bit, bit + maxN, maxN);
}


void Update(maxn bit[], maxn idx, const maxn val) {
    for(; idx <= n; idx += (idx & (-idx))) bit[idx] = std::min(bit[idx], val);
}

maxn GetMin(maxn bit[], maxn idx) {
    maxn re = maxN;
    for(; idx > 0; idx -= (idx & (-idx))) re = std::min(re, bit[idx]);
    return re;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) {
        maxn x2 = a[1][idx[i]], x3 = a[2][idx[i]];
        if (GetMin(bit, x2 - 1) > x3) ++res;
        Update(bit, x2, x3);
        //std::cout << i << ' ' << idx[i] + 1 << ' ' << x2 << ' ' << x3 << ' ' << GetMin(smn, 0, x2 - 1) << ' ' << res << '\n';
    }
    std::cout << res;
}


int main() {
    freopen("dt.inp", "r", stdin);
    freopen("dt.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
