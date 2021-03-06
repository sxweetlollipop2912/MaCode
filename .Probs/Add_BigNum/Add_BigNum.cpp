#include "pch.h"
#include <iostream>
#include <fstream>

int a[2][100], n1, n2;

void Prepare() {
	std::cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) std::cin >> a[0][i];
	for (int i = 0; i < n2; i++) std::cin >> a[1][i];
}

void Add(int p) {
	for (int i = 0; i < 100; i++) {
		a[p][i] += a[1 - p][i];
		a[p][i + 1] = a[p][i + 1] + (a[p][i] / 100);
		a[p][i] %= 100;
	}
}

int main() {
	Prepare();
	int p = 0;
	Add(p);
	int ii;
	for (ii = 99; ii >= 0; ii--) if (a[p][ii] != 0) break;
	std::cout << a[p][ii];
	for (int i = ii - 1; i >= 0; i--) {
		if (a[p][i] < 10) std::cout << 0;
		std::cout << a[p][i];
	}
}