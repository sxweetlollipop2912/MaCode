// AC
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 200001

typedef int maxn, maxa;

maxn n;
maxa a[maxN];

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n;
	
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);

	bool one = a[0] == 1, two = a[n - 1] == 2;

	if (two) std::cout << "2 ";
	if (one) std::cout << "1 ";
	for (maxn i = n - 1 - two; i >= 0 + one; i--) std::cout << a[i] << ' ';
}