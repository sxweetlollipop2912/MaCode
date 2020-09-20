#include "pch.h"
#include <iostream>
#include <algorithm>
#include <math.h>

#define maxN 1001

typedef int maxn;

maxn n, m;


void Prepare() {
	std::cin >> n;
}


void Process() {
	m = ceil((n - 1 + 2) / (double)2);
	std::cout << m << '\n';

	maxn co[2] = { 1,1 };
	while (n--) {
		std::cout << co[0] << ' ' << co[1] << '\n';
		++co[n % 2];
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}