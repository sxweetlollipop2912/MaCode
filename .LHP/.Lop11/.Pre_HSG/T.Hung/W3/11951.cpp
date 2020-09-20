// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102
#define maxK 1000000001
#define area(l, r, u, d) (((r) - (l) + 1) * ((d) - (u) + 1))

typedef int maxn;
typedef long long maxa;

maxn row, col, res;
maxa K, P[maxN][maxN], res_cost;


void Prepare() {
	std::cin >> row >> col >> K;

	for (maxn i = 1; i <= row; i++)
		for (maxn j = 1; j <= col; j++)
			std::cin >> P[i][j], P[i][j] += P[i][j - 1];
}


void Try(const maxn l, const maxn r) {
	maxa sum = 0;
	maxn u = 1, d = 0;

	while (d < row) {
		++d, sum += P[d][r] - P[d][l - 1];
		while (sum > K) sum -= (P[u][r] - P[u][l - 1]), ++u;

		if (area(l, r, u, d) == res) res_cost = std::min(res_cost, sum);
		else if (area(l, r, u, d) > res) res = area(l, r, u, d), res_cost = sum;
		//std::cout << l << ' ' << r << ' ' << u << ' ' << d << ' ' << P[u][l - 1] << ' ' << area(l, r, u, d) << '\n';
	}
}


void Process() {
	res = 0;
	for (maxn l = 1; l <= col; l++) for (maxn r = l; r <= col; r++) Try(l, r);
	std::cout << res << ' ' << res_cost << '\n';
}


int main() {
	freopen("11951.inp", "r", stdin);
	freopen("11951.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int q;
	std::cin >> q;

	for (int cntq = 1; cntq <= q; cntq++) {
		std::cout << "Case #" << cntq << ": ";
		Prepare();
		Process();
	}
}