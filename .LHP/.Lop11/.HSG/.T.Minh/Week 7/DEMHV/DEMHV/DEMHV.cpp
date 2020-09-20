#include <iostream>
#include <cstdio>

#define maxN ((maxn)100001)
#define MOD ((maxn)1000000007)

typedef long long maxn;

maxn n, key, fac[maxN], res, LOW, HIGH;


void Prepare() {
	HIGH = n - key, LOW = key - 1;
}


maxn power(maxn base, maxn x) {
	maxn re = 1;
	while (x) {
		if (x & 1) re = (re * base) % MOD;
		base = (base * base) % MOD, x >>= 1;
	}
	return re;
}


maxn P(maxn n, maxn k) {
	return (fac[n] * power(fac[n - k], MOD - 2)) % MOD;
}


void DFS(const maxn l, const maxn r, const maxn cntl, const maxn cnth) {
	if (l > r || cntl > LOW || cnth > HIGH) return;
	res = (res + (((P(LOW, cntl) * P(HIGH, cnth)) % MOD) * (fac[n - cntl - cnth - 1])) % MOD) % MOD;

	maxn m = (l + r + 1) / 2;
	DFS(l, m - 1, cntl, cnth + 1);
	DFS(m + 1, r, cntl + 1, cnth);
}


void Process() {
	res = 0;
	DFS(1, n, 0, 0);
	std::cout << res << '\n';
}


int main() {
	//freopen("demhv.inp", "r", stdin);
	//freopen("demhv.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	fac[0] = 1;
	for (maxn i = 1; i < maxN; i++) fac[i] = (fac[i - 1] * i) % MOD;

	while (std::cin >> n >> key) {
		Prepare();
		Process();
	}
}