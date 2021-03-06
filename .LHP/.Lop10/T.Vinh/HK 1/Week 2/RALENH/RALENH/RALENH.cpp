#include "pch.h"
#include <iostream>
#include <stdlib.h>



int a[1001], n, m;
bool c[1001];

bool check() {
	a[a[1]] = ~a[a[1]] + 1;
	for (int i = 2; i <= n; i++) {
		
		a[abs(a[i])] = ~a[abs(a[i])] + 1;
		if (abs(a[i - 1]) < abs(a[i])) continue;
		
		for (int j = abs(a[i]) + 1; j < abs(a[i - 1]); j++) 
			if (a[j] > 0) return false;
	}
	return true;
}



int main() {
	std::cin >> n >> m;
	if ((n < 1) | (n > 1000) | (m < 1) | (m > 25)) throw "Khong hop le";
	while (m > 0) {
		std::fill(c, c + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			if (c[a[i]] == 1) throw "Khong hop le";
			c[a[i]] = 1;
		}
		if (check()) std::cout << "yes\n";
		else std::cout << "no\n";
		m--;
	}
}