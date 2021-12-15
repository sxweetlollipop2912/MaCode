// not done
#include <iostream>
#include <algorithm>

#define maxN 2102
#define Ma (ma + mt)
#define Na (na + nt)
#define isEmpty(x, y) (!(sum[x][y] - sum[std::max((maxn)0, x - mt)][y] - sum[x][std::max((maxn)0, y - nt)] + sum[std::max((maxn)0, x - mt)][std::max((maxn)0, y - nt)]))

typedef long maxn;

maxn ma, na, mt, nt, a[maxN][maxN], sum[maxN][maxN], f[maxN][maxN], mx, my, res;


void Prepare() {
	mx = my = 0;
	for (maxn i = 1; i <= ma; i++) for (maxn j = 1; j <= na; j++) {
		a[i][j] = 0;
		char c; std::cin >> c;
		if (c == '.') continue;
		a[i][j] = 1;
		mx = std::max(mx, i), my = std::max(my, j);
	}

	for (maxn i = 1; i <= Ma; i++) for (maxn j = 1; j <= Na; j++) 
		sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
}


void Process() {
	for (maxn i = 1; i <= Ma; i++) for (maxn j = 1; j <= Na; j++) {
		f[i][j] = (maxn)!isEmpty(i, j) + f[std::max((maxn)0, i - mt)][j] + f[i][std::max((maxn)0, j - nt)] - f[std::max((maxn)0, i - mt)][std::max((maxn)0, j - nt)];
		//std::cout << i << ' ' << j << ' ' << f[i][j] << ' ' << isEmpty(i, j) << '\n';
	}

	res = na * ma;
	for (maxn i = mx; i <= Ma; i++) for (maxn j = my; j <= Na; j++) res = std::min(res, f[i][j]);

	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> ma >> na >> mt >> nt) {
		Prepare();
		Process();
	}
}