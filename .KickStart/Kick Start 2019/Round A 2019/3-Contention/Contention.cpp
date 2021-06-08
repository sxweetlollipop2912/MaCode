#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1000001
#define maxS 4000001
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define fi first
#define se second

typedef long maxn;
typedef std::pair <maxn, maxn> p_t;

maxn n, Q, seg[maxS], res;
bool lz[maxS];
std::vector <p_t> q;


bool cmp(const p_t p1, const p_t p2) {
    return (p1.se - p1.fi) < (p2.se - p2.fi);
}

void Prepare() {
    std::cin >> n >> Q;

    q.clear();
    for(maxn i = 0; i < Q; i++) {
        maxn l, r; std::cin >> l >> r;
        q.push_back(p_t(l, r));
    }

    std::sort(q.begin(), q.end(), cmp);
}


maxn Build(maxn seg[], const maxn ids = 0, const maxn L = 1, const maxn R = n) {
    if (L > R) return 0;
    lz[ids] = 0;
    if (L == R) return (seg[ids] = 1);
    return (seg[ids] = Build(seg, cle(ids), L, mid(L, R)) + Build(seg, cri(ids), mid(L, R) + 1, R));
}


void Lazy(const maxn ids, const maxn L, const maxn R) {
    if (lz[ids]) seg[ids] = 0;
    if (L != R) {
        lz[cle(ids)] |= lz[ids];
        lz[cri(ids)] |= lz[ids];
    }
    lz[ids] = 0;
}


maxn Upd(maxn seg[], const maxn Lq, const maxn Rq, const maxn ids = 0, const maxn L = 1, const maxn R = n) {
    if (L > R || Lq > Rq) return 0;
    Lazy(ids, L, R);

    if (R < Lq || L > Rq) return seg[ids];
    if (L >= Lq && R <= Rq) {
        lz[ids] = 1;
        Lazy(ids, L, R);
        return seg[ids];
    }
    maxn ans = Upd(seg, Lq, Rq, cle(ids), L, mid(L, R)) + Upd(seg, Lq, Rq, cri(ids), mid(L, R) + 1, R);
    ///std::cout << "upd " << L << ' ' << R << ' ' << ans << '\n';
    return (seg[ids] = ans);
}


maxn Sum(maxn seg[], const maxn Lq, const maxn Rq, const maxn ids = 0, const maxn L = 1, const maxn R = n) {
    if (L > R || Lq > Rq || R < Lq || L > Rq) return 0;
    Lazy(ids, L, R);
    //std::cout << "insum " << L << ' ' << R << ' ' << ids << ' ' << seg[ids] << '\n';

    if (L >= Lq && R <= Rq) return seg[ids];
    return Sum(seg, Lq, Rq, cle(ids), L, mid(L, R)) + Sum(seg, Lq, Rq, cri(ids), mid(L, R) + 1, R);
}


maxn Process() {
    Build(seg);
    res = n;

    for(maxn i = 0; i < Q; i++) {
        //std::cout << "sum " << q[i].fi << ' ' << q[i].se << ' ' << Sum(seg, q[i].fi, q[i].se) << '\n';
        res = std::min(res, Sum(seg, q[i].fi, q[i].se));
        Upd(seg, q[i].fi, q[i].se);
        //std::cout << i << ' ' << q[i].fi << ' ' << q[i].se << ' ' << res << '\n';
    }

    return res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t; std::cin >> t;

    for(int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": ";
        Prepare();
        std::cout << Process() << '\n';
    }
}