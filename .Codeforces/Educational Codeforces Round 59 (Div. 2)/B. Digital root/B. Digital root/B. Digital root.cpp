#include "pch.h"
#include <iostream>

int main() {
	long long k, x;
	int n;
	std::cin >> n;

	while (n--) {
		std::cin >> k >> x;
		long long res = 9 * (k - 1) + x;
		std::cout << res << '\n';
	}
}