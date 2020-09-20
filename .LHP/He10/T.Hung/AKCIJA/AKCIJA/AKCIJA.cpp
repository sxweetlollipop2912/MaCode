#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100001
#define maxA 100000

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		res += a[i];
	}
	std::sort(a, a + n);
}


void Process() {
	for (maxn i = n - 3; i >= 0; i -= 3)  res -= a[i];
	std::cout << res;
}


int main() {
	freopen("akcija.inp", "r", stdin);
	freopen("akcija.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}