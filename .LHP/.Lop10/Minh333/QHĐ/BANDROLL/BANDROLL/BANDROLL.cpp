#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 501
#define maxK 501
#define maxM 51

typedef int maxn, maxk;

maxn n, m, f[maxN][maxK];
maxk K;
maxn a[maxN];


void Prepare() {
	//freopen("BANDROLL.inp", "r", stdin);
	//freopen("BANFROLL.out", "W", stdout);

	std::cin >> K >> n >> m;

	for (maxn i = 0; i < m; i++) {
		std::cin >> a[i];
		std::fill(f[i], f[i] + K + 1, maxN + 1);
	}

	std::sort(a, a + m);
}



maxn Result(maxn i, maxn j, maxk k) {  // j < i - 1 && k -> i
	return f[j][k - 1] + a[i] - a[j + 1] + 1;
}


void Fill(maxn i, maxk k) {

	for (maxn j = i - 1; j >= 0 && j + 1 >= k - 1 && (a[i] - a[j + 1] + 1) < f[i][k]; j--) {
		f[i][k] = std::min(f[i][k], Result(i, j, k));
	}
}


int main() {
	Prepare();

	for (maxn i = 0; i < m; i++) {
		f[i][1] = a[i] - a[0] + 1;

		for (maxk k = 2; k <= i + 1 && k <= K; k++) Fill(i, k);
	}

	maxn re = f[m - 1][std::min(K, m)];
	if (re == maxN + 1) std::cout << 0;
	else std::cout << re;
}