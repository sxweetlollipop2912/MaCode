#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 30002
#define maxB 3
#define maxR 150001
#define Scena 8

typedef int maxn, scena;
typedef long maxa;

maxn n;
maxa dif3[maxN][maxB], f[2][Scena];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) std::cin >> dif3[i][0];
	for (maxn i = 1; i <= n; i++) std::cin >> dif3[i][1];
	for (maxn i = 1; i <= n; i++) std::cin >> dif3[i][2];
}


void Process() {
	bool p = 1;
	std::fill(f[p], f[p] + Scena, maxR);
	f[p][1 << 0] = dif3[1][0], f[p][1 << 1] = dif3[1][1], f[p][1 << 2] = dif3[1][2];

	for (maxn i = 2; i <= n; i++) {
		p = !p;
		std::fill(f[p], f[p] + Scena, maxR);

		for (maxn b = 0; b < maxB; b++) {
			scena slot = 1 << b;
			for (scena scene = 1; scene < Scena; scene++) {
				f[p][slot | scene] = std::min(f[p][slot | scene], f[!p][scene] + dif3[i][b]);
			}
		}
	}

	std::cout << f[p][Scena - 1];
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}