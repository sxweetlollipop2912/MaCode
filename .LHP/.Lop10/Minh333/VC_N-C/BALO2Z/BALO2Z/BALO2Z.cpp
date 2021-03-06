#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 50
#define maxW 1000000
#define minW -1000000

typedef int maxn;
typedef int maxa;

maxa a[maxN];
maxn n;
long W, smin, smax, re = minW - 1;

void Prepare() {
	//freopen("BALO2Z.inp", "r", stdin);
	//freopen("BALO2Z.out", "w", stdout);
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] < 0) smin += a[i];
		else smax += a[i];
	}
}

void Try(maxn i, long smin, long smax, bool empty) {

	if (smax == smin) {
		if (empty && smax <= W) re = std::max(re, smax);
		return;
	}
	if (i == n || smin > W) return;

	if (a[i] < 0) {
		Try(i + 1, smin, smax + a[i], 1);
		Try(i + 1, smin - a[i], smax, empty);
	}
	else {
		Try(i + 1, smin + a[i], smax, 1);
		Try(i + 1, smin, smax - a[i], empty);
	}
}

int main() {
	Prepare();
	Try(0, smin, smax, 0);
	std::cout << re;
}