#include "pch.h"
#include <iostream>
#include <cstdio>
#include <math.h>

typedef long long floor_t;
typedef int bal_t;

floor_t f;
bal_t bal;

int main() {
	freopen("water.inp", "r", stdin);
	freopen("water.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> bal >> f;
	floor_t res = ceil(log2(f));
	if (bal < res) std::cout << -1;
	else std::cout << res;
}