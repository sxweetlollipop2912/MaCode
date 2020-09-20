#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 300002

typedef long maxn, maxa;

maxn n;
maxa M, a[maxN], f[maxN];


void Prepare() {
	std::cin >> n >> M;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	f[n] = 0;
	for (maxn i = n - 1; i >= M + 1; i--) {
		f[i] = std::max(a[i] + f[std::min(M + i, n)], f[i + 1]);
	}
	std::cout << f[M + 1];
}


int main() {
	freopen("ninja.inp", "r", stdin);
	freopen("ninja.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}