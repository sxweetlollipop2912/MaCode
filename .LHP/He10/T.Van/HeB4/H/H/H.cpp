#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 101
#define maxM 10001
#define maxT 99999999999999999

typedef int maxn, maxm;
typedef long long maxa;

maxn n, JS, JT, RS, RT;
maxm m;
maxa d[maxN][maxN], res;


void Prepare() {
	std::cin >> n >> m >> JS >> JT >> RS >> RT;
	--JS; --JT; --RS; --RT;

	for (maxn i = 0; i < n; i++) {
		std::fill(d[i], d[i] + n, maxT);
		d[i][i] = 0;
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa c;
		std::cin >> u >> v >> c;
		--u; --v;
		d[u][v] = d[v][u] = c;

	}
}


void Floyd() {
	for (maxn i = 0; i < n; i++) 
		for (maxn j = 0; j < n; j++) 
			for (maxn k = 0; k < n; k++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
}


void Process() {
	Floyd();

	res = -1;
	for (maxn i = 0; i < n; i++) {
		if (d[JS][i] != d[RS][i] || d[JS][i] + d[i][JT] != d[JS][JT] || d[RS][i] + d[i][RT] != d[RS][RT]) continue;
		res = res != -1? std::min(res, d[JS][i]) : d[JS][i];
	}

	std::cout << res;
}


int main() {
	freopen("H.inp", "r", stdin);
	freopen("H.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}