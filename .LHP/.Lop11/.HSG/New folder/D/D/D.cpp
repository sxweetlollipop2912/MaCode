#include <iostream>
#include <algorithm>
#include <iomanip>

#define maxN 101
#define N 100

typedef long maxn;

maxn n, g[maxN][maxN], res;


void Prepare() {
	for (maxn i = 0; i < N; i++) {
		std::fill(g[i], g[i] + N, maxN);
		g[i][i] = 0;
	}
	maxn u, v; n = 0;
	while (std::cin >> u >> v && u && v) g[u - 1][v - 1] = 1, n = std::max(n, std::max(u, v));
}


void Process() {
	for (maxn k = 0; k < n; k++) for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
	res = 0;
	for (maxn i = 0; i < n; i++) for (maxn j = i + 1; j < n; j++) res += g[i][j] + g[j][i];
	
	std::cout << std::fixed; std::cout << std::setprecision(3);
	std::cout << res / (double)(n * (n - 1)) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}