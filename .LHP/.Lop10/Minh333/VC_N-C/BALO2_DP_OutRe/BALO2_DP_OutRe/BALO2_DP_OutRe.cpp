// W >= 0 && a -> Z
#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 50
#define maxW 50000 // maxa_max 1000

typedef int maxn;
typedef int maxa;

int f[maxN][maxW], W;
maxn n;
maxa a[maxN];
bool mark[maxN];

void Prepare() {
	std::cin >> n >> W;
	for (int i = 0; i < n; i++) std::cin >> a[i];
}


void Mark() {
	unsigned w = W;
	for (int i = n - 1; i > 0; i--) {
		if (f[i][w] == f[i - 1][w]) continue;
		mark[i] = 1;
		w -= a[i];
	}
	if (f[0][w] > 0) mark[0] = 1;
}

int main() {
	Prepare();

	for (int i = 0; i <= W; i++)
		if (a[0] <= i) f[0][i] = std::max(0, a[0]);

	for (int i = 1; i < n; i++) 
		for (int j = 0; j <= W; j++) {
			if (a[i] <= j) f[i][j] = std::max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
			else f[i][j] = f[i - 1][j];
		}

	std::cout << f[n - 1][W] << '\n';
	Mark();
	for (int i = 0; i < n; i++)
		if (mark[i]) std::cout << a[i] << ' ';
}