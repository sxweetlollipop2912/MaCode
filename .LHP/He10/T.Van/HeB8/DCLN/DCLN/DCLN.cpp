#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100001
#define maxR 1000000001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], res, rec;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	res = rec = a[0];

	for (maxn i = 1; i < n; i++) {
		rec = std::max(a[i], rec + a[i]);
		res = std::max(res, rec);
	}

	std::cout << res;
}


int main() {
	//freopen("dcln.inp", "r", stdin);
	//freopen("dcln.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}