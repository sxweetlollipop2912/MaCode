#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102

typedef int maxn;

maxn n, m;
maxn root[maxN], size[maxN];


maxn Root(maxn x) {
	while (x != root[x]) x = root[x];
	return x;
}


void Union(maxn x, maxn y) {
	x = Root(x), y = Root(y);

	if (x == y) return;

	if (size[x] < size[y]) root[x] = y, size[y] += size[x];
	else root[y] = x, size[x] += size[y];
}


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i <= m; i++) root[i] = i;

	for (maxn i = 0; i < n; i++) {
		maxn cnt, X; std::cin >> cnt;
		if (!cnt) {
			++size[0];
			continue;
		}
		std::cin >> X; ++size[Root(X)];
		while (--cnt) {
			maxn x; std::cin >> x;
			Union(X, x);
		}
	}
}


void Process() {
	maxn CNT = 0;
	for (maxn i = 1; i <= m; i++) CNT += (Root(i) == i && size[i]);

	std::cout << size[0] + std::max(CNT - 1, (maxn)0);
}


int main() {
	//freopen("ngaoaingu.inp", "r", stdin);
	//freopen("ngoaingu.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}