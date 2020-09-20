#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 501
#define maxK 501
#define maxM 51

typedef int maxn;

maxn n, m, f[maxN][maxK], K, a[maxN];


void Prepare() {
	std::cin >> K >> n >> m;

	for (maxn i = 0; i < m; i++) {
		std::cin >> a[i];
		std::fill(f[i], f[i] + K + 1, maxN + 1);
	}

	std::sort(a, a + m);
}


void Fill(maxn i, maxn k) {
	for (maxn j = i - 1; j >= 0 && j + 1 >= k - 1 && (a[i] - a[j + 1] + 1) < f[i][k]; j--) {
		f[i][k] = std::min(f[i][k], f[j][k - 1] + a[i] - a[j + 1] + 1);
	}
}


int main() {
	//freopen("BANDROLL.inp", "r", stdin);
	//freopen("BANFROLL.out", "W", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	for (maxn i = 0; i < m; i++) {
		f[i][1] = a[i] - a[0] + 1;

		for (maxn k = 2; k <= i + 1 && k <= K; k++) Fill(i, k);
	}

	maxn re = f[m - 1][std::min(K, m)];
	if (re == maxN + 1) std::cout << 0;
	else std::cout << re;
}