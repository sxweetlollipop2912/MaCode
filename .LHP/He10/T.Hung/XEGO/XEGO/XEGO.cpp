#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 53
#define maxA 1001
#define maxR 99999999

typedef int maxn;
typedef long maxa;

maxn n;
maxa L, a[maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
	a[0] = 0;
	++n, a[n] = L;
	std::sort(a, a + n + 1);
}


maxa Try(const maxn l, const maxn r) {
	if (f[l][r] != maxR) return f[l][r];
	if (l + 1 == r) f[l][r] = 0;

	for (maxn i = l + 1; i < r; i++) f[l][r] = std::min(f[l][r], Try(l, i) + Try(i, r) + (a[r] - a[l]));
	//std::cout << l << ' ' << r << ' ' << f[l][r] << '\n';
	return f[l][r];
}


void Process() {
	for (maxn i = 0; i <= n; i++)
		std::fill(f[i], f[i] + n + 1, maxR);
	std::cout << Try(0, n) << '\n';
}


int main() {
	//freopen("xego.inp", "r", stdin);
	//freopen("xego.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> L && L) {
		Prepare();
		Process();
	}
}