#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100001
#define maxL 100001
#define maxS 200001
#define INF 999999999
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define L_base mn
#define R_base mx
#define root_idx 0

typedef long maxn;

maxn n, seg[maxS], laz[maxS];
maxn le[maxN], ri[maxN], mn, mx;


void Prepare() {
	std::cin >> n;

	mn = maxL;
	mx = 0;
	for (maxn i = 0; i < n; i++) {
		std::cin >> le[i] >> ri[i];
		mn = std::min(mn, le[i]);
		mx = std::max(mx, ri[i]);
	}
}


void Laz(const maxn ids, const maxn L, const maxn R) {
    if (laz[ids] == INF) {
        seg[ids] = 0;
	    if (L != R) laz[cle(ids)] = laz[cri(ids)] = INF;
    }
	else {
        seg[ids] += laz[ids];
	    if (L != R) 
            laz[cle(ids)] = laz[cle(ids)] == INF? laz[ids] : laz[cle(ids)] + laz[ids], 
            laz[cri(ids)] = laz[cri(ids)] == INF? laz[ids] : laz[cri(ids)] + laz[ids];
    }
	laz[ids] = 0;
}


maxn Update(maxn seg[], const maxn Lq, const maxn Rq, const maxn val, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	if (L > R) return 0;
	Laz(ids, L, R);

	if (L > Rq || R < Lq) return seg[ids];
	if (L < Lq || R > Rq) return (seg[ids] = std::max(Update(seg, Lq, Rq, val, L, mid(L, R), cle(ids)), Update(seg, Lq, Rq, val, mid(L, R) + 1, R, cri(ids))));

	laz[ids] = val; Laz(ids, L, R);
	return seg[ids];
}


maxn GetSum(maxn seg[], const maxn Lq, const maxn Rq, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	if (L > R || L > Rq || R < Lq) return 0;
	Laz(ids, L, R);

    maxn re = 0;
	if (L < Lq || R > Rq) re = GetSum(seg, Lq, Rq, L, mid(L, R), cle(ids)) + GetSum(seg, Lq, Rq, mid(L, R) + 1, R, cri(ids));
	else re = seg[ids];

    laz[ids] = INF; Laz(ids, L, R);
    return re;
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		maxn a = GetSum(seg, le[i], le[i]);
		maxn b = GetSum(seg, ri[i], ri[i]);

		Update(seg, le[i] + 1, ri[i] - 1, 1);

		std::cout << a + b << '\n';
	}
}


int main() {
	//freopen("xoso.inp", "r", stdin);
	//freopen("xoso.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}