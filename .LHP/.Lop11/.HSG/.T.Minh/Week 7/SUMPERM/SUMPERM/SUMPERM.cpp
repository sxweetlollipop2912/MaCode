#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define MOD ((maxr)366239)

typedef long maxn, maxb;
typedef long long maxr;

maxn n;
maxr m10, fac, sum;


void Prepare() {
	std::string s; std::cin >> s;
	n = s.size();
	for (maxn i = 0; i < n; i++) sum += (maxr)s[i] - (maxr)'0';
}


void Process() {
	m10 = 1;
	for (maxn i = 2; i <= n; i++) m10 = (m10 * 10 + 1) % MOD;

	fac = 1;
	for (maxn i = 2; i < n; i++) fac = (fac * i) % MOD;

	std::cout << (((sum * m10) % MOD) * fac) % MOD;
}


int main() {
	//freopen("sumperm.inp", "r", stdin);
	//freopen("sumperm.out", "w", stdout);

	Prepare();
	Process();
}