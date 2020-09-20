#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100001
#define MOD	5000011

typedef long maxn;
typedef long long maxa;

maxn n, k;
maxa res, f[maxN];


void Prepare() {
	std::cin >> n >> k;
}


void Process() {
	f[0] = 1, res = 1 + f[0];
	for (maxn i = 1; i <= k; i++) f[i] = f[i - 1], res = (res + f[i]) % MOD;
	for (maxn i = k + 1; i < n; i++) f[i] = (f[i - 1] + f[i - k - 1]) % MOD, res = (res + f[i]) % MOD;
	std::cout << res;
}


int main() {
	//freopen("bieudien.inp", "r", stdin);
	//freopen("bieudien.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}