// AC Kattis
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 200005
//#define maxM 100001

typedef long long maxn, maxq;

maxn n, root[maxN], size[maxN], id[maxN], CNT, sum[maxN];
maxq q;


void Prepare() {
	CNT = n;
	for (maxn i = 1; i <= n; i++) id[i] = root[i] = sum[i] = i, size[i] = 1;
}


maxn Root(maxn x) {
	while (x != root[x]) x = root[x];
	return x;
}


void Seperate(maxn x) {
	maxn x1 = Root(id[x]);
	sum[x1] -= x, --size[x1];

	id[x] = ++CNT;
	root[id[x]] = id[x], sum[id[x]] = x, size[id[x]] = 1;
}


void Union(maxn x, maxn y) {
	x = Root(id[x]), y = Root(id[y]);

	if (x == y) return;

	if (size[x] < size[y]) root[x] = y, size[y] += size[x], sum[y] += sum[x];
	else root[y] = x, size[x] += size[y], sum[x] += sum[y];
}


void Process() {
	while (q--) {
		int opt; std::cin >> opt;

		if (opt == 1) {
			maxn u, v; std::cin >> u >> v;
			Union(u, v);
		}
		else if (opt == 2) {
			maxn u, v; std::cin >> u >> v;
			if (Root(id[u]) == Root(id[v])) continue; //**//
			Seperate(u);
			Union(u, v);
		}
		else if (opt == 3) {
			maxn u; std::cin >> u, u = Root(id[u]);
			std::cout << size[u] << ' ' << sum[u] << '\n';
		}
	}
}


int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> q) {
		Prepare();
		Process();
	}
}