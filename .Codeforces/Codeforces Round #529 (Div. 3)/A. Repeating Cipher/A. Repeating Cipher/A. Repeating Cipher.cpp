// AC
#include "pch.h"
#include <iostream>

int main() {
	int l = -1, n = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		std::cin >> c;
		std::cout << c;
		l++;
		for (int j = 0; j < l; i++, j++) std::cin >> c;
	}
}