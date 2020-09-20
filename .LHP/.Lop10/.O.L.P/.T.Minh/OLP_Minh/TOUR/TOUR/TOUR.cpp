#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 1001
#define maxK 12
#define maxM 1000001

typedef int maxn;
typedef long maxm;

maxn n, k, K[maxK];
maxm m;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> k >> m;

	for (maxn i = 0; i <= k; i++) std::cin >> K[i];

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


maxm re[maxN];
std::queue <maxn> bfs;


bool Fill(maxn u, maxn des) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (re[u] + 1 >= re[v]) continue;

		re[v] = re[u] + 1;
		bfs.push(v);

		if (v == des) return 1;
	}
	return 0;
}


maxm BFS(maxn S, maxn des) {
	std::fill(re, re + n, maxM);
	re[S] = 0;
	bfs.push(S);

	while (!Fill(bfs.front(), des)) 
		bfs.pop();

	return re[des];
}


void Process() {
	maxm res = 0;

	for (maxn i = 0; i < k; i++) 
		res += BFS(K[i], K[i + 1]);

	std::cout << res;
}


int main() {
	Prepare();
	Process();
}