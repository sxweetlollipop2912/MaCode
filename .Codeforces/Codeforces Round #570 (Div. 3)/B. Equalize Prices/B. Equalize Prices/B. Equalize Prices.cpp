#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 101

typedef int maxn;
typedef long maxa;

maxn n;
maxa a[maxN], k;


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		std::cin >> n >> k;
		for (maxn i = 0; i < n; i++) std::cin >> a[i];
		std::sort(a, a + n);
		if (a[0] + k >= a[n - 1] - k) std::cout << a[0] + k << '\n';
		else std::cout << "-1\n";
	}
}