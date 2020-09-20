// AC SPOJ, RMQ_Segment_Tree, Lazy_Propagation
#include <iostream>
#include <algorithm>

#define maxN 50001
#define maxS 150001
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define L_base 0
#define R_base (n - 1)
#define root_idx 0

typedef long maxn, maxa;

maxn n, m;
maxa seg[maxS], laz[maxS];


void Prepare() {
	std::cin >> n;
}


void Laz(const maxn ids, const maxn L, const maxn R) {
	seg[ids] += laz[ids];
	if (L != R) laz[cle(ids)] += laz[ids], laz[cri(ids)] += laz[ids];
	laz[ids] = 0;
}


maxa Update(maxa seg[], const maxn Lq, const maxn Rq, const maxa val, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	if (L > R) return 0;
	Laz(ids, L, R);
	if (L > Rq || R < Lq) return seg[ids];
	if (L < Lq || R > Rq) return (seg[ids] = std::max(Update(seg, Lq, Rq, val, L, mid(L, R), cle(ids)), Update(seg, Lq, Rq, val, mid(L, R) + 1, R, cri(ids))));
	laz[ids] = val; Laz(ids, L, R);
	return seg[ids];
}


maxa GetMax(maxa seg[], const maxn Lq, const maxn Rq, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	if (L > R || L > Rq || R < Lq) return 0;
	Laz(ids, L, R);
	if (L < Lq || R > Rq) return std::max(GetMax(seg, Lq, Rq, L, mid(L, R), cle(ids)), GetMax(seg, Lq, Rq, mid(L, R) + 1, R, cri(ids)));
	return seg[ids];
}


void Process() {
	std::cin >> m;
	while (m--) {
		maxn u, v; maxa a;
		std::cin >> u >> v >> a, --u, --v;
		Update(seg, u, v, a);
	}
	std::cin >> m;
	while (m--) {
		maxn u, v;
		std::cin >> u >> v, --u, --v;
		std::cout << GetMax(seg, u, v) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}