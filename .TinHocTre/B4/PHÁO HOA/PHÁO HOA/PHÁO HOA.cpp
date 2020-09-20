#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 200001
#define root 0

typedef long maxn;

maxn n, m, par[maxN], h[maxN], L;
std::vector <maxn> c[maxN];


void Prepare() {
	std::cin >> n >> m;

	par[root] = root;
	for (maxn i = 1; i < n; i++) {
		std::cin >> par[i];
		--par[i];
		c[par[i]].push_back(i);
	}
}


maxn DFS(const maxn u) {
	maxn mx1 = 0, mx2 = 0;
	h[u] = 1;

	for (maxn& v : c[u]) {
		maxn mxv = DFS(v);
		if (mxv + 1 > mx1) 
			mx2 = mx1, mx1 = mxv + 1;
		else if (mxv + 1 > mx2)
			mx2 = mxv + 1;
		h[u] = std::max(h[u], h[v] + 1);
	}

	L = std::max(L, mx1 + mx2 + 1);
	return mx1;
}


void Process() {
	L = 0;
	DFS(root);
	std::cout << (L + 2 * h[root] * (m - 1));
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}