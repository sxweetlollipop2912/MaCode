// W >= 0 || 0 <= a <= 1000
#include "pch.h"
#include <iostream>
#include <fstream>

#define maxN 50
#define maxW 50000

typedef int maxn;
typedef int maxa;

maxa a[maxN];
maxn n;
unsigned long long W, f[2][maxW];

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) std::cin >> a[i];
}

int main() {
	Prepare();
	
	bool p = 0;
	f[p][a[0]] = 1;

	for (int i = 1; i < n; i++) {
		p = 1 - p;
		for (int j = 0; j <= W; j++) {
			f[p][j] = f[1 - p][j];
			if (a[i] <= j) f[p][j] += f[1 - p][j - a[i]];
		}
		f[p][a[i]] += 1;
	}

	std::cout << f[p][W];
}