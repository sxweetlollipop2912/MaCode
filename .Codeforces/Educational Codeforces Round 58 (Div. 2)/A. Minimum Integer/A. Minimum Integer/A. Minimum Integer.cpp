#include "pch.h"
#include <iostream>

typedef long long maxn;

maxn l, r, d;

void Process() {
	std::cin >> l >> r >> d;

	maxn re = ((r / d) + 1) * d;

	if (d < l) std::cout << d << '\n';
	else std::cout << re << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int q;
	std::cin >> q;

	while (q--) Process();
}