#include "pch.h"
#include <iostream>
#include <algorithm>
#include <math.h>

long n, re, max;

void Prepare() {
	std::cin >> n;
}

void Prime(long n) {
	long p = 2;
	while (n > 0) {
		long re = 0;
		while (n % p == 0) {
			re++;
			n /= p;
		}
		max = std::max(max, re);
		while (n % p != 0) p++;
	}
}

int main() {
	Prepare();
	Prime(n);
	long k = 1;
	int cnt = 0;
	while (k < max) {
		k <<= 1;
		cnt++;
	}
	std::cout << cnt + 1;
}