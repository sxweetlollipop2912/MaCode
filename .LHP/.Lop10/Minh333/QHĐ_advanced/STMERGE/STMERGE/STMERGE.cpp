#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1002
#define maxMN 3
#define maxA 1000000001
#define maxR 1000000000001

typedef int maxn;
typedef long long maxa;

maxn nx, ny;
maxa c[maxN][maxN], fx[maxMN][maxN], fy[maxMN][maxN];


void Prepare() {
	std::cin >> nx >> ny;

	for (maxn i = 1; i <= nx; i++) {
		for (maxn j = 1; j <= ny; j++) {
			std::cin >> c[i][j];
		}
	}
}


void Process() {
	bool p = 0;
	std::fill(fx[p], fx[p] + nx + 1, maxR);
	std::fill(fy[p], fy[p] + ny + 1, maxR);

	fx[p][1] = fy[p][1] = 0;

	for (maxn i = 2; i <= nx + ny; i++) {
		p = !p;
		std::fill(fx[p], fx[p] + nx + 1, maxR);

		for (maxn j = 1; j <= nx; j++) {
			maxn m = i - j;
			if (m < 0) break;

			fx[p][j] = std::min(fx[!p][j - 1], fy[!p][m] + c[j][m]);
			//std::cout << i << ' ' << j << ' ' << m << ' ' << c[j][m] << ' ' << fx[i][j] << '\n';
		}

		std::fill(fy[p], fy[p] + ny + 1, maxR);

		for (maxn j = 1; j <= ny; j++) {
			maxn m = i - j;
			if (m < 0) break;

			fy[p][j] = std::min(fy[!p][j - 1], fx[!p][m] + c[m][j]);
		}
	}

	std::cout << std::min(fx[p][nx], fy[p][ny]) << '\n';
}


int main() {
	//freopen("stmerge.inp", "r", stdin);
	//freopen("stmerge.out","w",stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long long q = 0;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}
