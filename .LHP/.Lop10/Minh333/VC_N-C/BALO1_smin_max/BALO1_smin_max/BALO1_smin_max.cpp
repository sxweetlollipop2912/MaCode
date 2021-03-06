#include "pch.h"
#include <iostream>

#define max 51
typedef int maxn;
typedef int maxa;

maxa a[max];
maxn n;
long long W, smin, smax, re;

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] < 0) smin += a[i];
		else smax += a[i];
	}
}

void Try(maxn i, long long smin, long long smax, bool count) {
	
	if (smax == smin) {
		if (count && smax == W) re++;
		return;
	}
	if (i == n || smin > W || smax < W) return;

	if (a[i] < 0) {
		Try(i + 1, smin, smax + a[i], 1);
		Try(i + 1, smin - a[i], smax, count);
	}
	else {
		Try(i + 1, smin + a[i], smax, 1);
		Try(i + 1, smin, smax - a[i], count);
	}
}

int main() {
	Prepare();
	Try(0, smin, smax, 0);
	std::cout << re;
}