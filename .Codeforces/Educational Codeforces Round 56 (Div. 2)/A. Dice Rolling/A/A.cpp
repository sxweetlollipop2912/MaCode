// AC
#include "pch.h"
#include <iostream>

#define maxT 101

int t;

int main() {
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int q, re = 0;
		std::cin >> q;
		re = q / 7;
		if (q % 7 != 0) re++;
		std::cout << re << '\n';
	}
}