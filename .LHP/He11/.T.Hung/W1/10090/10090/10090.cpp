#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxA 2e9 + 1;

typedef long long maxa;

maxa n, n1, n2, c1, c2;


void Prepare() {
	std::cin >> n >> c1 >> n1 >> c2 >> n2;
}


// store x, y, and d as global variables 
void extendedEuclid(int a, int b) { 
	if (b == 0) { 
		x = 1; y = 0; d = a; return; 
	} // base case extendedEuclid(b, a % b); // similar as the original gcd 
	int x1 = y; int y1 = x - (a / b) * y; x = x1; y = y1; 
}
