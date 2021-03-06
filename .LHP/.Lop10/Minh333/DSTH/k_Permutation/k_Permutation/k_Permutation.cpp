// max 20 digit n!

#include "pch.h"
#include <iostream>
#include <fstream>

int n;
bool a[21];
unsigned long long gt = 1, k;

void Prepare() {
	std::cin >> n >> k;
	k--;
}


int a_th(int n_th) {
	int re = 0;
	int i = 0;
	while (re < n_th) re += 1 - a[++i];
	a[i] = 1;
	return i;
}


int main() {
	Prepare();
	for (int i = 2; i < n; i++) gt *= i;
	for (int i = 0; i < n - 1; i++) {
		std::cout << a_th(k / gt + 1) << " ";
		k = k % gt;
		gt = gt / (n - i - 1);
	}
	std::cout << a_th(1);
}