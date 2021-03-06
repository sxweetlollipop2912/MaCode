#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 1000001
#define maxA 32001

typedef long maxn;
typedef int maxa;
typedef long long maxf;

maxn pos[maxN], n;
maxf f[2];


void Prepare() {
	//freopen("SUBSUM.inp", "r", stdin);
	//freopen("SUBSUM.out", "w", stdout);

	std::cin >> n;
}


int main() {
	
	Prepare();

	bool p = 1;

	std::cin >> f[p];
	//pos[0] = 0;

	maxn id = 0;
	maxf re = 0;

	for (maxn i = 1; i < n; i++) {

		p = 1 - p;

		std::cin >> f[p];
		
		if (f[p] < f[p] + f[1 - p]) {
			f[p] += f[1 - p];
			pos[i] = pos[i - 1];
		}
		
		else pos[i] = i;

		if (re < f[p]) {
			id = i;
			re = f[p];
		}
	}

	std::cout << re << '\n' << (pos[id] + 1) << ' ' << (id + 1);
}