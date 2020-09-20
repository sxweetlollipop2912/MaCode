#include "pch.h"
#include <iostream>
#include <cstdio>

#define maxN 1000003
#define dummy_next maxN - 3
#define dummy_prev maxN - 2
//#define maxA 1000000001

typedef long maxn, maxa;

maxn n, res;
maxa a[maxN];
bool jump[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}

maxn next(const maxn &x) {
	return a[x] + x < 0 ? dummy_next : a[x] + x;
}

maxn prev(const maxn &x) {
	return x - a[x] < 0 ? dummy_prev : x - a[x];
}


void Process() {
	jump[next(0)] = 1;
	res = 0;

	for (maxn i = 1; i < n; i++) {
		if (!jump[prev(i)]) continue;
		jump[next(i)] = 1;
		res = i;
	}

	std::cout << res + 1;
}


int main() {
	//freopen("rbech.inp", "r", stdin);
	//freopen("rbech.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}