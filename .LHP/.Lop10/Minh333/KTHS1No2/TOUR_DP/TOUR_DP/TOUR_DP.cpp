#include "pch.h"
#include <iostream>
#include <fstream>

#define maxn 11

int c[maxn][470][maxn];
int f[maxn + 1][maxn + 1], n;

void Prepare() {
	//freopen("TOUR.inp", "r", stdin);
	//freopen("TOUR.out", "w", stdout);
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> f[0][i + 1] >> f[i + 1][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> f[i + 1][j + 1];
	c[0][0][0] = 0;
}


void CMin(int S, int j) {
	for (int i = 1; i < S; i++) {

	}
}