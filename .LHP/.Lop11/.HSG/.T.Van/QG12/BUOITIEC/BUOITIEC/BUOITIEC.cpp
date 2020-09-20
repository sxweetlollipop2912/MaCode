#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 701
#define maxM 10001

typedef int maxn, maxm;

maxn n;
maxm m;
bool done[maxN], block[maxN][4];
int col[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		ad[u].push_back(v); ad[v].push_back(u);
	}
}


void DFS(const maxn u, const bool c) {
	done[u] = 1, col[u] = c;
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v] && col[u] == col[v]) col[u] = 2;
		else if (!done[v]) DFS(v, !c);
	}
}