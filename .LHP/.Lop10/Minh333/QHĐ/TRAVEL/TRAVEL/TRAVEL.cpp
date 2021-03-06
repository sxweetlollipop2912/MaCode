#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 10001
#define maxP 501
#define maxA 2000001

typedef int maxn, maxp;
typedef long maxa;
typedef long long maxf;

maxf f[maxN];
maxn n, prev[maxN];
maxa a[maxN];
maxp p;


void Prepare() {
	//freopen("TRAVEL.inp", "r", stdin);
	//freopen("TRAVEL.out", "w", stdout);

	std::cin >> n >> p;
}


maxf Sqr(maxf n) {
	return n * n;
}


void Trace() {

	std::cout << prev[n - 1] << '\n' << n << ' ';

	maxn i_cur = n - 1;

	for (maxn i = n - 2; i >= 0; i--)
		if (f[i] + Sqr(a[i_cur] - a[i] - p) == f[i_cur]) {
			std::cout << (i + 1) << ' ';
			i_cur = i;
		}
}


int main() {
	Prepare();

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		f[i] = Sqr(a[i] - p);
		prev[i] = 1;

		for (maxn j = i - 1; j >= 0 && f[i] > 0; j--) {
			maxf ff = Sqr(a[i] - a[j] - p);
			if (ff >= f[i]) break;
			if (f[i] > f[j] + ff) {
				f[i] = f[j] + ff;
				prev[i] = prev[j] + 1;
			}
		}
	}

	std::cout << f[n - 1] << '\n';

	Trace();
}