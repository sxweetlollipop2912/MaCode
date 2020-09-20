#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 11
#define group(x) ((n & 1) ? abs((x) - (n / 2)) : (x) < (n / 2) ? ((n / 2) - (x) - 1) : (x) - (n / 2))

typedef int maxn;
typedef long maxa;

maxn n;
maxa a[maxN][maxN], res[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


void Process() {
	std::fill(res, res + n, 0);
	for (maxn r = 0, i = 0, j = n - 1; r < n; r++, ++i, --j) for (maxn c = std::min(i, j); c <= std::max(i, j); c++)    res[group(r)] += a[r][c];
	for (maxn c = 0, i = 0, j = n - 1; c < n; c++, ++i, --j) for (maxn r = std::min(i, j) + 1; r < std::max(i, j); r++) res[group(c)] += a[r][c];

	for (maxn i = (n + 1) / 2 - 1; i >= 0; i--) std::cout << ' ' << res[i];
	std::cout << '\n';
}


int main() {
	freopen("11470.inp", "r", stdin);
	freopen("11470.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> n && n) {
		++cntq, std::cout << "Case " << cntq << ":";
		Prepare();
		Process();
	}
}