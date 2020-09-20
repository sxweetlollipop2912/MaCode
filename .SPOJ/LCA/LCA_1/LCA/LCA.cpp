// AC SPOJ
// Sparse table, nlogn preprocess, logn each query
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

#define maxN 1002
#define maxS 11

typedef int maxn;

maxn n, par[maxN][maxS], d[maxN];
std::vector <maxn> ad[maxN];


void Init() {
	for (maxn i = 0; i < maxN; i++) {
		ad[i].clear();
		std::fill(par[i], par[i] + maxS, 0);
	}
	std::fill(d, d + maxN, maxN);
}


void Prepare() {
	std::cin >> n;
	for (maxn u = 1; u <= n; u++) {
		maxn c; std::cin >> c;
		for (maxn ic = 0; ic < c; ic++) {
			maxn v;
			std::cin >> v;
			par[v][0] = u;
			ad[u].push_back(v);
		}
	}
	for (maxn u = 1; u <= n; u++) if (!par[u][0]) ad[0].push_back(u);
}


void DFS(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (d[v] != maxN) continue;
		d[v] = d[u] + 1;
		DFS(v);
	}
}


void BuildAnc() {
	for (maxn p = 1; (1 << p) <= n; p++) for (maxn i = 1; i <= n; i++)
		par[i][p] = par[par[i][p - 1]][p - 1];
}


maxn Anc(maxn x, maxn y) {
	if (d[x] < d[y]) std::swap(x, y);
	while (d[x] != d[y])
		x = par[x][(maxn)log2(d[x] - d[y])];

	for (maxn p = maxS - 2; p >= 0; p--)
		if (par[x][p] != par[y][p]) x = par[x][p], y = par[y][p];

	return x == y ? x : par[x][0];
}


void Process() {
	d[0] = -1;
	DFS(0);

	int q; std::cin >> q;
	while (q--) {
		maxn x, y;
		std::cin >> x >> y;
		std::cout << Anc(x, y) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q; std::cin >> q;

	for (int cntq = 1; cntq <= q; cntq++) {
		std::cout << "Case " << cntq << ":\n";
		Init();
		Prepare();
		BuildAnc();
		Process();
	}
}