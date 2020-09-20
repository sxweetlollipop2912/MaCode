#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 2001

typedef int maxn;
typedef long long maxr;
typedef std::string str;

maxn m, n, f[maxN][maxN];
str a[maxN];
maxr res;


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) std::cin >> a[i];
}


void Process() {
	for (maxn j = 0; j < n; j++) {
		f[m - 1][j] = 1;
		if (m != 1) f[m - 2][j] = 1;
	}

	for (maxn i = m - 3; i >= 0; i--) for (maxn j = 0; j < n; j++) {
		f[i][j] = 1;
		if (j == 0 || j == n - 1 || a[i][j] != a[i + 1][j - 1] || a[i][j] != a[i + 1][j + 1] || a[i][j] != a[i + 1][j])
			continue;

		maxn l = std::min(f[i + 1][j - 1], f[i + 1][j + 1]) + 1;
		
		if (l > f[i + 1][j] && a[i][j] == a[i + 2][j] && f[i + 1][j] <= f[i + 2][j])
			f[i][j] = f[i + 1][j] + 1;
		else
			f[i][j] = std::min(l, f[i + 1][j]);
	}

	res = 0;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++)
		res += (maxr)f[i][j];

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}