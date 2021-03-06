#include "pch.h"
#include <iostream>
#include <math.h>

long long n;
long k;

void Prepare() {
	std::cin >> n;
}

long long P() {
	long long re = 2;
	while (re <= pow(n, 0.5)) {
		if (n % re == 0) return re;
		re++;
	}
	return n;
}

int main() {
	Prepare();
	std::cout << 1 + (n - P()) / 2;
}