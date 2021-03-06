#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 1001

typedef int maxn;
typedef long maxa;

maxa a[maxN];
maxn n, f[maxN];

void Prepare() {
	//freopen("D.inp", "r", stdin);
	//freopen("D.out", "w", stdout);
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


maxn Max(maxn x) {
	maxn re = 0;
	for (maxn i = x + 1; i < n; i++)
		if (a[i] >= a[x]) re = std::max(re, f[i]);
	return re;
}


int main() {
	Prepare();

	f[n - 1] = 1;
	maxn re = 0;

	for (maxn i = n - 2; i >= 0; i--) {
		f[i] = Max(i) + 1;
		re = std::max(re, f[i]);
	}

	std::cout << re << '\n';

	maxn i = 0;
	while (re > 0) {
		while (f[i] != re) i++;
		std::cout << a[i] << ' ';
		re--;
	}
}