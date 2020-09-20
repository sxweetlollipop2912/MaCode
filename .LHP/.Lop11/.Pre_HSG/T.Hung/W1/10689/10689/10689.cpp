#include <iostream>
#include <algorithm>

#define maxN 15001
#define MOD 10000

typedef long maxn, maxa;

maxa a, b, n, m, f[maxN];

void Prepare() {
	std::cin >> a >> b >> n >> m;

	f[0] = a, f[1] = b;
	for (maxn i = 2; i < maxN; i++) 
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
}


