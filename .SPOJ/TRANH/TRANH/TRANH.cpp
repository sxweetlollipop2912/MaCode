#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 53
#define maxA 2503
#define full 0
#define took 1

typedef int maxn, maxa;

maxn n, M;
maxa d[maxN], v[maxN][maxN], f[maxN][maxN][2];


void Prepare() {
	std::cin >> n >> M;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= M; j++) {
			std::cin >> v[i][j];
		}
	}
}


void Process() {
	for (maxn m = 1; m <= M; m++) {
		for (maxn i = 1; i <= n; i++) {
			if (m >= i) {
				f[m][i][full] = std::max(f[m - 1][i][full], v[i][m] + f[m - 1][i - 1][full]);
			}
			if (i > 1 && m + 1 >= i) {
				f[m][i][took] = std::max(f[m - 1][i][took], v[i][m] + f[m - 1][i - 2][full] + d[i - 1]);
			}
		}
	}

	std::cout << std::max(f[M][n][took], f[M][n - 1][full] + d[n]);
}


int main() {
	Prepare();
	Process();
}