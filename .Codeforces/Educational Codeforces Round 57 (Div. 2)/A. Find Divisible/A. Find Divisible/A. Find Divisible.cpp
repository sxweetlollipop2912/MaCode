#include "pch.h"
#include <iostream>

typedef long maxn;

maxn n, l, r;

int main() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		std::cin >> l >> r;
		std::cout << l << ' ';
		l *= 2;
		std::cout << l << '\n';
	}
}