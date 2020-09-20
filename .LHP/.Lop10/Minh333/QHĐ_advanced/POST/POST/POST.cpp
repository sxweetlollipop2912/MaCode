#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 301
#define maxK 32
#define maxA 99999999

typedef int maxn, maxk;
typedef long maxa;

maxn n, pos[maxN][maxK], pos_res;
maxk K;
maxa a[maxN], f[maxN][maxK], d[maxN][maxN], res;


void Prepare() {
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


maxn Sum(maxn l, maxn r) { // l + 1 < r
	maxn m = (a[l] + a[r]) / 2;
	return lower(m, l, r);
}


void fillIn(maxn ii, maxn i) { // i > ii
	maxa len_sum = Sum(ii, i);
	len_sum = d[ii][len_sum] + d[i][len_sum + 1];

	for (maxk k = 2; k - 1 <= n - i && k <= K; k++) {

		maxa fi = f[i][k - 1] + len_sum;

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

		std::cout << a[pos_res] << ' ';
		pos_res = pos[pos_res][k--];
	}
}


void GetReady() {
	for (maxn i = 0; i < n; i++) {
		d[i][i] = 0;

		for (maxn j = i + 1; j < n; j++) 
			d[i][j] = a[j] - a[i] + d[i][j - 1];

		for (maxn j = i - 1; j >= 0; j--) 
			d[i][j] = a[i] - a[j] + d[i][j + 1];
	}
	//std::cout << d[0][n - 1] << '\n';
}


void Process() {
	res = maxA;

	for (maxn i = n - 1; i >= 0; i--) {

		f[i][1] = d[i][n - 1];
		pos[i][1] = n;

		for (maxk k = 2; k <= n - i && k <= K; k++) {
			f[i][k] = f[i + 1][k - 1];
			pos[i][k] = i + 1;
		}

		for (maxn j = i + 2; j < n; j++)
			fillIn(i, j);

		if (n - i >= K && res > f[i][K] + d[i][0]) {
			//std::cout << re << '\n';
			res = f[i][K] + d[i][0];
			pos_res = i;
		}
	}
}


int main() {
	//freopen("post.inp", "r", stdin);
	//freopen("post.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	GetReady();
	Process();

	std::cout << res << '\n';
	Trace();
}