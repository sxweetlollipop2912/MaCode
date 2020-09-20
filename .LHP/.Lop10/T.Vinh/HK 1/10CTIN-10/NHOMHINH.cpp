#include <iostream>
#include <fstream>

int m, n;
int a[21][21];
int ki[4] = { -1,0,0,1 },
	kj[4] = { 0,-1,1,0 },
	f[4][4] = { {2,1,-1,-1},{3,-1,0,-1},{-1,3,-1,0},{-1,-1,2,1} };
bool map[21][21];

void Prepare() {
	freopen("NHOMHINH.inp", "r", stdin);
	freopen("NHOMHINH.out", "w", stdout);
	std::cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			char c;
			std::cin >> c;
			a[i][j] = c - 'A';
		}
}

void Try(int ii, int jj, int prev) {
	if ((ii >= m) || (ii < 0) || (jj >= n) || (jj < 0) || (map[ii][jj])) return;
	if (prev != a[ii][jj]) return;
	map[ii][jj] = 1;
	for (int i = 0; i < 4; i++)
		Try(ii + ki[i], jj + kj[i], f[a[ii][jj]][i]);
}


int main() {
	Prepare();
	int re = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			re += 1 - map[i][j];
			Try(i, j, a[i][j]);
		}
	std::cout << re;
}
