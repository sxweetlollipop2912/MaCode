#include "pch.h"
#include <iostream>

int main() {
	char S, R;
	std::cin >> R >> S;

	for (int i = 0; i < 5; i++) {
		char r, s;
		std::cin >> r >> s;
		
		if (r == R || s == S) {
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";
}