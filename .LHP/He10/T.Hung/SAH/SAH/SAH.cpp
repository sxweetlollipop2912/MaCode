#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 41
#define maxA 40000000001
#define maxH 1000000001
#define top first
#define bottom second

typedef int maxn;
typedef long long maxa, maxh, maxr;
typedef std::pair <maxn, maxn> tb_t;

maxn n, na, nb;
maxa T, a[maxN];
maxh h[maxN];
std::vector <maxa> nat[maxN];
maxr res;


void Prepare() {
	std::cin >> n >> T;
	na = n / 2; nb = n - na;

	for (maxn i = 1; i <= n; i++)
		std::cin >> h[i] >> a[i];
}


tb_t TopBot(const maxr c, const maxn n, const maxn add) {
	maxn id = 0, tp = 0, bm = 0;
	while (++id <= n) {
		if (!(c & (1 << (id - 1)))) continue;
		if (h[tp] > h[id + add]) return tb_t(-1, -1);
		if (!bm) bm = id + add;
		tp = id + add;
	}
	return tb_t(tp, bm);
}


void Na() {
	for (maxr i = 0; i < (1 << na); i++) {
		maxn tp = TopBot(i, na, 0).top;
		if (tp == -1) continue;

		maxa t = 0; maxn id = 1;
		while (id <= na) t += a[id] * (bool)(i & (1 << (id - 1))), ++id;
		nat[tp].push_back(t);
	}

	for(maxn i = 0; i <= na; i++)
		std::sort(nat[i].begin(), nat[i].end());
}


maxr fit(const maxa x, const maxn id) {
	return nat[id].end() - std::lower_bound(nat[id].begin(), nat[id].end(), x);
}


void Nb() {
	for (maxr i = 0; i < (1 << nb); i++) {
		maxn bm = TopBot(i, nb, na).bottom;
		if (bm == -1) continue;

		maxa t = 0; maxn id = 1;
		while (id <= nb) t += a[id + na] * (bool)(i & (1 << (id - 1))), ++id;
		
		for (maxn ia = 0; ia <= na; ia++)
			if (h[ia] <= h[bm]) res += fit(T - t, ia);
	}
}


void Process() {
	Na();
	Nb();
	std::cout << res;
}


int main() {
	//freopen("sah.inp", "r", stdin);
	//freopen("sah.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}