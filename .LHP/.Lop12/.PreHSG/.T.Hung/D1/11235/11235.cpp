#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>

#define maxN 100001
#define maxL 20
#define CNT first
#define LCNT second

typedef long maxn, maxa;
typedef std::pair <maxn, maxn> p_t;

maxn n, Q, cnt[maxL][maxN], lcnt[maxL][maxN], rcnt[maxL][maxN], LOG2;
maxa a[maxN];


void Prepare() {
    std::cin >> Q;
    LOG2 = log2(n);
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


p_t Count(const maxn L, const maxn R) {
    if (L > R) return p_t(0, 0);
    if (L == R) return p_t(cnt[0][L], lcnt[0][L]);

    maxn log = log2(R - L + 1), M = L + ((maxn)1 << log), re = 0;
    if (M > R) return p_t(cnt[log][L], lcnt[log][L]);

    p_t p = Count(M, R);
    if (a[M - 1] == a[M]) re = rcnt[log][L] + p.LCNT;
    re = std::max(re, std::max(cnt[log][L], p.CNT));
    maxn l_cnt = a[L] == a[M]? (M - L) + p.LCNT : lcnt[log][L];
    return p_t(re, l_cnt);
}


void Process() {
    for(maxn i = 0; i < n; i++) cnt[0][i] = lcnt[0][i] = rcnt[0][i] = 1;

    for(maxn l = 1; l <= LOG2; l++) for(maxn i = 0; i <= (n - ((maxn)1 << l)); i++) {
        maxn L = i, R = i + ((maxn)1 << l) - 1, M = L + ((maxn)1 << (l - 1));

        cnt[l][i] = std::max(cnt[l - 1][L], cnt[l - 1][M]);
        if (a[M - 1] == a[M])
            cnt[l][i] = std::max(cnt[l][i], rcnt[l - 1][L] + lcnt[l - 1][M]);
        lcnt[l][i] = a[L] == a[M]?     cnt[l][i] : lcnt[l - 1][i];
        rcnt[l][i] = a[M - 1] == a[R]? cnt[l][i] : rcnt[l - 1][M];
    }

    maxn ql, qr;
    while (Q--) {
        std::cin >> ql >> qr;
        --ql, --qr;
        std::cout << Count(ql, qr).CNT << '\n';
    }
}


int main() {
    freopen("11235.inp","r",stdin);
    freopen("11235.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (std::cin >> n && n) {
        Prepare();
        Process();
    }
}
