#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 1001
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

typedef int maxn;
typedef long long maxa;

const maxa MOD = 1e9;

maxn m, n, StX, StY, EnX, EnY, f[4][2] = { { 2,-1 },{ 2,1 },{ 1,2 },{ -1,2 } };
maxa cnt[maxN][maxN];


void Prepare() {
	StX = 0, StY = 0;
	std::cin >> m >> n >> EnX >> EnY;
	--EnX, --EnY;
}


void Process() {
	cnt[StX][StY] = 1;

	for (maxn t = 0; t < m + n - 1; t++) for (maxn uj = t - m; uj <= t && uj < n; uj++) {
		maxn ui = t - uj;
		for (maxn k = 0; k < 4; k++) {
			maxn vi = ui + f[k][0], vj = uj + f[k][1];
			if (!valid(vi, vj)) continue;
			cnt[vi][vj] = (cnt[vi][vj] + cnt[ui][uj]) % MOD;
		}
	}

	std::cout << cnt[EnX][EnY];
}


int main() {
	freopen("quanco.inp", "r", stdin);
	freopen("quanco.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}