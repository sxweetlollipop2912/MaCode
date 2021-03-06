#include "pch.h"
#include <iostream>

typedef int maxa, maxn;

maxn n;
maxa a[16];


bool Try(maxn i, maxa t) {
	if (i == n) return t % 360 == 0;
	if (Try(i + 1, t + a[i])) return true;
	if (Try(i + 1, t - a[i])) return true;
	return false;
}


int main() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) 
		std::cin >> a[i];

	if (Try(0, 0)) std::cout << "YES";
	else std::cout << "NO";
}