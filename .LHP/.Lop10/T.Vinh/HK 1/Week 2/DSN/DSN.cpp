// full test

#include "pch.h"
#include <iostream>

long a[100001], n;

void input() {
	std::cin >> n;
	if ((n < 1) | (n > 100000)) throw "Khong hop le";
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if ((a[i] < 1) | (a[i] > 1000000)) throw "Khong hop le";
	}
}


int main() {
	input();
	long s[100001], top = -1;
	for (int i = 0; i < n; i++) {
		while ((top >= 0) && (a[s[top]] < a[i])) {
			a[s[top]] = 0 - i;
			top--;
		}
		s[++top] = i;
	}
	for (int i = 0; i < n; i++) std::cout << ((a[i] < 0) ? (~(a[i]-1)) + 1 : 0) << "\n";
}