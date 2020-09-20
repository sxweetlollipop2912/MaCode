#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 503
#define maxA 1000001
#define maxM 1000000001
#define maxR 1000000000000001
#define des n + 1
#define start 0

typedef int maxn;
typedef long maxa;
typedef long long maxm;

struct info {
	maxa d;
	maxm m;
};
info newInfo(const maxa d, const maxm m) {
	info re;
	re.d = d; re.m = m;
	return re;
}

maxn n;
maxa x[maxN];
maxm M[maxN];
std::vector <info> f[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> x[i] >> M[i];

	std::cin >> x[des];
	M[des] = 0;

	x[start] = 0;
	M[start] = 0;
}


maxm b_search(const maxn n, const maxa x) { // search -> >= x _ reversed_sort
	//if (f[n].empty()) return newInfo(-1, -1);
	maxn l = 0, r = f[n].size() - 1;

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (f[n][m].d < x) r = m - 1;
		else l = m;
	}

	return f[n][l].d >= x ? f[n][l].m : -1;
}


bool cmp(const info &x, const info &y) {
	return x.m < y.m;
}

void Process() {
	f[0].push_back(newInfo(maxA, M[0]));

	for (maxn i = 1; i <= n + 1; i++) {
		for (maxn j = 0; j < i; j++) {
			maxm tmp_m = b_search(j, x[i] - x[j]);

			if (tmp_m == -1) continue;

			if (!f[i].empty() && f[i].back().m >= tmp_m + M[i]) continue;
			f[i].push_back(newInfo(x[i] - x[j], tmp_m + M[i]));
		}
	}

	std::cout << f[des][std::max_element(f[des].begin(), f[des].end(), cmp) - f[des].begin()].m;
}


int main() {
	//freopen("prince.inp", "r", stdin);
	//freopen("prince.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}