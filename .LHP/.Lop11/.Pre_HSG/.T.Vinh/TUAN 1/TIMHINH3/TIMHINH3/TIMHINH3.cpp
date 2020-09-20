#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1401
#define maxA (maxa)100
#define maxT 140001
#define maxK 1000000

typedef int maxn;
typedef long long maxa;

maxn n, res_size, res_cnt;
maxa K, sum[maxN][maxN];


void Prepare() {
	std::cin >> n >> K;

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= n; j++) {
			std::cin >> sum[i][j];
			sum[i][j] += sum[i - 1][j] - sum[i - 1][j - 1] + sum[i][j - 1];
		}
	}
}


maxa Sum(const maxn x1, const maxn y1, const maxn x2, const maxn y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}


maxn Max(const maxn x, const maxn y) {
	for (maxn l = std::min(n - x + 1, n - y + 1); l >= 1; l--) {
		maxa s = Sum(x, y, x + l - 1, y + l - 1);
		if (s < K) break;
		if (s % K == 0) return l;
	}
	return 0;
}


void Process() {
	res_size = res_cnt = 0;

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= n; j++) {
			maxn l = Max(i, j);
			if (res_size == l) ++res_cnt;
			else if (res_size < l) res_size = l, res_cnt = 1;
		}
	}

	std::cout << res_size * res_cnt;
}


int main() {
	//freopen("timhinh3.inp", "r", stdin);
	//freopen("timhinh3.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}