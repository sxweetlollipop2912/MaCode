#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#pragma warning(disable:4996)

#define maxN 5001
#define maxA 1001

typedef int maxn, maxa;

maxn n, k, id[maxN], f[maxN], len_r;
maxa a[maxN];


bool cmp(const maxn &x, const maxn &y) {
	return a[x] > a[y];
}

void Prepare() {
	std::cin >> n >> k;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}

	std::sort(id, id + n, cmp);
}


void Set() {
	for (maxn i = 0; i < n; i++) {
		a[id[i]] = ceil((i + 1) / (double)(k));
	}
}


void Process() {
	f[0] = 1;
	for (maxn i = 1; i < n; i++) {
		for (maxn j = i; j >= 0; j--) {
			if (a[j] > a[i]) continue;

			f[i] = std::max(f[i], f[j] + 1);
			len_r = std::max(len_r, f[i]);
		}
	}

	std::cout << n - len_r;
}


int main() {
	freopen("aprobot.inp", "r", stdin);
	freopen("aprobot.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Set();
	Process();
}