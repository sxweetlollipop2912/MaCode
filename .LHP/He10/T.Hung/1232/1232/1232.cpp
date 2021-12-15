// not done
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxL 100001
#define maxS 200001
#define maxH 1000000001
#define cleft(x) ((x)*2 + 1)
#define cright(x) ((x)*2 + 2)
#define root 0

typedef long maxn, maxl;
typedef long long maxh;

maxn n;
maxl le[maxN], ri[maxN], mn, mx;
maxh hi[maxN],  seg[maxS], lazy[maxS];
bool whole[maxS];


void Prepare() {
	std::cin >> n;

	mn = maxL;
	mx = 0;
	for (maxn i = 0; i < n; i++) {
		std::cin >> le[i] >> ri[i] >> hi[i];
		mn = std::min(mn, le[i]);
		mx = std::max(mx, ri[i]);
	}

	std::fill(lazy, lazy + maxS, -1);
}


void GetOffUrAs(const maxn ids, const maxl L, const maxl R) {
	if (seg[ids] > lazy[ids]) return;

	seg[ids] = lazy[ids];
	whole[ids] = 1;

	if (L == R) return;
	lazy[cleft(ids)] = lazy[cright(ids)] = seg[ids];
}


maxl Update(const maxn ids, const maxl L, const maxl R, const maxn id) {
	if (L > ri[id] || R < le[id]) return 0;
	GetOffUrAs(ids, L, R);

	if (seg[ids] < hi[id]) {
		seg[ids] = hi[id];
		if (le[id] <= L && ri[id] >= R) {
			lazy[ids] = lazy[cleft(ids)] = lazy[cright(ids)] = hi[id];
			return R - L;
		}
	}

	else if (le[id] <= L && ri[id] >= R) {
		if (whole[ids]) {
			if (seg[ids] > hi[id]) return 0;
			return R - L;
		}
		if (seg[ids] == hi[id]) lazy[ids] = hi[id];
	}

	return Update(cleft(ids), L, (L + R) / 2, id) + Update(cright(ids), (L + R) / 2 + 1, R, id);
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		std::cout << Update(root, mn, mx, i) << '\n';
	}
}


int main() {
	Prepare();
	Process();
}