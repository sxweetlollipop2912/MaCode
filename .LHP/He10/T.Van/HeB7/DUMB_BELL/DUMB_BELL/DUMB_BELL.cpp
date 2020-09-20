#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 11
#define maxW 101
#define maxT 6
#define maxR 99999

typedef int maxn, maxa;

maxn n, res;
maxa a[maxN], ta[maxT] = { 1,2,5,10,15,20 }, W;


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
	a[0] = 0;
	std::cin >> W;
}


maxn MinT(maxa w) {
	if (w < 0) return maxR;

	maxn re = 0, i = maxT;
	while (w) {
		--i;
		re += w / ta[i], w %= ta[i];
	}
	return re;
}


void Process() {
	res = maxR;
	maxa sum = 0;
	for (maxn i = 0; i <= n; i++) {
		sum += a[i];
		res = std::min(res, MinT(W - sum) + n - i);
	}
	std::cout << res;
}


int main() {
	//freopen("dumb_bell.inp", "r", stdin);
	//freopen("dumb_bell.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}