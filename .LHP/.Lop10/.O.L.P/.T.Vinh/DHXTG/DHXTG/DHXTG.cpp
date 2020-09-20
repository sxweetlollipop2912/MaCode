#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 201
#define maxM 20001
#define maxT 1001
#define maxK 5001
#define maxD 20000001

typedef int maxn, maxm;
typedef long maxd;

maxn n;
maxm m, k;
maxd rout[maxN][maxN], K[maxK][3];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < n; i++) {
		std::fill(rout[i], rout[i] + n, maxD);
		rout[i][i] = 0;
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxd d;
		std::cin >> u >> v >> d;
		u--; v--;

		rout[u][v] = rout[v][u] = std::min(rout[u][v], d);
	}

	std::cin >> k;

	for (maxm i = 0; i < k; i++) {
		maxn u, v;
		maxd d;
		std::cin >> u >> v >> d;
		u--; v--;

		K[i][0] = u; K[i][1] = v; K[i][2] = d;
	}
}


void Floyd() {
	for(maxn k = 0; k < n; k++)
		for(maxn i = 0; i < n; i++)
			for (maxn j = 0; j < n; j++) {

				maxd x = rout[i][k] + rout[j][k];
				if (rout[i][j] > x) rout[i][j] = x;
			}
}


bool check(maxn a, maxn b) {
	for (maxm i = 0; i < k; i++) {
		maxn u = K[i][0], v = K[i][1];
		maxd d = K[i][2];

		if (rout[u][v] != d && rout[u][a] + rout[b][v] != d && rout[u][b] + rout[v][a] != d) return 0;
	}
	return 1;
}


void Process() {
	for(maxn a = 0; a < n; a++)
		for (maxn b = a + 1; b < n; b++) {
			if (!check(a, b)) continue;

			std::cout << a + 1 << ' ' << b + 1;
			return;
		}
}


int main() {
	Prepare();
	Floyd();
	Process();
}