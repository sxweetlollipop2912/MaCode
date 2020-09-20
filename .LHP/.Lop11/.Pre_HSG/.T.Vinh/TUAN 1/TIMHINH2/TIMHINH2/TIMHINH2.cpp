#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 602
#define maxK 2
#define B 0
#define W 1

typedef long long maxn;

maxn n, sum[maxN][maxN], res_size, res_cnt;
bool a[maxN][maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= n; j++) {
			std::cin >> a[i][j];
			a[i][j] = !a[i][j];
			sum[i][j] = sum[i - 1][j] - sum[i - 1][j - 1] + sum[i][j - 1] + a[i][j];
		}
	}
}


maxn Sum(const maxn x1, const maxn y1, const maxn x2, const maxn y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}


maxn BS_ul(const maxn x1, const maxn y1) {
	maxn l = 1, r = std::min(n - x1 + 1, n - y1 + 1);

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (Sum(x1, y1, x1 + m - 1, y1) + Sum(x1, y1, x1, y1 + m - 1) - a[x1][y1] > maxK) r = m - 1;
		else l = m;
	}

	return l;
}

maxn BS_ur(const maxn x1, const maxn y1) {
	maxn l = 1, r = std::min(n - x1 + 1, y1);

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (Sum(x1, y1, x1 + m - 1, y1) + Sum(x1, y1 - m + 1, x1, y1) - a[x1][y1] > maxK) r = m - 1;
		else l = m;
	}

	return l;
}

maxn BS_dl(const maxn x1, const maxn y1) {
	maxn l = 1, r = std::min(x1, n - y1 + 1);

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (Sum(x1 - m + 1, y1, x1, y1) + Sum(x1, y1, x1, y1 + m - 1) - a[x1][y1] > maxK) r = m - 1;
		else l = m;
	}

	return l;
}

maxn BS_dr(const maxn x1, const maxn y1) {
	maxn l = 1, r = std::min(x1, y1);

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (Sum(x1 - m + 1, y1, x1, y1) + Sum(x1, y1 - m + 1, x1, y1) - a[x1][y1] > maxK) r = m - 1;
		else l = m;
	}

	return l;
}


void Process() {
	res_size = res_cnt = 0;

	for (maxn i = 1; i <= n; i++) {
		for (maxn j = 1; j <= n; j++) {
			maxn size = BS_ul(i, j);
			if (size == res_size) ++res_cnt;
			else if (size > res_size) res_size = size, res_cnt = 1;

			size = BS_ur(i, j);
			if (size == res_size) ++res_cnt;
			else if (size > res_size) res_size = size, res_cnt = 1;

			size = BS_dl(i, j);
			if (size == res_size) ++res_cnt;
			else if (size > res_size) res_size = size, res_cnt = 1;

			size = BS_dr(i, j);
			if (size == res_size) ++res_cnt;
			else if (size > res_size) res_size = size, res_cnt = 1;
		}
	}

	std::cout << res_size * res_cnt;
}


int main() {
	//freopen("timhinh2.inp", "r", stdin);
	//freopen("timhinh2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}