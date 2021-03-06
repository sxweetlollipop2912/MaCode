#include "pch.h"
#include <iostream>
#include <fstream>

#define max 11
#define mod 100

int n;
int f[4][max];

void Prepare() {
	//freopen("BT1.inp", "r", stdin);
	//freopen("BT1.out", "w", stdout);
	std::cin >> n;
	// f3
	// n >= 3
	f[0][0] = 0;
	f[1][0] = 0;
	// f2
	// start at 1
	f[2][0] = 0;
	f[3][0] = 1;
}

void Add(int ii, int jj) {  // cong vao ii
	for (int i = 0; i < max; i++) {
		f[ii][i] += f[jj][i];
		f[ii][i + 1] = f[ii][i + 1] + (f[ii][i] / mod);
		f[ii][i] %= mod;
	}
}

int main() {
	Prepare();

	int p3 = 1, p2 = 2; // re -> p3
	for (int i = 0; i < n - 2; i++) {
		p3 = 1 - p3;
		p2 = 5 - p2;
		Add(p2, 5 - p2);
		Add(p3, 1 - p3);
		Add(p3, p2);

	}

	int ii;
	for (ii = max - 1; ii >= 0; ii--) if (f[p3][ii] != 0) break;

	std::cout << f[p3][ii];
	for (int i = ii - 1; i >= 0; i--) {
		if (f[p3][i] < 10) std::cout << 0;
		std::cout << f[p3][i];
	}
}