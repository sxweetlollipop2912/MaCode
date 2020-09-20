#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 102

typedef int maxm, maxn;

maxn n, num[maxN], low[maxN], parent[maxN], child[maxN], CNT;
maxm m;
bool d[maxN][maxN], isArti[maxN], isBridge[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		d[u][v] = d[v][u] = 1;
	}
}


void DFS(maxn u) {
	num[u] = ++CNT;
	low[u] = maxN;

	for (maxn v = 1; v <= n; v++) {
		if (!d[u][v]) continue;
		d[v][u] = 0;
		
		if (parent[v] != -1) low[u] = std::min(low[u], num[v]);
		else {
			parent[v] = u;
			DFS(v);
			low[u] = std::min(low[u], low[v]);
		}
	}
}


void CountArticulations() {
	for (maxn v = 1; v <= n; v++)
		child[parent[v]]++;
		
	for (maxn v = 1; v <= n; v++) {
		maxn u = parent[v];
		std::cout << u << ' ' << v << ' ' << parent[u] << '\n';
		if (!u) isArti[v] = child[v] >= 2;
		else if (parent[u] && low[v] >= num[u]) isArti[u] = 1;
	}

	std::cout << "Articulations: ";
	for (maxn i = 1; i <= n; i++)
		if (isArti[i]) std::cout << i << ' ';
	std::cout << '\n';
}


void CountBridges() {
	for (maxn v = 1; v <= n; v++) {
		//std::cout << v << ' ' << low[v] << ' ' << num[v] << '\n';
		maxn u = parent[v];
		if (u && low[v] >= num[v]) isBridge[v] = 1;
	}

	std::cout << "Bridges:\n";
	for (maxn v = 1; v <= n; v++)
		if (isBridge[v]) std::cout << parent[v] << ' ' << v << '\n';
}


void Process() {
	std::fill(parent, parent + n + 1, -1);
	for (maxn i = 1; i <= n; i++) {
		if (parent[i] != -1) continue;
		parent[i] = 0;
		DFS(i);
	}
	//CountBridges();
	CountArticulations();
}


int main() {
	Prepare();
	Process();
}


