#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define maxN 102

typedef int maxn, maxm;

maxn n, cnt[maxN], group[maxN], CNT;
maxm m;
bool d[maxN][maxN], del[maxN];
std::vector <maxn> comp;


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		d[u][v] = 1;
	}
}


void DFS(maxn u) {
	cnt[u] = ++CNT;
	group[u] = cnt[u];
	comp.push_back(u);

	for (maxn v = 1; v <= n; v++) {
		if (del[v] || !d[u][v]) continue;
		if (cnt[v]) group[u] = std::min(group[u], cnt[v]);
		else {
			DFS(v);
			group[u] = std::min(group[u], group[v]);
		}
	}

	if (group[u] != cnt[u]) return;

	maxn v;
	do {
		v = comp.back();
		del[v] = 1;
		std::cout << v << ' ';
		comp.pop_back();
	} while (v != u);

	std::cout << '\n';
}


void Process() {
	CNT = 0;
	for (maxn i = 1; i <= n; i++)
		if (!cnt[i]) DFS(i);
}


int main() {
	Prepare();
	Process();
}