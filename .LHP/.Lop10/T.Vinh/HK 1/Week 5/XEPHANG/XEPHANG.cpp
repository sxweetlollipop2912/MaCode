#include "pch.h"
#include <iostream>
#include <fstream>


bool f[100][100];
int n, m;

void Prepare() {
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		f[u - 1][v - 1] = 1;
	}
}


int main() {
	freopen("XEPHANG.inp", "r", stdin);
	freopen("XEPHANG.out", "w", stdout);
	Prepare();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (f[i][j] && f[j][k]) f[i][k] = 1;
	int re = 0;
	for (int i = 0; i < n; i++) {
		int d = 0;
		for (int j = 0; j < n; j++)
			d += (f[i][j] | f[j][i]) * (i != j);
		if (d == n - 1) re++;
	}
	std::cout << re;
}