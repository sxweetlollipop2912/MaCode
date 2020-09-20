#include "pch.h"
#include <iostream>
#include <algorithm>

typedef long long maxa;

maxa a, b, c, d;


int main() {
	std::cin >> a >> b >> c >> d;
	maxa l = std::min(a, std::min(b, c));
	maxa r = std::max(a, std::max(b, c));
	maxa m = a + b + c - l - r;
	std::cout << std::max(d - (m - l), (maxa)0) + std::max(d - (r - m), (maxa)0);
}