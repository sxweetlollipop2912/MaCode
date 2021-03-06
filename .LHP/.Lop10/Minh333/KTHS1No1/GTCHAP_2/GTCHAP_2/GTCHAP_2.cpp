#include "pch.h"
#include <iostream>

int re[2][100], n, len = 100, p = 1;

void Prepare() {
	std::cin >> n;
	std::fill(re[p], re[p] + len, 0);
	re[p][0] = 1;
}

void fix() {
	int x = 0;
	for (int i = 0; i < len; i++) {
		re[p][i] += x;
		x = re[p][i] / 10;
		re[p][i] %= 10;
	}
}

void Multiply(int n) {
	p = 1 - p;
	std::fill(re[p], re[p] + len, 0);
	int d = -1;
	while (n > 0) {
		d++;
		int x = n % 10;
		for (int i = 0; i < len - 5; i++) {
			re[p][d + i] += x * re[1 - p][i];
		}
		n /= 10;
	}
	fix();
}


int main() {
	Prepare();
	n += 2;
	while (n > 2) Multiply(n -= 2);
	int i;
	for (i = len - 1; (i >= 0) && (re[p][i] == 0); i--) {}
	for (i = i; i >= 0; i--) std::cout << re[p][i];
}