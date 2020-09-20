#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxA ((maxa)90000001)
#define maxN ((maxn)52)
#define N ((maxn)50)

typedef long maxn;
typedef long long maxa;

maxa A, f[2][maxN];
std::vector <int> res;


void Prepare() {
	std::cin >> A;
}


void DFS(const maxn n, const maxa A, bool flag = 0) {
	if (!n) return;
	if (f[0][n] >= A) {
		if (flag) res.push_back(0);
		DFS(n - 1, A, flag);
	}
	else {
		res.push_back(1);
		DFS(n - 1, A - f[0][n], 1);
	}
}


void Process() {
	f[0][1] = 1; f[1][1] = 1;

	for (maxn n = 2; n <= N; n++) {
		f[0][n] = f[0][n - 1] + f[1][n - 1];
		f[1][n] = f[0][n - 1];
		//std::cout << n << ' ' << f[0][n] + f[1][n] << '\n';
	}
	DFS(N, A + 1);

	for (maxn i = 0; i < res.size(); i++) std::cout << res[i];
}


int main() {
	//freopen("pinary.inp", "r", stdin);
	//freopen("pinary.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}