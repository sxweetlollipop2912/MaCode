#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 1000001
#define maxA 10001

typedef long maxn;
typedef int maxa;
typedef unsigned long maxf;

maxf f[maxN];
maxn n;


void Prepare() {
	//freopen("XOASOF.inp", "r", stdin);
	//freopen("XOASOF.out", "w", stdout);

	std::ios_base::sync_with_stdio(false);

	std::cin >> n;
}


void Trace() {
	maxn i = n + 1;

	while (i > 3) {
		i = std::min_element(f + i - 3, f + i) - f;
		std::cout << i << ' ';
	}
}


int main() {
	Prepare();

	if (n == 0) {
		std::cout << "0\n" << "0 0";
		return 0;
	}

	f[0] = 0;
	std::cin >> f[1] >> f[2] >> f[3];

	for (maxn i = 4; i <= n; i++) {
		std::cin >> f[i];
		f[i]+= *std::min_element(f + i - 3, f + i);
	}

	std::cout << *std::min_element(f + n - 2, f + n + 1) << '\n';

	Trace();
}