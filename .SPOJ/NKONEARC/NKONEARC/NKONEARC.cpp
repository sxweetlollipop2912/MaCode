#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define maxN 2002
#define maxM 30002

typedef int maxn, maxm;

maxn n, low[maxN], fin[maxN];
maxm m;
std::vector <maxn> ad[maxN], ad_scc[maxN], comp;
bool done[maxN], num[maxN], par[maxN], scc[maxN][maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		ad[u].push_back(v);
	}
}


void DFS_SCC(maxn u) {
	num[u] = 1;
	low[u] = u;
	comp.push_back(u);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v]) continue;

		if (num[v]) low[u] = std::min(low[u], v);
		else {
			DFS_SCC(v);
			low[u] = std::min(low[u], low[v]);
		}
	}

	if (u != low[u]) return;

	maxn v;
	do {
		v = comp.back();
		done[v] = 1;
		low[v] = low[u];
		comp.pop_back();
	} while (u != v);
}


void Process_SCC() {
	for (maxn u = 1; u <= n; u++)
		if (!num[u]) DFS_SCC(u);

	for (maxn u = 1; u <= n; u++) {
		/*while (!ad[u].empty()) {
			maxn v = ad[u].back();
			ad[u].pop_back();
			if (low[u] == low[v] || scc[low[u]][low[v]]) continue;

			scc[low[u]][low[v]] = 1;
			ad_scc[low[u]].push_back(low[v]);
		}*/
		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (low[u] == low[v] || scc[low[u]][low[v]]) continue;

			scc[low[u]][low[v]] = 1;
			ad_scc[low[u]].push_back(low[v]);
		}
	}
}


maxn DFS_FIN(maxn u) {
	if (done[u]) return fin[u];
	done[u] = 1;
	fin[u] = u;

	for (maxn i = 0; i < ad_scc[u].size(); i++) {
		maxn v = ad_scc[u][i];
		par[v] = 1;
		fin[u] = DFS_FIN(v);
	}

	return fin[u];
}


void Process_FIN() {
	std::fill(done, done + n + 1, 0);
	for (maxn u = 1; u <= n; u++) {
		if (!done[low[u]]) DFS_FIN(low[u]);
	}

	for (maxn i = 1; i <= n; i++) {
		if (i == low[i] && low[i] == fin[low[i]]) comp.push_back(i);
	}

	for (maxn i = 1; i <= n; i++) {
		if (i == low[i] && !par[low[i]]) comp.push_back(i);
	}
}


void Process() {
	Process_SCC();
	Process_FIN();
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();

	if (comp.size() != 2) std::cout << "NO";
	else std::cout << "YES\n" << comp[0] << ' ' << comp[1];
}