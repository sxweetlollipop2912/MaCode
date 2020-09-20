#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1003
#define valid(x) ((x) == opt || (x) == opt + 1)

typedef long maxn;
typedef int maxa;

maxn m, n, f[maxN][maxN], mxl[maxN][maxN], mxh[maxN][maxN];
maxa a[maxN][maxN];


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) std::cin >> a[i][j];
}


void Pre_process(const bool opt) {
	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) 
		mxh[i][j] = valid(a[i][j]) ? mxh[i][j] = mxh[i - 1][j] + 1 : 0, mxl[i][j] = 0;

	for (maxn i = 1; i <= m; i++) {
		std::vector <maxn> de; 
		mxh[i][0] = -2, mxh[i][n + 1] = -1; de.push_back(0);

		for (maxn j = 1; j <= n + 1; j++) {
			while (mxh[i][de.back()] >= mxh[i][j]) {
				maxn idx = de.back(); de.pop_back();
				mxl[i][mxh[i][idx]] = std::max(mxl[i][mxh[i][idx]], j - de.back() - 1);
			}
			de.push_back(j);
		}

		for (maxn j = i - 1; j >= 1; j--) mxl[i][j] = std::max(mxl[i][j], mxl[i][j + 1]);
	}
}


void Process() {
	Pre_process(0);
	for (maxn h = 1; h <= m; h++) for (maxn l = 1; l <= m - h + 1; l++) {
		maxn r = l + h - 1;
		f[l][r] = std::max(f[l][r], mxl[r][h] * h);
		f[l][r] = std::max(f[l][r], std::max(f[l][r - 1], f[l + 1][r]));
	}

	Pre_process(1);
	for (maxn h = 1; h <= m; h++) for (maxn l = 1; l <= m - h + 1; l++) {
		maxn r = l + h - 1;
		f[l][r] = std::max(f[l][r], mxl[r][h] * h);
		f[l][r] = std::max(f[l][r], std::max(f[l][r - 1], f[l + 1][r]));
	}
	
	long q; std::cin >> q;
	while (q--) {
		maxn l, r; std::cin >> l >> r;
		std::cout << f[l][r] << '\n';
	}
}


int main() {
	//freopen("numtab.inp", "r", stdin);
	//freopen("numtab.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}