#include "pch.h"
#include <iostream>

int n, k, m;

void Process() {
	std::cin >> n >> k;
	int len = n;
	char c = 'a' - 1;
	while (c < 'a' + k - 1) {
		c++;
		for (int i = 0; i < (n / k); i++, len--) 
			std::cout << char(c);
	}
	for (len; len > 0; len--) std::cout << (char)c;
	std::cout << '\n';
}


int main() {
	std::cin >> m;
	for (int i = 0; i < m; i++) Process();
}