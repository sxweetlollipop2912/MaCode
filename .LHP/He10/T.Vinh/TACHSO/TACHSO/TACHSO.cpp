#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 703
//#define maxA 1001
//#define maxR 1000000000001
#define DEBUG 0

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn len = 1; len <= n - 2; len++)
		for (maxn x = 1; x < n - 1; x++) {

			maxn L = std::max(0, x - len);
			maxn R = std::min(n - 1, x + len);

			if (x + len == R)
				for (maxn l = L; l < x; l++) 
					f[l + 1][R - 1] = std::max(f[l + 1][R - 1], a[x] * (a[l] + a[R]) + f[l + 1][x - 1] + f[x + 1][R - 1]);

			if (x - len == L)
				for (maxn r = x + 1; r <= R; r++) 
					f[L + 1][r - 1] = std::max(f[L + 1][r - 1], a[x] * (a[L] + a[r]) + f[L + 1][x - 1] + f[x + 1][r - 1]);
		}
}


int main() {
	//freopen("tachso.inp", "r", stdin);
	//freopen("tachso.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();

	std::cout << f[1][n - 2];
}
