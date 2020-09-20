#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 42
#define S(x1, y1, x2, y2) (((x2) - (x1) + 1) * ((y2) - (y1) + 1))
#define Sum(x1, y1, x2, y2) (sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1])
#define valid(x1, y1, x2, y2) (Sum(x1, y1, x2, y2) == S(x1, y1, x2, y2) || !Sum(x1, y1, x2, y2))

typedef int maxn;

maxn m, n, sum[maxN][maxN], f[maxN][maxN][maxN][maxN];
bool a[maxN][maxN];


void Prepare() {
	std::cin >> m >> n;

	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++)
		std::cin >> a[i][j], sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
}


maxn DP(const maxn x1, const maxn y1, const maxn x2, const maxn y2) {
	if (f[x1][y1][x2][y2] || (f[x1][y1][x2][y2] = valid(x1, y1, x2, y2))) return f[x1][y1][x2][y2];
	f[x1][y1][x2][y2] = S(x1, y1, x2, y2);

	for (maxn m = x1; m < x2; m++) f[x1][y1][x2][y2] = std::min(f[x1][y1][x2][y2], DP(x1, y1, m, y2) + DP(m + 1, y1, x2, y2));
	for (maxn m = y1; m < y2; m++) f[x1][y1][x2][y2] = std::min(f[x1][y1][x2][y2], DP(x1, y1, x2, m) + DP(x1, m + 1, x2, y2));

	return f[x1][y1][x2][y2];
}


void Process() {
	std::cout << DP(1, 1, m, n);
}


int main() {
	//freopen("rectangle.inp", "r", stdin);
	//freopen("rectangle.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}