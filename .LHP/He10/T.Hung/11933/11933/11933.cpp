// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

typedef long long maxa;


void Process(const maxa a) {
	maxa res[2] = { 0,0 };
	bool p = 1;
	maxa tmp = 1;

	while (tmp <= a) {
		if (tmp & a) {
			p = !p;
			res[p] |= tmp;
		}
		tmp <<= 1;
	}

	std::cout << res[0] << ' ' << res[1] << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);

	maxa a;
	while (std::cin >> a && a != 0)
		Process(a);
}