// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 500002

typedef long maxn;

maxn n, mx[maxN], mx2[maxN], res[maxN], par[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i < n; i++) {
		maxn u, v; std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	ad[0].push_back(1);
}


void DFS_1(const maxn u) {
	mx[u] = 1, mx2[u] = 0;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (mx[v]) continue;
		par[v] = u; DFS_1(v);
		if (mx[v] + 1 > mx[u]) mx2[u] = mx[u], mx[u] = mx[v] + 1;
		else if (mx[v] + 1 > mx2[u]) mx2[u] = mx[v] + 1;
 	}
}


void DFS_2(const maxn u) {
	res[u] = res[par[u]] + 1;

	if (mx[u] + 1 == mx[par[u]]) res[u] = std::max(res[u], mx2[par[u]] + 1);
	else res[u] = std::max(res[u], mx[par[u]] + 1);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (res[v]) continue;
		DFS_2(v);
	}

	res[u] = std::max(res[u], mx[u]);
}


void Process() {
	DFS_1(0); mx[0] = 0;
	DFS_2(1);
	for (maxn i = 1; i <= n; i++) std::cout << res[i] << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}