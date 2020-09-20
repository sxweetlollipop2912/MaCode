#include "pch.h"
#include <iostream>
#include <algorithm>

typedef long maxq;
typedef long long maxa;


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	maxq q;
	std::cin >> q;

	while (q--) {
		maxa k, n, a, b;
		std::cin >> k >> n >> a >> b;
		maxa tmp = b * n;
		if (tmp >= k) std::cout << "-1\n";
		else std::cout << std::min(n, ((k - 1 - tmp) / (a - b))) << '\n';
	}
}