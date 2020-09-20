#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

#pragma warning(disable:4996)

#define maxN 103

typedef int maxn;
typedef long maxa;

maxn n, K;
maxa f[maxN][maxN][maxN];
std::vector <maxn> V;


void Prepare() {
	std::cin >> n >> K;
}


maxa DFS(const maxn u, const maxn k, const maxn S, const maxa I) {
	if (I == V.size()) return 1;
	if (V[I] == u)
		return DFS(u, k - 1, S - u, I + 1);

	maxn s = k != 0 ? f[S][u][k] : 0;
	for (maxn v = u + 1; v < V[I]; v++) 
		s += f[S][v][K];
	return s + DFS(V[I], K - 1, S - V[I], I + 1);
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

	std::string s; std::cin.ignore();
	while (std::getline(std::cin, s)) {
		std::stringstream ss(s);
		maxn x; 
		V.clear();
		while (ss >> x) V.push_back(x);

		std::cout << DFS(0, 0, n, 0) << '\n';
	}
}


int main() {
	freopen("dictnum2.inp", "r", stdin);
	freopen("dictnum2.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}