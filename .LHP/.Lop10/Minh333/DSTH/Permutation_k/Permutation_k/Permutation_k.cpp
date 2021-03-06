// max 20 digit n!
#include "pch.h"
#include <iostream>

int  p[20], n;
bool a[20];
unsigned long long gt = 1;

void Prepare() {
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> p[i];
}


int a_th(int x) {
	int n = 0;
	for (int i = 1; i < x; i++) n += 1 - a[i];
	a[x] = 1;
	return n;
}


int main() {
	Prepare();
	unsigned long long re = 1;
	for (int i = 2; i < n; i++) gt *= i;
	for (int i = 0; i < n - 2; i++) {
		re = re + a_th(p[i]) * gt;
		gt = gt / (n - i - 1);
	}
	re += a_th(p[n - 2]);
	std::cout << re;
}