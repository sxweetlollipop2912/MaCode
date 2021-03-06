// strictly greater _ AC SPOJ _ O(nlogn)
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable: 4996)

#define maxN 1002
#define maxA 100001 // 10^5

typedef int maxn, maxa;

maxa a, f[maxN];
maxn n, re;

void Prepare() {
	//freopen("DAYDONDIEU.inp", "r", stdin);
	//freopen("DAYDONDIEU.out", "w", stdout);

	std::ios_base::sync_with_stdio(false);
	std::cin >> n;

	std::fill(f, f + n + 1, maxA + 1);
	std::cin >> f[1];
}

void find(maxa a) {
	maxn l = 1, r = n;
	while (l < r) {
		maxn m = (l + r) / 2;
		if (f[m] < a) l = m + 1;
		else r = m;
	}
	if (f[l] < a) return;
	f[l] = a;
	re = std::max(re, l);
}


int main() {
	Prepare();

	for (int i = 1; i < n; i++) {
		std::cin >> a;
		find(a);
	}

	std::cout << re;
}