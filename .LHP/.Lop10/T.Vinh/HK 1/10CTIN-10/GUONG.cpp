#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1001

typedef int maxn;

int x[2][4] = { {0,0,-1,1},{0,0,1,-1} },
    y[2][4] = { {-1,1,0,0},{1,-1,0,0} },
    dir[2][4] = { {3,2,1,0},{2,3,0,1} };
bool a[maxN][maxN], f[maxN][maxN];
long re;
maxn m, n;


void Prepare() {
	freopen("GUONG.inp", "r", stdin);
	freopen("GUONG.out", "w", stdout);

	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			char x;
			std::cin >> x;
			a[i][j] = x == '/' ? 0 : 1;
		}
}


bool Fit(maxn x, maxn n) {
	return x >= 0 && x < n;
}


long Step(maxn ii, maxn jj, int direc) {

	if (f[ii][jj]) return 0;

	f[ii][jj] = 1;
	long re = 0;
	bool cur;

	maxn i = ii, j = jj;

	while (Fit(ii, m) && Fit(jj, n)) {
		re++;
		cur = a[ii][jj];
		i = ii; j = jj;
		ii += x[cur][direc];
		jj += y[cur][direc];
		direc = dir[cur][direc];
	}

	f[i][j] = 1;

	return re;
}


int main() {
	Prepare();

	long re = 0;
	for (maxn j = 0; j < n; j++) {
		re = std::max(re, Step(0, j, 0));
		re = std::max(re, Step(m - 1, j, 1));
	}

	for (maxn i = 0; i < m; i++) {
		re = std::max(re, Step(i, 0, 2));
		re = std::max(re, Step(i, n - 1, 3));
	}

	std::cout << re;
}
