#include "pch.h"
#include <iostream>
#include <fstream>

int n, k, a[100001];

void Prepare() {
	//freopen("TOHOP.inp", "r", stdin);
	//freopen("TOHOP.out", "w", stdout);
	std::cin >> n >> k;
	for (int i = 0; i < k; i++) std::cin >> a[i];
	//sort a
}

void Next() {
	int ii;
	for (ii = k - 1; ii >= 0; ii--)
		if (a[ii] < n - k + ii + 1) break;
	
	if (ii < 0) {
		std::cout << -1;
		return;
	}

	for (int i = 0; i < ii; i++) std::cout << a[i] << " ";
	int d = a[ii] + 1;
	std::cout << d << " ";
	for (int i = ii + 1; i < k; i++) {
		d++;
		std::cout << d << " ";
	}
}

void Prev() {
	int ii;
	for (ii = k - 1; ii > 0; ii--) {
		if (a[ii] - a[ii - 1] >= 2) break;
	}
	if (ii == 0 && a[ii] == 1) {
		std::cout << -1;
		return;
	}
	for (int i = 0; i < ii; i++) std::cout << a[i] << " ";
	std::cout << a[ii] - 1 << " ";
	for (int i = ii + 1; i < k; i++) {
		std::cout << n - k + i + 1 << " ";
	}
}

int main() {
	Prepare();
	Prev();
	std::cout << '\n';
	Next();
	
}
