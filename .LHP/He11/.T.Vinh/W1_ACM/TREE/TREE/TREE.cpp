// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 100001

typedef long maxn;

maxn n, P[maxN], par[maxN], res;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) ad[i].clear();

	for (maxn i = 1; i < n; i++) {
		maxn u, v; std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	res = maxN;
	std::fill(par, par + n, -1);
}


maxn DFS_1(const maxn u) {
	P[u] = 0;
	maxn cnt = 0;
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[u] == v) continue;
		++cnt, par[v] = u;
		P[u] = std::max(P[u], DFS_1(v));
	}
	return (P[u] += (cnt != 0));
}


void DFS_2(const maxn u, const maxn MAX) {
	maxn max1 = -1, max2 = -1;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[u] == v) continue;
		if (P[v] > max1) max2 = max1, max1 = P[v];
		else if (P[v] > max2) max2 = P[v];
	}

	res = std::min(res, std::max(MAX, max1 + 1));

	//std::cout << u << ' ' << MAX << ' ' << max1 << ' ' << max2 << '\n';

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[u] == v) continue;
		if (P[v] == max1) DFS_2(v, std::max(MAX, max2 + 1) + 1);
		else DFS_2(v, std::max(MAX, max1 + 1) + 1);
	}
}


void Process() {
	DFS_1(0);
	DFS_2(0, 0);
	std::cout << res << '\n';
}


int main() {
	//freopen("tree.inp", "r", stdin);
	//freopen("tree.out", "w", stdout);

	std::ios_base::sync_with_stdio(0); 
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}