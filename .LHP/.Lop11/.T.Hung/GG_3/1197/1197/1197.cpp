// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning(disable:4996)

#define maxN 30001

typedef int maxn;

maxn n, m, par[maxN], size[maxN];


maxn Root(maxn x) {
	while (x != par[x]) x = par[x];
	return x;
}

void Union(maxn x, maxn y) {
	x = Root(x), y = Root(y);
	if (x == y) return;

	if (size[x] > size[y]) par[y] = x, size[x] += size[y];
	else par[x] = y, size[y] += size[x];
}


void Prepare() {
	std::cin >> m;

	for (maxn i = 0; i < n; i++) par[i] = i, size[i] = 1;

	for (maxn i = 0; i < m; i++) {
		maxn cnt; std::cin >> cnt;
		if (!cnt) continue;
		maxn a; std::cin >> a;
		while (--cnt) {
			maxn x; std::cin >> x;
			Union(a, x);
		}
	}
}


void Process() {
	std::cout << size[Root(0)] << '\n';
}


int main() {
	//freopen("1197.inp", "r", stdin);
	//freopen("1197.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}