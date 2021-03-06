#include "pch.h"
#include <iostream>

int n, a[2][80], p = 0;

void fix() {
	int x = 0;
	
	for (int i = 79; i >= 0; i--) {
		a[p][i] += x;
		x = a[p][i] / 10;
		a[p][i] %= 10;
	}
}

void multiply(int n) {
	p = 1 - p;
	int d = 0;
	std::fill(a[p], a[p] + 80, 0);
	
	while (n > 0) {
		int x = n % 10;
		n /= 10;
		for (int i = 0; i < 80 - d; i++) a[p][i] += x * a[1 - p][i + d];
		d++;
	}
	fix();
}

int main() {
	std::cin >> n;
	std::fill(a[p], a[p] + 80, 0);
	
	a[p][79] = 1;
	n += 2;
	
	while (n > 2) multiply(n -= 2);
	
	int i;
	for (i = 0; a[p][i] == 0; i++) {}
	for (i = i; i < 80; i++) std::cout << a[p][i];
}