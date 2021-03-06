// m n
#include "pch.h"
#include <iostream>
#include <fstream>

bool a[10001][10001], f[10001][10001];
int m, n, ni[8] = { 0, 0,1,1, 1,-1,-1,-1 },
          nj[8] = { 1,-1,0,1,-1, 0, 1,-1 };

void Prepare() {
	//freopen("MIENSO.inp", "r", stdin);
	//freopen("MIENSO.out", "w", stdout);
	std::cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			int c;
			std::cin >> c;
			a[i][j] = c > 0 ? 1 : 0;
		}
}

void Mark(int ii, int jj) {
	if ((ii < 0) || (jj < 0) || (!a[ii][jj]) || (f[ii][jj])) return;
	f[ii][jj] = 1;
	for (int i = 0; i < 8; i++) 
		Mark(ii + ni[i], jj + nj[i]);
}


int main() {
	Prepare();
	int re = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			re += a[i][j] * (1 - f[i][j]);
			Mark(i, j);
		}
	std::cout << re;
}