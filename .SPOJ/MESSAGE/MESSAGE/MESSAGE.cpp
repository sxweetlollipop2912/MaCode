#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define maxN 802
#define unvisited 0

typedef int maxn;

maxn n, m, low[maxN], num[maxN], par[maxN], NUM, CNT;
std::vector <maxn> ad[maxN], comp;
bool done[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		ad[u].push_back(v);
	}
}


void DFS(maxn u) {
	num[u] = ++NUM;
	low[u] = num[u];
	comp.push_back(u);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v]) continue;

		if (num[v] == unvisited) {
			DFS(v);
			low[u] = std::min(low[u], low[v]);
		}
		else low[u] = std::min(low[u], num[v]);
	}

	if (num[u] != low[u]) return;

	CNT++;
	maxn v;
	do {
		v = comp.back();
		done[v] = 1;
		low[v] = low[u];

		comp.pop_back();
	} while (v != u);
}



void Process() {
	NUM = 0;
	for (maxn u = 1; u <= n; u++) {
		if (num[u] == unvisited) DFS(u);
	}

	for (maxn u = 1; u <= n; u++) {
		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (par[low[v]]) continue;

			if (low[u] != low[v]) par[low[v]] = 1;
			CNT -= par[low[v]];
		}
	}

	std::cout << CNT;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}