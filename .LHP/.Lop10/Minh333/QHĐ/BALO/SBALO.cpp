#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1001
#define maxW 10001
#define maxA 1001

typedef long maxn;
typedef long maxa;

maxn n, W;
maxa a[maxN], g[maxN], f[maxN][maxW];


void Prepare() {
	freopen("SBALO.inp", "r", stdin);
	freopen("SBALO.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> W;
	for (maxn i = 0; i < n; i++) std::cin >> a[i] >> g[i];
}


bool find(maxa x, maxn ii, maxn r) {
	maxn l = 0;
	if (l > r) return false;

	while (l < r) {
		maxn m = (l + r) / 2;
		if (f[ii][m] < x) l = m + 1;
		else r = m;
	}

	return f[ii][l] == x;
}


int main() {
	Prepare();

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= W; j++) {
			if (a[i - 1] <= j) f[i][j] = std::max(f[i - 1][j - a[i - 1]] + g[i - 1], f[i - 1][j]);
			else f[i][j] = f[i - 1][j];
		}
	}

	std::cout << f[n][W] << '\n';

	maxa x = f[n][W];
	maxn w = W;
	for (maxn i = n; i > 0; i--) {
		if (!find(x - g[i - 1], i - 1, w - a[i - 1])) continue;
		std::cout << i << ' ';
		x -= g[i - 1];
		w -= a[i - 1];
	}
}
