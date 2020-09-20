#include "pch.h"
#include <iostream>

int num[10];

int main() {
	int len = 0, n;
	
	std::cin >> n;
	while (n != 0) {
		num[len++] = n % 10;
		n /= 10;
	}

	long long res = 0;
	num[0]--;
	for (int i = 0; i < len; i++) {
		std::cout << num[i] << ' ';
		num[i]++;
		if (num[i]) res += 10 - num[i];
		std::cout << res << '\n';
	}

	std::cout << res;
}