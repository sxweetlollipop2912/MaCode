// AC
#include "pch.h"
#include <iostream>

int t;
long long a, b, k;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b >> k;
		long long re = (a * ((k + 1) / 2)) - (b * (k / 2));
		std::cout << re << '\n';
	}
}