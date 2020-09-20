#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 200001

typedef int maxn;

maxn n, b[maxN], res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) std::cin >> b[i];
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
}


bool Base() {
	maxn base = 0;

	maxn i;
	for (i = n - 2; i >= 0; i--) 
		if (!b[i] || b[i] + 1 != b[i + 1]) break;
	if (b[i + 1] == 1) base = b[n - 1];

	for (maxn i = 0; i < n - base; i++) 
		if (b[i] && b[i] < i + 2 + base) return 0;

	std::cout << n - base;
	return 1;
}


void Process() {
	res = 0;

	for (maxn i = 0; i < n; i++) {
		if (!b[i] || b[i] >= i + 2) continue;
		res = std::max(res, i + 2 - b[i]);
	}

	std::cout << res + n;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Base()) Process();
}