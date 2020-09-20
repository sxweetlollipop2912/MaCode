#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 10001
#define maxK 102
#define maxA 10001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], K;
bool f[2][maxK], p = 0;


void Prepare() {
	std::cin >> n >> K;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	std::fill(f[0], f[0] + K + 1, 0);
	std::fill(f[1], f[1] + K + 1, 0);
	f[p][a[0] % K] = 1;

	for (maxn i = 1; i < n; i++) {
		maxa mod = a[i] % K;
		p = !p;
		for (maxa k = 0; k <= K; k++) {
			if (!f[!p][k]) continue;
			f[p][(k + mod) % K] = f[p][(k - mod) % K] = 1;
		}
	}

	if (f[p][0]) std::cout << "Yes\n";
	else std::cout << "No\n";
}


int main() {
	//freopen("chiahet.inp", "r", stdin);
	//freopen("chiahet.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}