// AC
#include "pch.h"
#include <iostream>

int n, s;
bool a[1000];

bool Prepare_Re() {
	
	std::cin >> n >> s >> a[0];
	s--;

	if (!a[0]) return 0;
	if (s == 0) return 1;
	
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		if (i == s && a[i]) return 1;
	}

	bool c;
	for (int i = 0; i <= s; i++) 
		std::cin >> c;
	if (!c) return 0;

	for (int i = s + 1; i < n; i++) {
		std::cin >> c;
		if (c && a[i]) return 1;
	}
	return 0;
}

int main() {
	bool re = Prepare_Re();
	if (re) std::cout << "YES";
	else std::cout << "NO";
}