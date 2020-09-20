#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

#pragma warning (disable:4996)

#define maxN 500001
#define isPar(u, v) (in[u] <= in[v] && out[u] >= out[v])

typedef long maxn;

maxn n, m, CNT;
std::vector <maxn> ad[maxN], adr[maxN], ad2[maxN];
std::vector <maxn> par, pos, in, out, topo;
std::vector <bool> done;


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(v);
		adr[v].push_back(u);
	}
}


void TOPO(const maxn u) {
	done[u] = 1;
	for (maxn& v : ad[u]) 
		if (!done[v]) TOPO(v);
	topo.push_back(u);
}


void DFS(const maxn u) {
	in[u] = ++CNT;
	for (maxn& v : ad2[u]) 
		DFS(v);
	out[u] = ++CNT;
}


bool Process() {
	done.resize(n, 0);
	for (maxn i = 0; i < n; i++)
		if (!done[i]) TOPO(i);
	done.clear();

	std::reverse(topo.begin(), topo.end());

	pos.resize(n, 0);
	for (maxn i = 0; i < topo.size(); i++)
		pos[topo[i]] = i + 1;

	par.resize(n, -2);
	for (maxn i = 1; i < topo.size(); i++) {
		maxn u = topo[i], tmp = -1;

		if (!adr[u].size())
			return 0;

		for (maxn& v : adr[u])
			if (tmp == -1 || pos[tmp] < pos[v]) tmp = v;
		if (pos[tmp] > pos[u])
			return 0;

		ad2[tmp].push_back(u);
		par[u] = tmp;
		adr[u].clear();
	}
	pos.clear();
	
	in.resize(n, 0); out.resize(n, 0);
	DFS(topo[0]);

	for (maxn u = 0; u < n; u++) for (maxn& v : ad[u])
		if (!isPar(u, v)) return 0;

	std::cout << "Yes\n";
	for (maxn i = 0; i < n; i++) std::cout << par[i] + 1 << ' ';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "No";
}