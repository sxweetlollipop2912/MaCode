#include "pch.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

//#define maxK 101
//#define maxM 51
#define maxN 153
#define N M + K + 2
#define delta 1
#define start 0
#define des N - 1
#define getK(x) x + M

typedef int maxn, maxm;

maxn K, trace[maxN];
maxm M, c[maxN][maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> K >> M;

	for (maxm m = 1; m <= M; m++) {
		maxn k, k_cnt;
		std::cin >> k_cnt;

		for (maxn i = 0; i < k_cnt; i++) {
			std::cin >> k;
			++k;
			c[m][getK(k)] = 1;
		}
	}

	for (maxn k = getK(1); k <= getK(K); k++)
		c[k][des] = 1;
}


void Init(const maxm &x) {
	for (maxm m = 1; m <= M; m++)
		c[start][m] = x;

	for (maxm i = 0; i < N; i++) 
		std::fill(f[i], f[i] + N, 0);
}


bool Path() {
	std::queue <maxn> bfs;
	bfs.push(start);

	std::fill(trace, trace + N, -1);
	trace[start] = start;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();

		for (maxn v = 0; v < N; v++) {
			if (trace[v] != -1 || c[u][v] == f[u][v]) continue;
			trace[v] = u;

			if (v == des) return 1;
			bfs.push(v);
		}
	}

	return 0;
}


void Update() {
	maxn v, u = des;

	while (u != start) {
		v = u;
		u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


bool Try(const maxm &x) {
	Init(x);
	while (Path()) Update();

	for (maxn k = getK(1); k <= getK(K); k++)
		if (f[k][des] <= 0) return 0;

	return 1;
}


void Process() {
	maxn l = 1, r = K;

	while (l != r) {
		maxn m = (l + r) / 2;
		if (Try(m)) r = m;
		else l = m + 1;
	}

	if (Try(r)) std::cout << r;
	else std::cout << "No";
}


int main() {
	//freopen("chiakeo.inp", "r", stdin);
	//freopen("chiakeo.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}