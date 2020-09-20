#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 1001
#define maxA 101
#define maxR 1000001

typedef long maxn, maxa, maxr;

maxn n;
maxa a[maxN], limax, limin, T;
maxr res = maxR;


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		limax = std::max(limax, a[i]);
		limin = std::min(limin, a[i]);
	}
}


maxr cal(maxa t) {
	maxr re = 0;
	for (maxn i = 0; i < n; i++) 
		re += std::min(abs(a[i] - t), std::min(abs(a[i] - (t + 1)), ((t < 1) * maxR) + abs(a[i] - (t - 1))));

	return re;
}


void Process() {
	limin = std::max(limin, (long)2);

	for (maxa t = limin - 1; t <= limax + 1; t++) {
		maxr tmp = cal(t);
		if (res > tmp) {
			T = t;
			res = tmp;
		}
	}
}


int main() {
	Prepare();
	Process();
	std::cout << T << ' ' << res;
}