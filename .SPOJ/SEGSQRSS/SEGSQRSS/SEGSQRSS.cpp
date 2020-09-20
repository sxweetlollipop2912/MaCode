// AC SPOJ
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxS 400001
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define L_base 0
#define R_base (n - 1)
#define root_idx 0
#define sqr(x) ((x) * (x))
#define inc 1
#define set 0

typedef long long maxn;
typedef long long maxa;

maxn n;
long Q;
maxa a[maxN], seg[maxS], seg2[maxS], laz[maxS];
bool opt[maxS];


void Prepare() {
	std::cin >> n >> Q;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Build(const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	if (L > R) return;
	if (L == R) seg[ids] = a[L], seg2[ids] = sqr(seg[ids]);
	else {
		Build(L, mid(L, R), cle(ids)); Build(mid(L, R) + 1, R, cri(ids));
		seg[ids]  = seg[cle(ids)]  + seg[cri(ids)];
		seg2[ids] = seg2[cle(ids)] + seg2[cri(ids)];
	}
	laz[ids] = 0, opt[ids] = inc;
}


void Laz(const maxn ids, const maxn L, const maxn R) {
	if (opt[ids] == inc) {
		seg2[ids] = 2 * laz[ids] * seg[ids] + seg2[ids] + (R - L + 1) * sqr(laz[ids]);
		seg[ids] += (R - L + 1) * laz[ids];
		if (L != R) laz[cle(ids)] += laz[ids], laz[cri(ids)] += laz[ids];
	}
	else {
		seg2[ids] = sqr(laz[ids]) * (R - L + 1);
		seg[ids] = laz[ids] * (R - L + 1);
		if (L != R) laz[cle(ids)] = laz[cri(ids)] = laz[ids], opt[cle(ids)] = opt[cri(ids)] = set;
	}
	opt[ids] = inc, laz[ids] = 0;
}


void Update(const maxn Lq, const maxn Rq, const maxa val, const bool op, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	Laz(ids, L, R);
	if (R < Lq || L > Rq) return;

	if (L != R) {
		Update(Lq, Rq, val, op, L, mid(L, R), cle(ids)); Update(Lq, Rq, val, op, mid(L, R) + 1, R, cri(ids));
		seg[ids] = seg[cle(ids)] + seg[cri(ids)];
		seg2[ids] = seg2[cle(ids)] + seg2[cri(ids)];
		return;
	}

	if (op == inc) seg[ids] += val, seg2[ids] = sqr(seg[ids]);
	else seg[ids] = val, seg2[ids] = sqr(seg[ids]);
}


maxa GetSum2(const maxn Lq, const maxn Rq, const maxn L = L_base, const maxn R = R_base, const maxn ids = root_idx) {
	Laz(ids, L, R);
	if (R < Lq || L > Rq) return 0;
	if (L < Lq || R > Rq) return GetSum2(Lq, Rq, L, mid(L, R), cle(ids)) + GetSum2(Lq, Rq, mid(L, R) + 1, R, cri(ids));
	return seg2[ids];
}


void Process() {
	Build();

	while (Q--) {
		int op; maxn l, r;
		std::cin >> op >> l >> r, --l, --r;
		
		if (op == 2) {
			std::cout << GetSum2(l, r) << '\n';
		}
		else {
			maxa x; std::cin >> x;
			Update(l, r, x, op);
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	for(int cnt = 1; cnt <= t; cnt++) {
		std::cout << "Case " << cnt << ":\n";
		Prepare();
		Process();
	}
}