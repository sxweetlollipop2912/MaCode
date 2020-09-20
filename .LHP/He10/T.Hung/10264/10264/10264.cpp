// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>

#define maxN 16385
#define maxM 114689

typedef int maxn;
typedef long maxm;
typedef long long maxa;

maxn n, dimension;
maxa W[maxN], P[maxN], res;


void Prepare() {
	n = pow(2, dimension);

	for (maxn i = 0; i < n; i++)
		std::cin >> W[i];
}


maxa Potency(const maxn &c) {
	maxn x = 1;
	P[c] = 0;

	while (x != n) {
		P[c] += W[c^x];
		x <<= 1;
	}

	return P[c];
}


void Check(const maxn &c) {
	maxn x = 1;
	while (x != n) {
		res = std::max(res, P[c] + P[c^x]);
		x <<= 1;
	}
}


void Process() {
	res = 0;

	for (maxn i = 0; i < n; i++)
		Potency(i);
	for (maxn i = 0; i < n; i++)
		Check(i);

	std::cout << res << '\n';
}


int main() {
	//freopen("10264.inp", "r", stdin);
	//freopen("10264.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> dimension) {
		Prepare();
		Process();
	}
}