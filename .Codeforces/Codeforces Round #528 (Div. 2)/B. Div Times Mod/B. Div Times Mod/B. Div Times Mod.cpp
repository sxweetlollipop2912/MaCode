#include "pch.h"
#include <iostream>

#define maxK 1001
#define maxN 1000001

typedef long maxn;

maxn n, k, u;


void Prepare() {
	std::cin >> n >> k;
}


bool check() {
	return n % u == 0;
}


int main() {
	Prepare();

	for (u = k - 1; u >= 0; u--) 
		if (check()) break;

	u = k * (n / u) + u;
	std::cout << u;
}