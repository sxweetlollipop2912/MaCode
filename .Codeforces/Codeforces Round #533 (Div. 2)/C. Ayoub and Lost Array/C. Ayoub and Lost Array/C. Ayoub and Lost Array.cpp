#include "pch.h"
#include <iostream>

#define maxN 200001
#define maxA 1000000001
#define maxR 1000000007
#define MOD 1000000007

typedef long long maxn, maxa, maxr;

maxr f[maxN][3], s0, s1, s2;
maxn n;
maxa l, r;


void Prepare() {
	std::cin >> n >> l >> r;

	maxa R = r / 3, L = l / 3;

	s0 = f[1][0] = (R - (L - (l % 3 == 0))) % MOD;
	s1 = f[1][1] = ((R + (r % 3 != 0)) % MOD - (L + (l % 3 == 2)) % MOD) % MOD;
	s2 = f[1][2] = ((R + (r % 3 == 2)) % MOD - L % MOD) % MOD;
}


void Process() {
	for (maxn i = 2; i <= n; i++) {
		f[i][0] = ((f[i - 1][0] * s0) % MOD + (f[i - 1][1] * s2) % MOD + (f[i - 1][2] * s1) % MOD) % MOD;
		f[i][1] = ((f[i - 1][0] * s1) % MOD + (f[i - 1][1] * s0) % MOD + (f[i - 1][2] * s2) % MOD) % MOD;
		f[i][2] = ((f[i - 1][0] * s2) % MOD + (f[i - 1][1] * s1) % MOD + (f[i - 1][2] * s0) % MOD) % MOD;
	}
}


int main() {
	Prepare();
	Process();
	std::cout << f[n][0];
}