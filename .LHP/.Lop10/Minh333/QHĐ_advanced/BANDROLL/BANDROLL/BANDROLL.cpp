#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 501
#define maxK 51

typedef int maxn, maxk;

maxn re[maxN];
maxn n, m;
maxk K;


void Prepare() {
	maxn a[maxN];
	std::cin >> K >> n >> m;

	for (maxn i = 0; i < m; i++)
		std::cin >> a[i];
	//a[i] = i + 2;

	std::sort(a, a + m);

	for (maxn i = 0; i < m - 1; i++)
		re[a[i + 1] - a[i] - 1]++;
}


int main() {
	//freopen("BANDROLL.inp", "r", stdin);
	//freopen("BANDROLL.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	maxn res = m;

	maxn i = 0;
	while (m > K && i < maxN) {
		while (re[i] == 0) i++;
		res += i;
		re[i]--;
		m--;
	}

	std::cout << res;
}