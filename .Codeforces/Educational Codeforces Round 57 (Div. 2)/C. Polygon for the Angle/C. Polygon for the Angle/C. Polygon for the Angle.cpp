// AC
#include "pch.h"
#include <iostream>

#define maxN 181
#define maxA 180

typedef long maxn;
maxn x;


int GCD(maxn x, maxn y) {

	while (y != 0) {
		maxn r = x % y;
		x = y;
		y = r;
	}
	return x;
}


void Process() {
	maxn tmp = x;
	if (tmp > 90) tmp = 180 - tmp;
	tmp *= 2;

	long a = tmp, b = 360 - tmp;

	tmp = GCD(a, b);
	a /= tmp; 
	b /= tmp;

	if ((x > 90 && a == 1) || (x <= 90 && b == 1)) {
		a *= 2;
		b *= 2;
	}

	if (a + b < 3) std::cout << -1;
	else std::cout << a + b;

	std::cout << '\n';
}


int main() {
	maxn n = 0;
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> x;
		Process();
	}
}