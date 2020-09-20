#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

#define maxN 100001
#define maxR 1000000001

typedef long maxn, maxa;

maxa a[maxN], T, res;
maxn n;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		T += a[i];
	}
}


maxa D(maxn x, maxn y) {
	maxn m = std::min(x, y);

	if (m == 0 && x + y - m == n - 1) return a[n - 1];
	return a[m];
}


maxn next(maxn u) {
	return (u + 1) % n;
}


maxn prev(maxn v) {
	if (!v) return n - 1;
	return v - 1;
}


void Process() {
	res = 0;
	maxa d = D(0, n - 1);
	maxn v = 0;

	for (maxn u = 0; u < n; u++) {
		d -= D(u, prev(u));

		maxa tmp = D(v, next(v));

		while (d + tmp <= T / 2) {
			d += tmp;
			v = next(v);
			tmp = D(v, next(v));
		}

		res = std::max(res, std::max(d, T - d - tmp));
	}
}


int main() {
	freopen("wys.inp", "r", stdin);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	std::cout << res;
}