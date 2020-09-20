#include <iostream>
#include <algorithm>
#include <cstdio>

long n;

int main() {
	//freopen("digits.inp", "r", stdin);
	//freopen("digits.out", "w", stdout);

	std::cin >> n;
	if (n == 1) std::cout << 1;
	else if (n == 2) std::cout << 2;
	else if (n == 3) std::cout << 6;
	else if (n == 4) std::cout << 6;
	else if (n == 5) std::cout << 3;
	else std::cout << 9;
}