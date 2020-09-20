#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxA 1000000001
#define maxN 100001
#define maxR 100000000000001
#define maxT 3

typedef long maxn;
typedef long long maxa;

maxa L[maxT], C[maxT], a[maxN], f[maxN];
maxn n, S, F;


void Prepare() {
	std::cin >> L[0] >> L[1] >> L[2] >> C[0] >> C[1] >> C[2];
	std::cin >> n;

	std::cin >> S >> F;
	S--; F--;

	for (maxn i = 1; i < n; i++) std::cin >> a[i];
	a[0] = 0;
}


maxa fmin(maxn x, int id_l) {
	maxn l = S, r = x - 1;

	while (l != r) {
		maxn m = (l + r) / 2;
		if (a[x] - a[m] > L[id_l]) l = m + 1;
		else r = m;
	}

	if (a[x] - a[r] <= L[id_l]) return f[r];
	return maxR;
}


maxa Min(maxa x1, maxa x2, maxa x3) {
	return std::min(x1, std::min(x2, x3));
}


void Process() {
	f[S] = 0;

	for (maxn i = S + 1; i <= F; i++) 
		f[i] = Min(fmin(i, 0) + C[0], fmin(i, 1) + C[1], fmin(i, 2) + C[2]);

	std::cout << f[F];
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	freopen("ticket.inp", "r", stdin);

	Prepare();
	Process();
}