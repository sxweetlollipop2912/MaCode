// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#pragma warning(disable:4996)

#define maxN 202
#define maxD 21

typedef long long maxn, maxa, maxr;

maxn n, m;
int q;
maxa a[maxN], D;
maxr f[maxN][maxN][maxD];


void Prepare() {
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
	std::cin >> D >> m;
	for (maxn i = 0; i <= n; i++) for (maxn j = 0; j <= m; j++) std::fill(f[i][j], f[i][j] + D, 0);
	f[0][0][0] = 1;
	for (maxn i = 1; i <= n; i++) for (maxn len = 0; len < std::min(i, m + 1); len++) for (maxn d = 0; d < D; d++) {
		f[i][len][d] += f[i - 1][len][d];
		f[i][len + 1][(((d + a[i]) % D) + D) % D] += f[i - 1][len][d];
	}
	std::cout << f[n][m][0] << '\n';
}


int main() {
	//freopen("10616.inp", "r", stdin);
	//freopen("10616.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntt = 0;
	while (std::cin >> n >> q && n) {
		std::cout << "SET " << ++cntt << ":\n";
		Prepare();
		int cntq = 0;
		while (q--) {
			std::cout << "QUERY " << ++cntq << ": ";
			Process();
		}
	}
}