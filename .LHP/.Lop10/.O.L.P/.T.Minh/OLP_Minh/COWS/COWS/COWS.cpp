#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 1001
#define maxL 10001
#define maxR 10000001

typedef int maxn;
typedef long maxl;

maxn n, par_id[maxN], id[maxN], cnt = -1, Q;
maxl d[maxN][maxN], d_id[maxN];


void Prepare() {
	std::cin >> n >> Q;

	for (maxn i = 1; i < n; i++) {
		maxn u, v;
		maxl dist;
		std::cin >> u >> v >> dist;
		u--; v--;

		d[u][v] = d[v][u] = dist;
	}
}


void DFS(maxn u, maxl t) {
	d_id[id[u]] = t;
	
	for (maxn v = 0; v < n; v++) {
		if (id[v] != -1 || !d[u][v]) continue;

		id[v] = ++cnt;
		par_id[id[v]] = id[u];
		DFS(v, t + d[u][v]);
	}
}


void ShortestPath() {
	std::fill(id, id + n, -1);
	par_id[0] = 0;
	id[0] = ++cnt;

	DFS(0, 0);
}


maxn Intersect(maxn x, maxn y) {
	maxn par_x = x, par_y = y;

	while (par_x != par_y) {
		if (par_x > par_y) 
			par_x = par_id[par_x];

		else par_y = par_id[par_y];
	}

	return par_x;
}


maxl Res(maxn id1, maxn id2) {
	return d_id[id1] + d_id[id2] - 2 * d_id[Intersect(id1, id2)];
}


void Process() {
	while (Q--) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		std::cout << Res(id[u], id[v]) << '\n';
	}
}


int main() {
	Prepare();
	ShortestPath();
	Process();
}