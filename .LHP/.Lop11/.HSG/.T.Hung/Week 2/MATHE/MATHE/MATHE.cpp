#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

#define maxN 50001
#define CNT 4
#define maxA 38
#define all 0

typedef int maxn, maxa;
typedef long long maxr;
typedef std::string str;

maxn n, D;
maxr cnt[maxA][maxA][maxA][maxA], f[CNT];
std::vector <maxn> id;


maxa num(char c) {
	if (c > '9') return c - 'a' + 10 + 1;
	return c - '0' + 1;
}


void Prepare() {
	std::cin >> n >> D;

	for (maxn ii = 0; ii < n; ii++) {
		str s; std::cin >> s;
		maxn id[CNT];

		for (int b = 0; b < (1 << CNT); b++) {
			for (int i = 0; i < CNT; i++) id[i] = (b & (1 << i)) ? num(s[i]) : all;
			++cnt[id[0]][id[1]][id[2]][id[3]];
		}
	}
}


void Process() {
	f[0] = n * (n - 1) / 2;
	for (maxn x1 = 0; x1 < maxA - 1; x1++) for (maxn x2 = 0; x2 < maxA - 1; x2++) for (maxn x3 = 0; x3 < maxA - 1; x3++) for (maxn x4 = 0; x4 < maxA - 1; x4++) {
		int same = (x1 != all) + (x2 != all) + (x3 != all) + (x4 != all);
		f[same] += (cnt[x1][x2][x3][x4] * (cnt[x1][x2][x3][x4] - 1)) / 2;
	}
	if (D == 1) std::cout << f[3];
	if (D == 2) std::cout << f[2] - 3 * f[3];
	if (D == 3) std::cout << f[1] - 2 * f[2] + 3 * f[3];
	if (D == 4) std::cout << f[0] - f[1] + f[2] - f[3];
}


int main() {
	//freopen("mathe.inp", "r", stdin);
	//freopen("mathe.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}