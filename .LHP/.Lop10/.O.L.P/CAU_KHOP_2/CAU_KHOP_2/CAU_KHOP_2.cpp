#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
 
#define maxN 102

typedef int maxn;

maxn n, m, low[maxN], num[maxN], par[maxN], child[maxN], CNT;
std::vector <maxn> ad[maxN];
bool isArti[maxN], isBridge[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void DFS(maxn u) {
	low[u] = num[u] = ++CNT;
	child[u] = 0;
	
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];

		if (!par[v]) {
			par[v] = u;
			DFS(v);

			low[u] = std::min(low[u], low[v]);
			child[u]++;
		}

		else if (par[u] != v) 
			low[u] = std::min(low[u], num[v]);
	}
}


void CountArticulations() {
	for (maxn v = 1; v <= n; v++) {
		maxn u = par[v];
		if (u == v) isArti[v] = child[v] > 1;
		else if (par[u] != u && low[v] >= num[u]) isArti[u] = 1;
	}

	std::cout << "Articulations: ";
	for (maxn i = 1; i <= n; i++)
		if (isArti[i]) std::cout << i << ' ';
	std::cout << '\n';
}


void CountBridges() {
	for (maxn v = 1; v <= n; v++) {
		maxn u = par[v];
		if (low[v] > num[u]) isBridge[v] = 1;
	}

	std::cout << "Bridges:\n";
	for (maxn v = 1; v <= n; v++) {
		if (isBridge[v]) std::cout << par[v] << ' ' << v << '\n';
	}
}


void Process() {
	for (maxn u = 1; u <= n; u++) {
		if (par[u]) continue;
		par[u] = u;
		DFS(u);
	}
	CountBridges();
	CountArticulations();
}


int main() {
	Prepare();
	Process();
}