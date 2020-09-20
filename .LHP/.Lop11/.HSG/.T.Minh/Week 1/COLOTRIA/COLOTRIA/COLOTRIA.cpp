#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1001

typedef long long maxn, maxm, maxr;

maxn n, cnt[maxN];
maxm m;
maxr res;


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		++cnt[u], ++cnt[v];
	}
}


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++) {
		res += ((cnt[i] * (n - (maxr)1 - cnt[i])));
	}
	std::cout << (n * (n - 1) * (n - 2) / 6) - (res / 2);
}


int main() {
	freopen("colotria.inp", "r", stdin);
	freopen("colotria.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}