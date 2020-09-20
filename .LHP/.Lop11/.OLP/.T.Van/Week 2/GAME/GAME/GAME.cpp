#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1002
#define S(l, r) (sum[r] - sum[l - 1])

typedef int maxn;
typedef long maxa;

maxn n;
maxa a[maxN], sum[maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
}


void Process() {
	for (maxn i = 1; i <= n; i++) f[i][i] = a[i];

	for (maxn len = 2; len <= n; len++) for(maxn l = 1; l <= n - len + 1; l++) {
		maxn r = l + len - 1;
		f[l][r] = std::min(a[l] + S(l + 1, r) - f[l + 1][r], a[r] + S(l, r - 1) - f[l][r - 1]);
	}

	std::cout << f[1][n] << ' ' << S(1, n) - f[1][n];
}


int main() {
	freopen("game.inp", "r", stdin);
	freopen("game.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}