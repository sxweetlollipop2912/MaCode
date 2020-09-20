#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 60002
#define maxS 250002
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)

typedef long maxn;
typedef long long maxa;

maxn C, n, seat;
maxa seg[maxS], lazy[maxS];


void Prepare() {
	std::cin >> C >> seat >> n;
}


void Lazy(const maxn ids) {
	lazy[cle(ids)] += lazy[ids];
	lazy[cri(ids)] += lazy[ids];
	seg[ids] += lazy[ids], lazy[ids] = 0;
}


maxa Update(const maxn ids, const maxn l, const maxn r, const maxn L, const maxn R, const maxa val) {
	if (l > r) return 0;
	Lazy(ids);
	if (r < L || l > R) return seg[ids];

	if (l >= L && r <= R) {
		lazy[ids] += val;
		Lazy(ids);
	}
	else seg[ids] = std::max(Update(cle(ids), l, mid(l, r), L, R, val), Update(cri(ids), mid(l, r) + 1, r, L, R, val));

	return seg[ids];
}


maxa Get_max(const maxn ids, const maxn l, const maxn r, const maxn L, const maxn R) {
	if (l > r || r < L || l > R) return 0;
	Lazy(ids);

	if (l >= L && r <= R) return seg[ids];
	return std::max(Get_max(cle(ids), l, mid(l, r), L, R), Get_max(cri(ids), mid(l, r) + 1, r, L, R));
}


void Process() {
	while (n--) {
		maxn l, r; maxa a;
		std::cin >> l >> r >> a, --l, --r;
		//std::cout << Get_max(0, 0, C - 1, l, r - 1) << '\n';
		if (Get_max(0, 0, C - 1, l, r - 1) > seat - a) std::cout << "N\n";
		else {
			std::cout << "T\n";
			Update(0, 0, C - 1, l, r - 1, a);
		}
	}
}


int main() {
	//freopen("kol.inp", "r", stdin);
	//freopen("kol.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}