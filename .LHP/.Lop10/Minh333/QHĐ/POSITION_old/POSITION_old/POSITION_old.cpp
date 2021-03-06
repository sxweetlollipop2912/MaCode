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

	if (a[r] <= x) return r;
}


maxn higher(maxa x, maxn l, maxn r) {

	while (l < r) {
		maxn m = (l + r) / 2;
		if (a[m] < x) l = m + 1;
		else r = m;
	}

	if (a[r] >= x) return r;
}


maxa Max(maxn l, maxn r) { // l + 1 < r

	maxn m = (a[l] + a[r]) / 2;

	maxn x = lower(m, l, r);
	maxn y = higher(m, x + 1, r);

	return std::max(a[x] - a[l], a[r] - a[y]);
}


void fillIn(maxn ii, maxn i) {
	maxn len_max = Max(i, ii);

	for (maxk k = 2; k - 1 <= i + 1 && k <= K; k++) {
		maxa fi = std::max(f[i][k - 1], len_max);
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
		std::cout << (pos_re + 1) << '\n';
		pos_re = pos[pos_re][k--];
	}
}


int main() {
	Prepare();

	maxa re = maxA;

	for (maxn i = 0; i < n; i++) {

		f[i][1] = a[i] - a[0];
		pos[i][1] = -1;

		for (maxk k = 2; k <= i + 1 && k <= K; k++) {
			f[i][k] = f[i - 1][k - 1];
			pos[i][k] = i - 1;
		}

		for (maxn j = 0; j < i - 1; j++)
			fillIn(i, j);

		if (i + 1 >= K && re > std::max(f[i][K], a[n - 1] - a[i])) {
			re = std::max(f[i][K], a[n - 1] - a[i]);
			pos_re = i;
		}
	}

	std::cout << re << '\n' << '\n';
	Trace();
}