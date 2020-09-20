#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 252
#define maxA 101
#define maxR 99999999999999999

typedef int maxn;
typedef long long maxa;

maxn n;
maxa f[maxN], sum[maxN], cost[maxN][maxN];


void Prepare() {
	sum[0] = 0;
	for (maxn i = 1; i <= n; i++) {
		std::cin >> f[i];
		sum[i] = sum[i - 1] + f[i];
	}
}


maxa Try(const maxn l, const maxn r) {
	if (l > r) return 0;
	if (cost[l][r] != maxR) return cost[l][r];

	for (maxn i = l; i <= r; i++)
		cost[l][r] = std::min(cost[l][r], (Try(l, i - 1) + (sum[i - 1] - sum[l - 1])) + (Try(i + 1, r) + (sum[r] - sum[i])));
	return cost[l][r];
}


void Process() {
	for (maxn i = 0; i <= n; i++) {
		std::fill(cost[i], cost[i] + n + 1, maxR);
		cost[i][i] = 0;
	}
	std::cout << Try(1, n) << '\n';
}


int main() {
	//freopen("bst.inp", "r", stdin);
	//freopen("bst.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) {
		Prepare();
		Process();
	}
}