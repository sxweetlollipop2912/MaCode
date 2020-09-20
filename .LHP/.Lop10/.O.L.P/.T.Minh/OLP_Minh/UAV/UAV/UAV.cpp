#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

#define maxL 100
#define maxN 500001
#define maxA 106
#define maxR maxN*maxA

typedef long maxn;
typedef long long maxa;

maxn L, n;
maxa a[maxN], f[maxN];


void Prepare() {
	std::cin >> L >> n;
	L = std::min(L, n - 1);

	for (maxn i = 1; i < n - 1; i++) std::cin >> a[i];
	a[0] = 1000;
	a[n - 1] = 1001;
}


void Process_1() {
	maxn res = 1, cur = 0;

	while (cur != n - 1) {
		maxn i;
		for (i = std::min(n - 1, cur + L); i > cur && a[i] % 2 == 0; i--);
		cur = i;
		res++;
	}

	std::cout << res << ' ';
}


void Process_2() {
	f[n - 1] = a[n - 1];
	maxa mx = f[n - 1];

	for (maxn i = n - 2; i > n - 1 - L; i--) {
		if (a[i] % 2 != 0) continue;
		f[i] = mx - a[i];
		mx = std::max(mx, f[i]);
	}

	for (maxn i = n - 1 - L; i >= 0; i--) {
		if (a[i] % 2 != 0) continue;
		f[i] = std::max(f[i + L] + a[i], mx - a[i]);
		mx = std::max(mx, f[i]);
	}

	std::cout << f[0];
}


int main() {
	//freopen("uav.inp", "r", stdin);
	//freopen("uav.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process_1();
	Process_2();
}
