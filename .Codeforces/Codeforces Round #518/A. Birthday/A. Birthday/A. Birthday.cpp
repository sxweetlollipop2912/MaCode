// Wrong answer on test 6
#include "pch.h"
#include <iostream>
#include <math.h>

#define high 1000000000000000000
#define low 1

unsigned long long n, m, k, l;

void Prepare() {
	std::cin >> n >> m >> k >> l;
}

int main() {
	Prepare();
	if (m < low || m > high || l < low || l > high || k < low || n > high || k > n) {
		std::cout << "-1";
		return 0;
	}
	unsigned long long re = ceil((k + l) / (double) m);
	if (re * m > n) std::cout << "-1";
	else std::cout << re;
}