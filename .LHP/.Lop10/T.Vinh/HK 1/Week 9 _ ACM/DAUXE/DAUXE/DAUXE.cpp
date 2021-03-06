#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning(disable:4996)

#define maxN 100

typedef int maxn;

maxn n, l;

int main() {
	freopen("DAUXE.inp", "r", stdin);
	freopen("DAUXE.out", "w", stdout);

	std::cin >> n >> l;

	int re = 0, cnt = 0;
	char x;

	while (std::cin >> x) {
		if (x == '.') cnt++;
		else {
			re = re + cnt / l;
			cnt = 0;
		}
	}
	re = re + cnt / l;

	std::cout << std::max(re - n, 0) << '\n';
	std::cout << std::min(re, n);
}