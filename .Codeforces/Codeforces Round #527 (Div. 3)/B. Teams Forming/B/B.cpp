#include "pch.h"
#include <iostream>
#include <algorithm>

int n, a[101];

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
	int re = 0;
	for (int i = 1; i < n; i += 2) re += a[i] - a[i - 1];
	std::cout << re;
}