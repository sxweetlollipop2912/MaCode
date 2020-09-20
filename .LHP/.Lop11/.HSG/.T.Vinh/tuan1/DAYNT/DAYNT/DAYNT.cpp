#include <iostream>
#include <algorithm>
#include <cstdio>

//#define maxN 1002
#define maxC 10005
#define MOD (maxa)1000000007

typedef int maxn;
typedef long long maxa;

maxn n, C;
maxa f[2][maxC], sum[2][maxC];


void Prepare() {
	std::cin >> n >> C;
}


void Process() {
	bool p = 0;

	f[p][1] = 1;
	for (maxn i = 1; i <= C + 1; i++) sum[p][i] = (f[p][i] + sum[p][i - 1]) % MOD;

	for (maxn i = 2; i <= n; i++) {
		p = !p;
		for (maxn c = 1; c <= C + 1; c++) {
			f[p][c] = (((sum[!p][c] - sum[!p][std::max(0, c - i)]) % MOD) + MOD) % MOD;
			sum[p][c] = (f[p][c] + sum[p][c - 1]) % MOD;
		}
	}
	std::cout << f[p][C + 1];
}


int main() {
	//freopen("daynt.inp", "r", stdin);
	//freopen("daynt.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}