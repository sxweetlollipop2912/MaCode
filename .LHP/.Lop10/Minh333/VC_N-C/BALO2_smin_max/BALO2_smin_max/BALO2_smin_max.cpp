#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 50
#define maxW 50000
#define minW -50000

typedef int maxn;
typedef int maxa;

maxa a[maxN];
maxn n;
long long W, smin, smax, re = minW - 1;

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] < 0) smin += a[i];
		else smax += a[i];
	}
}

void Try(maxn i, long long smin, long long smax) {

	if (smax == smin) {
		if (smax <= W) re = std::max(re, smax);
		return;
	}
	if (i == n || smin > W) return;

	if (a[i] < 0) {
		Try(i + 1, smin, smax + a[i]);
		Try(i + 1, smin - a[i], smax);
	}
	else {
		Try(i + 1, smin + a[i], smax);
		Try(i + 1, smin, smax - a[i]);
	}
}

int main() {
	Prepare();
	Try(0, smin, smax);
	std::cout << re;
}