#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 10002

typedef int maxn;
typedef long maxa;

maxn n, K;
maxa a[maxN], f[maxN];


void Prepare() {
	std::cin >> n >> K;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
	maxa mx = 0;
	for (maxn i = 1; i <= n; i++, mx = 0) for (maxn j = 0; j < K && i > j; j++) {
		mx = std::max(mx, a[i - j]);
		f[i] = std::max(f[i], mx * (j + 1) + f[i - j - 1]);
	}
	std::cout << f[n];
}


int main() {
	//freopen("teamwork.inp", "r", stdin);
	//freopen("teamwork.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}