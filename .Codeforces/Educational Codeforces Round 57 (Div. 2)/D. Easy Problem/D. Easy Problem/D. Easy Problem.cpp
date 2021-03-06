#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100001
#define maxA 998244353

typedef unsigned long long maxn, maxa, maxf;

maxn s[maxN];
maxf f[6];
maxn n;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		if (c == 'h') s[i] = 1;
		else if (c == 'a') s[i] = 2;
		else if (c == 'r') s[i] = 3;
		else if (c == 'd') s[i] = 4;
		else s[i] = 0;
	}
}


void Process() {

	for (maxn i = 0; i < n; i++) {
		maxa a;
		std::cin >> a;

		maxn x = s[i];
		if (!x) continue;

		if (x == 1) f[1] += a;
		else f[x] = std::min(f[x - 1], f[x] + a);
	}
}


int main() {
	Prepare();
	Process();
	std::cout << f[4];
}