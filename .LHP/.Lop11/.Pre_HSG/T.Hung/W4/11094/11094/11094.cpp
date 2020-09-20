// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning(disable:4996)

#define maxN 23

typedef int maxn;

maxn m, n, f[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }, stx, sty, res;
char map[maxN][maxN], land;


void Prepare() {
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		std::cin >> map[i][j];
	}
	std::cin >> stx >> sty;
	land = map[stx][sty];
}


maxn DFS(const maxn x, const maxn y) {
	++map[x][y]; maxn re = 1;
	
	for (int i = 0; i < 4; i++) {
		maxn x1 = x + f[i][0], y1 = y + f[i][1];
		if (x1 == -1) x1 = 0; if (x1 == m) x1 = m - 1;
		if (y1 == -1) y1 = n - 1; if (y1 == n) y1 = 0;

		if (map[x1][y1] == land) re += DFS(x1, y1);
	}
	return re;
}


void Process() {
	DFS(stx, sty);
	res = 0;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		if (map[i][j] == land) res = std::max(res, DFS(i, j));
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("11094.inp", "r", stdin);
	//freopen("11094.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> m >> n) {
		Prepare();
		Process();
	}
}