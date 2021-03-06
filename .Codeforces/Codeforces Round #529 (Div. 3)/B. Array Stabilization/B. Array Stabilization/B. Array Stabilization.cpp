// AC
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxA 100001

typedef long maxn;

maxn n, a[maxN];


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 0; i < n; i++) std::cin >> a[i];

	std::sort(a, a + n);
}


int main() {
	Prepare();

	maxn max = a[n - 1] - a[n - 2];
	maxn min = a[1] - a[0];

	if (max > min) std::cout << (a[n - 2] - a[0]);
	else std::cout << (a[n - 1] - a[1]);
}