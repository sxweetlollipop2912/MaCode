// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 27
#define maxM 677
#define awake 3
#define darkness -1
#define id(x) x - 'A'

typedef int maxn, maxm;

maxn n, connect[maxN], CNT;
maxm m;
std::vector <maxn> ad[maxN];
std::queue <maxn> bfs;


void Prepare() {
	for (maxn i = 0; i < awake; i++) {
		char c;
		std::cin >> c;
		connect[id(c)] = awake;
		bfs.push(id(c));
	}

	for (maxm i = 0; i < m; i++) {
		char u, v;
		std::cin >> u >> v;
		ad[id(u)].push_back(id(v));
		ad[id(v)].push_back(id(u));
	}
}


void Init() {
	for (maxn i = 0; i < maxN; i++)
		ad[i].clear();
	
	bfs = std::queue <maxn>();
	std::fill(connect, connect + maxN, 0);
	CNT = 0;
}


maxn BFS() {
	maxn res_year = 0;

	while (!bfs.empty()) {
		maxn oney = bfs.size();

		while (oney--) {
			maxn u = bfs.front();
			bfs.pop();

			for (maxn i = 0; i < ad[u].size(); i++) {
				maxn v = ad[u][i];
				++connect[v];

				if (connect[v] != awake) continue;
				bfs.push(v);
				CNT++;
			}
		}

		++res_year;
	}
	
	return CNT != n ? darkness : res_year - 1;
}


void Process() {
	CNT = awake;
	maxn res = BFS();

	if (res == darkness) std::cout << "THIS BRAIN NEVER WAKES UP\n";
	else std::cout << "WAKE UP IN, " << res << ", YEARS\n";
}


int main() {
	//freopen("10507.inp", "r", stdin);
	//freopen("10507.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> m) {
		Init();
		Prepare();
		Process();
	}
}