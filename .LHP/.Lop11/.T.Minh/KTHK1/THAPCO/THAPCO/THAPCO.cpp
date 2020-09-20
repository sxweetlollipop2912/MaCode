#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1000002
//#define maxA 1000000001

typedef long long maxn, maxa;

const maxn MOD = 1e9 + 9;

maxn n, res;
maxa D, a[maxN];


void Prepare() {
	std::cin >> n >> D;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a, a + n);
}


void Process() {
	res = 1;
	for (maxn l = 0, r = 1; r < n; ++r) {
		while (a[r] - a[l] > D) ++l;
		res = (res * (r - l) + res) % MOD;
	}
	std::cout << res;
}


int main() {
	//freopen("thapco.inp", "r", stdin);
	//freopen("thapco.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}