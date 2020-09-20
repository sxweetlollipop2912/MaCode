#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <string>

#pragma warning(disable:4996)

#define maxN 53

typedef int maxn;
typedef long maxa;
typedef std::string str;

maxn N, K, M;
maxa f[maxN][maxN][maxN];
str ss;
std::vector <maxn> V;


void Prepare() {
	std::cin >> N >> K >> M;
}


/*bool DFS_A(const maxn u, const maxn k, const maxn S, const maxa T) {
	if (u != 0) V.push_back(u);
	if (S == 0) return 1;

	if (k != 0 && f[S][u][k] >= T)
		return DFS_A(u, k - 1, S - u, T);

	maxn s = k != 0 ? f[S][u][k] : 0;
	for (maxn v = u + 1; v <= S; v++) {
		if (f[S][v][K] >= T - s) return DFS_A(v, K - 1, S - v, T - s);
		s += f[S][v][K];
	}
	return 0;
}
*/

maxa DFS_STT(const maxn n, const maxn k, const maxn m) {
	if (n == ss.size()) return 1;
	if (ss[n] == '0') {
		if (n != 0 && ss[n] != ss[n - 1]) return DFS_STT(n - 1, k, m - 1);
		return DFS_STT(n - 1, k - 1, M);
	}
	else {
		if (n != 0 && ss[n] != ss[n - 1]) return f[n][k][m] + DFS_STT(n - 1, k, m - 1);
		return f[n][k - 1][M] + DFS_STT(n - 1, k - 1, M);
	}
}


maxa DP(const maxn n, const maxn k, const maxn m) {
	if (f[n][k][m] != 0) return f[n][k][m];
	if (m > n || k > (n - m) + 1) return 0;

	f[n][k][m] = DP(n - m, k - 1, M);
	if (m != 1)
		f[n][k][m] += DP(n, k, m - 1);
}


void Process() {
	//f[n][k][m]: sl cac day sl mv = n, có k mv, bat dau voi mv dai <= m dv
	f[0][0][M] = 1;
	for (maxn ni = 1; ni <= N; ni++) for (maxn mi = 1; mi <= M; mi++) for (maxn ki = 1; ki <= std::min(K, ni - mi) + 1; ki++) {
		if (ni - mi >= 0)
			f[ni][ki][mi] = f[ni - mi][ki - 1][M];
		f[ni][ki][mi] += f[ni][ki][mi - 1];
		std::cout << ni << ' ' << ki << ' ' << mi << ' ' << f[ni][ki][mi] << '\n';
	}
	std::cout << DP(N, K, M);
}


int main() {
	//freopen("dictnum.inp", "r", stdin);
	//freopen("dictnum.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}