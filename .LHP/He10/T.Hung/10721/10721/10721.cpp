// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 52

typedef int maxn;
typedef long long maxr;

maxn N, K, M;
maxr f[maxN][maxN];


void Process() {
	for (maxn i = 0; i <= N; i++) std::fill(f[i], f[i] + N + 1, 0);
	f[0][0] = 1;

	for (maxn i = 1; i <= N; i++) {
		for (maxn k = 1; k <= K; k++) {
			if (i < k) break;
			for (maxn m = 1; m <= M; m++) {
				if (i - m < 0) break;
				f[i][k] += f[i - m][k - 1];
			}
		}
		//std::cout << f[i][1] << '\n';
	}

	std::cout << f[N][K] << '\n';
}


int main() {
	//freopen("10721.inp", "r", stdin);
	//freopen("10721.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> N >> K >> M) Process();
}