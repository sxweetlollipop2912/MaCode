#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 502
#define maxR 250002

typedef long maxn;

maxn m, n, mx, mn, f[maxN][maxN];


void Prepare() {
	std::cin >> m >> n;
	mx = std::max(m, n);
	mn = m + n - mx;
}


void Process() {
	for (maxn i = 1; i <= mn; i++)
		f[i][i] = 1;

	for (maxn i = 1; i <= mn; i++) {
		for (maxn j = i + 1; j <= mx; j++) {
			f[i][j] = i * j;
			for (maxn k = 1; k <= j / 2; k++) {
				f[i][j] = std::min(f[i][j], f[i][k] + f[i][j - k]);
			}
			for (maxn k = 1; k <= i / 2; k++) {
				f[i][j] = std::min(f[i][j], f[k][j] + f[i - k][j])
			}
			f[j][i] = f[i][j];
		}
	}

	std::cout << f[mn][mx];
}


int main() {
	//freopen("hcn1.inp", "r", stdin);
	//freopen("hcn1.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}