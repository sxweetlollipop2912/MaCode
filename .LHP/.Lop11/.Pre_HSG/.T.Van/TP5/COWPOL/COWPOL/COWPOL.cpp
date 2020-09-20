#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 200002

typedef long maxn;

maxn n, K, par[maxN], d[maxN];
std::vector <maxn> ad[maxN], frac[maxN];


void Prepare() {
	std::cin >> n >> K;
	for (maxn i = 1; i <= n; i++) {
		maxn f;
		std::cin >> f >> par[i];
		frac[--f].push_back(i);
		ad[par[i]].push_back(i);
	}
	std::fill(d, d + n + 1, maxN);
}


void DFS(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (d[v] != maxN) continue;
		d[v] = d[u] + 1;
		DFS(v);
	}
}


maxn anc(maxn x, maxn y) {
	//std::cout << x << ' ' << y << ' ';
	while (x != y) {
		while (d[x] > d[y]) x = par[x];
		while (d[y] > d[x]) y = par[y];
		if (x != y) x = par[x], y = par[y];
	}
	//std::cout << x << '\n';
	return x;
}


void Process() {
	d[0] = -1;
	DFS(0);

	//for (maxn i = 0; i <= n; i++) std::cout << d[i] << '\n';
	for (maxn k = 0; k < K; k++) {
		maxn lowest = frac[k][0], re = 0;
		for (maxn i = 1; i < frac[k].size(); i++) if (d[frac[k][i]] > d[lowest]) lowest = frac[k][i];
		for (maxn i = 0; i < frac[k].size(); i++) re = std::max(re, d[frac[k][i]] + d[lowest] - 2 * d[anc(frac[k][i], lowest)]);
		std::cout << re << '\n';
	}
}


int main() {
	//freopen("cowpol.inp", "r", stdin);
	//freopen("cowpol.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}