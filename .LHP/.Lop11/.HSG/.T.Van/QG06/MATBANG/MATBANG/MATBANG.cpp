#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 1003
#define maxA 10001
#define minA -10001

typedef long maxn;
typedef int maxa;

maxn m, n, H, L, mxh[maxN][maxN], res;
bool a[maxN][maxN];


void Prepare() {
	std::cin >> m >> n >> H >> L;

	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) {
		maxa x; scanf("%d", &x);
		a[i][j] = abs(H - x) <= L;
	}
}


void Process() {
	res = 0;

	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++)
		mxh[i][j] = a[i][j] ? mxh[i][j] = mxh[i - 1][j] + 1 : 0;

	for (maxn i = 1; i <= m; i++) {
		std::vector <maxn> de;
		mxh[i][0] = minA - 2, mxh[i][n + 1] = minA - 1; de.push_back(0);

		for (maxn j = 1; j <= n + 1; j++) {
			while (mxh[i][de.back()] >= mxh[i][j]) {
				maxn idx = de.back(); de.pop_back();
				res = std::max(res, (j - de.back() - 1) * mxh[i][idx]);
			}
			de.push_back(j);
		}
	}

	std::cout << res;
}


int main() {
	//freopen("matbang.inp", "r", stdin);
	//freopen("matbang.out", "w", stdout);

	//std::ios_base::sync_with_stdio(0);
	//std::cin.tie(0);

	Prepare();
	Process();
}