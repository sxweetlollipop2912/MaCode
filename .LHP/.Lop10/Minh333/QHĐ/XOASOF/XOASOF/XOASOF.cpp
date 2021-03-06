// test 1000
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)
#define maxN 1000002
#define maxA 10001

typedef long maxn;
typedef int maxa;

maxn n;
unsigned long f[maxN];


void Prepare() {
	//freopen("XOASOF.inp", "r", stdin);
	//freopen("XOASOF.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);

	std::cin >> n;
}


/*void Trace() {

	unsigned long re = n - 1;

	for (maxn i = n - 2; i >= n - 3 && i >= 0; i--)
		if (f[i] < f[re])
			re = i;

	std::cout << f[re] - 1 << '\n' << re << ' ';

	unsigned long pos_mi = re - 1;

	while (re > 3) {

		for (maxn i = re - 1; i >= re - 3 && i >= 0; i--) 
			if (f[i] < f[pos_mi]) pos_mi = i;

		std::cout << pos_mi << ' ';
		re = pos_mi;
		pos_mi--;
	}
}*/


int main() {
	Prepare();

	std::cin >> f[1] >> f[2] >> f[3];

	maxa a;
	for (maxn i = 4; i <= n; i++) {
		std::cin >> a;
		unsigned long min = *std::min_element(f + i - 3, f + i);
		f[i] = a + min;
		//std::cout << min << ' ' << a << ' ';
	}


	//for (maxn i = n - 2; i <= n; i++) std::cout << f[i] << ' ';
	//Trace();
	std::cout << *std::min_element(f + n - 3, f + n) << ' ' << std::min(f[n - 1], std::min(f[n - 2], f[n - 3]));
}