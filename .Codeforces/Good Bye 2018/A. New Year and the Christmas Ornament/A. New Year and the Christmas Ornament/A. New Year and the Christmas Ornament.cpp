#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxA 101

typedef int maxa;

maxa a[5];


int main() {
	a[0] = maxA;

	for (int i = 1; i < 4; i++) {
		std::cin >> a[i];
		a[i] = std::min(a[i], a[i - 1] + 1);
	}

	a[3] = a[3] * 3 - 3;
	std::cout << a[3];
}