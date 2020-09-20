#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 20001
#define maxA 1002

typedef int maxn, maxa;

maxn n, cntl[maxA], cntr[maxA], len, res;
maxa a[maxN], M;


void Prepare() {
	std::cin >> M >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	cntr[0] = cntl[0] = 1;
}


bool Check() {
	maxa l = M, r = M;
	maxn cl = cntl[l], cr = cntr[r];

	while (l != 0 && r != 0) {
		while (!cl) cl = cntl[--l];
		while (!cr) cr = cntr[--r];
		if (l && r <= l) return 0;

		maxn pair = std::min(cl, cr);
		cr -= pair; cl -= pair;
	}

	return (res = len);
}


void Process() {
	res = 0; len = 1;
	cntl[a[0]] = cntr[a[1]] = 1;
	Check();

	for (len = 2; len <= n / 2; len++) {
		++cntl[a[len - 1]]; --cntr[a[len - 1]];
		++cntr[a[2 * len - 2]];
		++cntr[a[2 * len - 1]];
		Check();
	}

	std::cout << res;
}


int main() {
	//freopen("xepthung.inp", "r", stdin);
	//freopen("xepthung.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}