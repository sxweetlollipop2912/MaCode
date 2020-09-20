#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100001
#define maxL 100001
#define maxS 200001
#define cleft(x) ((x)*2 + 1)
#define cright(x) ((x)*2 + 2)
#define root 0

typedef long maxn, maxl;

maxn n, seg[maxS], lazy[maxS];
maxl le[maxN], ri[maxN], mn, mx;


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


void GetOffUrAs(const maxn ids, const maxl L, const maxl R) {
	if (!lazy[ids]) return;
	seg[ids] += lazy[ids];

	if (L < R) lazy[cleft(ids)] = lazy[cright(ids)] = lazy[ids];
	lazy[ids] = 0;
}


void Update(const maxn ids, const maxl L, const maxl R, const maxn l, const maxn r, const maxn x) {
	if (!x || L > r || R < l || L > R) return;

	if (L >= l && R <= r) {
		lazy[ids] += x;
		return;
	}

	Update(cleft(ids), L, (L + R) / 2, l, r, x);
	Update(cright(ids), (L + R) / 2 + 1, R, l, r, x);
}


maxn Get(const maxn ids, const maxl L, const maxl R, const maxn l, const maxn r) {
	if (L > r || R < l) return 0;
	maxn re = 0;
	GetOffUrAs(ids, L, R);

	if (L >= l && R <= r) re = seg[ids];
	else re = Get(cleft(ids), L, (L + R) / 2, l, r) + Get(cright(ids), (L + R) / 2 + 1, R, l, r);

	seg[ids] -= re;
	return re;
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		maxn a = Get(root, mn, mx, le[i], le[i]);
		maxn b = Get(root, mn, mx, ri[i], ri[i]);

		Update(root, mn, mx, le[i] + 1, ri[i] - 1, 1);

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