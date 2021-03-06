// directed graph
#include "pch.h"
#include <iostream>
#include <vector>

#define maxN 1000
#define maxV 1000000

typedef int maxn;
typedef long maxv;

std::vector <maxn> adj[maxN], circut;
maxn n;
maxv V;


bool Prepare() {
	std::cin >> n >> V;

	maxv check[maxN];

	for (maxv i = 0; i < V; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		check[u]++; check[v]++;
		adj[u].push_back(v);
	}

	for (maxn i = 0; i < n; i++)
		if (check[i] % 2) return 0;
	return 1;
}


void Hierholzer() {
	std::vector <maxn> stack;
	maxn cur = 0;

	stack.push_back(cur);

	while (!stack.empty()) {

		if (!adj[cur].empty()) {
			stack.push_back(cur);

			maxn tmp = adj[cur].back();
			adj[cur].pop_back();
			cur = tmp;
		}

		else {
			circut.push_back(cur);
			cur = stack.back();
			stack.pop_back();
		}
	}
}


int main() {
	if (!Prepare()) {
		std::cout << -1;
		return 0;
	}

	Hierholzer();
	for (maxv i = circut.size() - 1; i >= 0; i--) std::cout << circut[i] << ' ';
}