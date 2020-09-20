#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 201
#define maxK 32
#define maxA 32001

typedef int maxn, maxk, maxa;

maxn n, pos[maxN][maxK], pos_re;
maxk K;
maxa a[maxN], f[maxN][maxK];


void Prepare() {
	//freopen("POSITION.inp", "r", stdin);
	//freopen("POSITION.out", "w", stdout);

	std::cin >> n >> K;

	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


maxn lower(maxa x, maxn l, maxn r) {

	while (l < r) {
		maxn m = (l + r + 1) / 2;
		if (a[m] > x) r = m - 1;
		else l = m;
	}

	if (a[l] <= x) return l;
}


maxa Max(maxn l, maxn r) { // l + 1 < r

	maxn m = (a[l] + a[r]) / 2;

	maxn x = lower(m, l, r);
	maxn y = x + 1;

	return std::max(a[x] - a[l], a[r] - a[y]);
}


void fillIn(maxn ii, maxn i) { // i > ii
	maxn len_max = Max(ii, i);

	for (maxk k = 2; k - 1 <= n - i && k <= K; k++) {

		maxa fi = f[i][k - 1] + len_max;

		if (f[ii][k] > fi) {
			f[ii][k] = fi;
			pos[ii][k] = i;
		}

		//f[ii][k] = std::min(f[ii][k], std::max(f[i][k - 1], len_max));
	}
}


void Trace() {
	maxk k = K;

	while (k > 0) {

		std::cout << a[pos_re] << '\n';
		pos_re = pos[pos_re][k--];
	}
}


int main() {
	Prepare();

	maxa re = maxA;

	for (maxn i = n - 1; i >= 0; i--) {

		f[i][1] = a[n - 1] - a[i];
		pos[i][1] = n;

		for (maxk k = 2; k <= n - i && k <= K; k++) {
			f[i][k] = f[i + 1][k - 1];
			pos[i][k] = i + 1;
		}

		for (maxn j = i + 2; j < n; j++)
			fillIn(i, j);

		if (n - i >= K && re > f[i][K] + a[i] - a[0]) {
			re = f[i][K] + a[i] - a[0];
			pos_re = i;
		}
	}

	std::cout << re << '\n';
	Trace();
}