#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxN 103

typedef int maxn;
typedef long maxa;

maxn n, K;
maxa f[maxN][maxN][maxN];
std::vector <maxn> res;


void Prepare() {
	std::cin >> n >> K;
}


bool DFS(const maxn u, const maxn k, const maxn S, const maxa T) {
	if (u != 0) res.push_back(u);
	if (S == 0) return 1;

	if (k != 0 && f[S][u][k] >= T)
		return DFS(u, k - 1, S - u, T);

	maxn s = k != 0 ? f[S][u][k] : 0;
	for (maxn v = u + 1; v <= S; v++) {
		if (f[S][v][K] >= T - s) return DFS(v, K - 1, S - v, T - s);
		s += f[S][v][K];
	}
	return 0;
}


void Process() {
	for (maxn j = 0; j <= n + 1; j++) std::fill(f[0][j], f[0][j] + maxN, 1);

	//f[i][j][0]: sl cac day tong i có phan tu >= j
	//f[i][j][k]: sl các day tong i có phan tu >= j, bat dau bang 1 -> k phan tu j
	for (maxn i = 1; i <= n; i++) for (maxn j = i; j >= 1; j--) {
		f[i][j][0] = f[i][j + 1][0];
		for (maxn k = 1; k <= K; k++) {
			f[i][j][k] = k - 1 != 0 ? f[i][j][k - 1] : 0;
			if (j * k <= i) {
				f[i][j][0] += f[i - (j * k)][j + 1][0];
				f[i][j][k] += f[i - (j * k)][j + 1][0];
			}
		}
	}
	/*for (maxn i = n; i >= 1; i--) for (maxn j = 1; j <= i; j++) {
		for (maxn k = 1; k <= K && j * k <= i; k++) std::cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
	}*/
	//std::cout << f[n][1][0] - 1;

	maxa t;
	while (std::cin >> t) {
		res.clear();
		if (!t || t == f[n][1][0] || !DFS(0, 0, n, t)) std::cout << '0';
		else for (maxn i = 0; i < res.size(); i++) std::cout << res[i] << ' ';
		std::cout << '\n';
	}
}


int main() {
	//freopen("dictnum1.inp", "r", stdin);
	//freopen("dictnum1.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}