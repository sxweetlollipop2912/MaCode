#include "pch.h"
#include <iostream>
#include <fstream>

#define max 150
#define mod 100

int n;
int f[3][max];

void Prepare() {
	//freopen("BT1.inp", "r", stdin);
	//freopen("BT1.out", "w", stdout);
	std::cin >> n;
	f[0][0] = 1;
	f[1][0] = 1;
	f[2][0] = 2;
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
	
	if (n == 0) {
		std::cout << 0;
		return 0;
	}

	int cur = -1;
	for (int i = 0; i < n - 2; i++) {
		cur++;
		Add(cur % 3, (cur + 1) % 3);
		Add(cur % 3, (cur + 2) % 3);
	}
	
	if (n < 3) cur = n;
	else cur %= 3;
	
	int ii;
	for (ii = max - 1; ii >= 0; ii--) if (f[cur][ii] != 0) break;
	
	std::cout << f[cur][ii];
	for (int i = ii - 1; i >= 0; i--) {
		if (f[cur][i] < 10) std::cout << 0;
		std::cout << f[cur][i];
	}
}