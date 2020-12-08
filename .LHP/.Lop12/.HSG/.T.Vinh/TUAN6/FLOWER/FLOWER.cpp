// AC
#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002

typedef long maxn;

const maxn N = 100000;

maxn n, bit[maxN], res;


void Prepare() {
    std::cin >> n;
}


void Update(maxn idx, const maxn val) {
    for(; idx <= N; idx += (idx & (-idx))) bit[idx] += val;
}
maxn Sum(maxn idx) {
    maxn re = 0;
    for(; idx > 0; idx -= (idx & (-idx))) re += bit[idx];
    return re;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) {
        maxn l, r; std::cin >> l >> r;
        if (l > r) std::swap(l, r);

        maxn sl = Sum(l);
        Update(l, -sl); Update(l + 1, sl);
        maxn sr = Sum(r);
        Update(r, -sr); Update(r + 1, sr);

        res += sl + sr;
        std::cout << sl + sr << '\n';

        if (l + 1 >= r) continue;
        Update(l + 1, 1); Update(r, -1);
    }
}


int main() {
    freopen("flower.inp", "r", stdin);
    freopen("flower.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}