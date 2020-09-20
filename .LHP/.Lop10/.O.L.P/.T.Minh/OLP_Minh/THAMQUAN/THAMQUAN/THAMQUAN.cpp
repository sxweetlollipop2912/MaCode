#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 101
#define maxM 5001
#define maxK 11
#define maxT 50001
#define maxD 250000001

typedef int maxn, maxm;
typedef long maxd;

maxn n, M[maxM][2];
maxm m, k, K[maxK];
maxd d[maxN][maxN], res;
bool done[maxN];


void Prepare() {
	std::cin >> n >> m >> k;

	for (maxn i = 0; i < n; i++) std::fill(d[i], d[i] + n, maxD);

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxd D;
		std::cin >> u >> v >> D;
		u--; v--;
		
		M[i][0] = u; M[i][1] = v;
		d[u][v] = std::min(d[u][v], D);
	}

	for (maxm i = 0; i < k; i++) {
		std::cin >> K[i];
		K[i]--;
	}
}


void Floyd() {
	for (maxn k = 0; k < n; k++) 
		for (maxn i = 0; i < n; i++) 
			for (maxn j = 0; j < n; j++) 
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
}


void Try(maxm k_th, maxn prev, maxd re, maxm cnt) {
	k_th = K[k_th];

	maxn u = M[k_th][0], v = M[k_th][1];
	re += d[prev][u] + d[u][v];

	if (re + d[v][0] >= res) return;

	if (cnt == k) {
		res = re + d[v][0];
		return;
	}

	for (maxm i = 0; i < k; i++) {
		if (done[i]) continue;

		done[i] = 1;
		Try(i, v, re, cnt + 1);
		done[i] = 0;
	}
}


void Process() {
	res = maxD;
	
	for (maxm i = 0; i < k; i++) {
		done[i] = 1;
		Try(i, 0, 0, 1);
		done[i] = 0;
	}
}


int main() {
	Prepare();
	Floyd();
	Process();
	std::cout << res;
}