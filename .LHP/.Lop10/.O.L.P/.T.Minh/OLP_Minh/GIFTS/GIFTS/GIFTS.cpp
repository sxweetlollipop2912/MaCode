#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

#define maxN 5001
#define maxA 999999999999999999

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN];


void Prepare() {
	n = 0;
	while (std::cin >> a[n]) n++;
	std::sort(a, a + n);
}


bool ifGetGift(maxn x) {
	maxn l = x - 1, r = x + 1;

	while (l >= 0 && r < n) {
		maxa T = a[l] + a[r];
		if (T == 2 * a[x]) return 1;

		if (T > 2 * a[x]) l -= 1;
		else r += 1;
	}

	return 0;
}


void Process() {
	maxn res = 0;
	for (maxn i = 0; i < n; i++) res += ifGetGift(i);
	std::cout << res;
}


int main() {
	freopen("gifts.inp", "r", stdin);
	Prepare();
	Process();
}