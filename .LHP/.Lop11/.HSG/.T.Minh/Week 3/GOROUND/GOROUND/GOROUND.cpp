#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 4001
#define maxK 1000002
#define MOD (maxa)1000000007

typedef int maxn;
typedef long long maxa;

maxn n, K;
maxa f[maxK], res;


void Prepare() {
	std::cin >> n >> K;

	f[0] = 1;
	for (maxa i = 1; i <= K; i++) f[i] = (i * f[i - 1]) % MOD;
}


maxa power(maxa x, maxa y) {
	maxa re = 1;
	while (y != 0) {
		if (y & 1) re = (re * x) % MOD;
		x = (x * x) % MOD, y >>= 1;
	}
	return re;
}


void Process() {
	res = 0;
	for (maxn i = 0; i <= (K >> 1); i++) {
		if (((K - i) - i) % n != 0) continue;
		res = (res + ((maxa)2 - ((i << 1) == K)) * ((((f[K] * power(f[i], MOD - 2)) % MOD) * power(f[K - i], MOD - 2)) % MOD)) % MOD;
	}
	std::cout << res;
}


int main() {
	//freopen("goround.inp", "r", stdin);
	//freopen("goround.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}