#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 129
#define maxA 10002

typedef int maxn, maxa;

maxn n;
maxa a[maxN];
bool isDiv[maxA];

int main() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];

	maxn pos = std::max_element(a, a + n) - a;
	maxa re1 = a[pos];
	a[pos] = 0;
	isDiv[re1] = 1;

	for (maxn i = 0; i < n; i++) {
		if (!a[i] || isDiv[a[i]] || re1 % a[i] != 0) continue;
		isDiv[a[i]] = 1;
		a[i] = 0;
	}

	std::cout << re1 << ' ' << *std::max_element(a, a + n);
}