#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 402
#define minR -160000000001

typedef int maxn;
typedef long long maxa;

maxn m, n;
maxa a[maxN][maxN], mx[maxN][maxN], res;


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) for (maxn j = 1; j <= n; j++) std::cin >> a[i][j], a[i][j] += a[i][j - 1];
}


void Process() {
	for (maxn i = 1; i <= n; i++) std::fill(mx[i], mx[i] + n + 1, minR);
	res = minR;

	for (maxn r = 0; r < m; r++) for(maxn i = 1; i <= n; i++) for(maxn j = i; j <= n; j++) {
		mx[i][j] = std::max(mx[i][j] + a[r][j] - a[r][i - 1], a[r][j] - a[r][i - 1]);
		res = std::max(res, mx[i][j]);
	}

	std::cout << res;
}


int main() {
	//freopen("max2d.inp", "r", stdin);
	//freopen("max2d.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}