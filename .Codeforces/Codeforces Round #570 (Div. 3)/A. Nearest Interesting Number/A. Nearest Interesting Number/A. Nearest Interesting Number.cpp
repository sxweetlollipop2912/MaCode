#include "pch.h"
#include <iostream>
#include <algorithm>

typedef long maxa;

maxa n;

bool check(maxa a) {
	maxa sum = 0;
	while (a != 0) {
		sum += a % 10;
		a /= 10;
	}
	return sum % 4 == 0;
}


int main() {
	std::cin >> n;
	while (!check(n)) ++n;
	std::cout << n;
}