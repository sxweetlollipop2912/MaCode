// AC
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 200002
#define maxS 800005
#define mid(l, r) (((l) + (r)) / 2)
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)

typedef long maxn;
typedef long long maxa;

const maxa INF = 2e18;

maxn n;
maxa M, A, B, a[maxN], sA[maxS], sB[maxS], sum[maxN], f[maxN];


void Prepare() {
    std::cin >> n >> M >> A >> B;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
}


maxa Update(maxa seg[], const maxn IDX, const maxa VAL, const maxn L = 0, const maxn R = n, const maxn ids = 0) {
    if (L > IDX || R < IDX) return seg[ids];
    if (L == R) 
        seg[ids] = VAL;
    else
        seg[ids] = std::min(Update(seg, IDX, VAL, L, mid(L, R), cle(ids)), Update(seg, IDX, VAL, mid(L, R) + 1, R, cri(ids)));
    return seg[ids];
}


maxa GetMin(maxa seg[], const maxn Lq, const maxn Rq, const maxn L = 0, const maxn R = n, const maxn ids = 0) {
    if (L > R || L > Rq || R < Lq) return INF;
    if (L >= Lq && R <= Rq) return seg[ids];
    return std::min(GetMin(seg, Lq, Rq, L, mid(L, R), cle(ids)), GetMin(seg, Lq, Rq, mid(L, R) + 1, R, cri(ids)));
}


void Process() {
    std::fill(sA, sA + maxS, INF);
    std::fill(sB, sB + maxS, INF);
    Update(sA, 0, 0); Update(sB, 0, 0);

    for(maxn i = 1; i <= n; i++) {
        maxn idx = std::upper_bound(sum, sum + i + 1, sum[i] - M) - sum;
        f[i] = INF;

        if (idx < i) // B
            f[i] = std::min(f[i], GetMin(sB, idx, i - 1) - sum[i]*B + M*B);
        if (idx > 0) // A
            f[i] = std::min(f[i], GetMin(sA, 0, idx - 1) + sum[i]*A - M*A);

        Update(sA, i, f[i] - sum[i]*A);
        Update(sB, i, f[i] + sum[i]*B);
    }

    std::cout << f[n];
}


int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}