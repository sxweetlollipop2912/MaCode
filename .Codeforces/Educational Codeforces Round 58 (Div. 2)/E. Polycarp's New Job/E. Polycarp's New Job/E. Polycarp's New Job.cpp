#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 500001
#define maxA 1000000001

typedef long maxn;
typedef long maxa;

maxa low, high;


void Add() {
	maxa x, y;
	std::cin >> x >> y;

	maxa m = std::min(x, y);

	low = std::max(low, m);
	high = std::max(high, x + y - m);
}


void Check() {
	maxa h, w;
	std::cin >> h >> w;

	maxa m = std::min(h, w);

	bool re = m >= low && h + w - m >= high;

	if (re) std::cout << "YES\n";
	else std::cout << "NO\n";
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	maxn n = 0;
	std::cin >> n;

	while (n--) {
		char c;
		std::cin >> c;
		if (c == '+') Add();
		else Check();
	}
}