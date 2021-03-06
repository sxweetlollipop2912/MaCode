// W >=0 && 0 <= a <= 1000
#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 50
#define maxW 50000 // maxa_max 1000

typedef int maxn;
typedef int maxa;

unsigned int f[2][maxW], W; 
maxn n;
maxa a[maxN];

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) std::cin >> a[i];
}


int main() {
	Prepare();

	bool p = 0;
	for (unsigned int i = 0; i <= W; i++)
		if (a[0] <= i) f[p][i] = a[0];

	for (maxn i = 1; i < n; i++) {
		p = 1 - p;
		for (unsigned int j = 0; j <= W; j++) {
			if (a[i] <= j) f[p][j] = std::max(f[1 - p][j], f[1 - p][j - a[i]] + a[i]);
			else f[p][j] = f[1 - p][j];
		}
	}

	std::cout << f[p][W];
}