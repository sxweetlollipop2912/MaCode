// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 14
#define maxA 3601
#define MAX_TIME 280
#define LIM(n) ((n + 1) / 2)
#define F 3

typedef int maxn, maxa;

maxn n, res;
maxa a[F][maxN], f[maxN][maxN][maxN];


void Prepare() {
	std::cin >> n;
	for (int fr = 0; fr < F; fr++) for (maxn i = 0; i < n; i++) std::cin >> a[fr][i];
}


void Process() {
	for (maxn i = 0; i <= n; i++) for (maxn j = 0; j <= n; j++) std::fill(f[i][j], f[i][j] + n + 1, maxA);

	f[0][0][0] = 0, res = 0;
	for(maxn p = 0; p < n; p++) for (maxn i = std::min(LIM(n), p); i >= 0; i--) for (maxn j = std::min(LIM(n), p); j >= 0; j--) for(maxn k = std::min(LIM(n), p); k >= 0; k--) {
		if (i + j + k > p) continue;
		maxn t = i + j + k + 1;

		f[i + 1][j][k] = std::min(f[i + 1][j][k], f[i][j][k] + a[0][p]);
		if ((i + 1) <= LIM(t) && j <= LIM(t) && k <= LIM(t) && f[i + 1][j][k] <= MAX_TIME) res = std::max(res, t);
		f[i][j + 1][k] = std::min(f[i][j + 1][k], f[i][j][k] + a[1][p]);
		if (i <= LIM(t) && (j + 1) <= LIM(t) && k <= LIM(t) && f[i][j + 1][k] <= MAX_TIME) res = std::max(res, t);
		f[i][j][k + 1] = std::min(f[i][j][k + 1], f[i][j][k] + a[2][p]);
		if (i <= LIM(t) && j <= LIM(t) && (k + 1) <= LIM(t) && f[i][j][k + 1] <= MAX_TIME) res = std::max(res, t);
	}

	std::cout << res << '\n';
}


int main() {
	//freopen("1240.inp", "r", stdin);
	//freopen("1240.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;

	while (t--) {
		Prepare();
		Process();
	}
}