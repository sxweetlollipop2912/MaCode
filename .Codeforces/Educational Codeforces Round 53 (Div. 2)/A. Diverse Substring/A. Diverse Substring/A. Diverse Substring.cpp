// AC
#include "pch.h"
#include <iostream>

int main() {
	
	int n, p = 0;
	std::cin >> n;
	
	char c[2];
	std::cin >> c[p];

	for (int i = 1; i < n; i++) {
		
		p = 1 - p;
		std::cin >> c[p];
		
		if (c[0] != c[1]) {
			std::cout << "YES\n" << c[1 - p] << c[p];
			return 0;
		}
	}
	
	std::cout << "NO";
}