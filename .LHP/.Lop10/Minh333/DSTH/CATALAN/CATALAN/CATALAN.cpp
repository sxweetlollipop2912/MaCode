// maxn 120
#include "pch.h"
#include <iostream>
#include <fstream>

#define max 35
#define maxn 120
#define mod 100

int n, a[maxn][max];

void Prepare() {
	//freopen("CATALAN.inp", "r", stdin);
	//freopen("CATALAN.out", "w", stdout);
	std::cin >> n;
	a[0][0] = 1;
	a[1][0] = 1;
}


void Multi(int re, int ii, int jj) {
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++) {
			a[re][i + j] += a[ii][i] * a[jj][j];
			a[re][i + j + 1] += a[re][i + j] / mod;
			a[re][i + j] %= mod;
		}
}


void Multi2(int re) {
	for (int i = 0; i < max; i++) 
		a[re][i] *= 2;
	for (int i = 0; i < max - 1; i++) {  // maxn = max * 2
		a[re][i + 1] += a[re][i] / mod;
		a[re][i] %= mod;
	}
}


void K(int n) {
	for (int i = 0; i < n / 2; i++) Multi(n, i, n - i - 1);
	Multi2(n);
	if (n % 2 == 1) Multi(n, n / 2, n - (n / 2) - 1);
}


int main() {
	Prepare();
	for (int i = 2; i <= n; i++) K(i);

	int ii;
	for (ii = max - 1; ii >= 0; ii--) if (a[n][ii] != 0) break;
	std::cout << a[n][ii];
	for (int i = ii - 1; i >= 0; i--) {
		if (a[n][i] < 10) std::cout << 0; // 0<num>
		std::cout << a[n][i];
	}
}