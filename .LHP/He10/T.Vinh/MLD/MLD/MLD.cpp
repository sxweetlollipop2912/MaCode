#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 1602
#define maxM 4001
#define maxC 501
#define INF 99999999999999999
#define clone(x) ((x) + n)

typedef int maxn, maxm;
typedef long long maxa;

maxn n, N, S, T, trace[maxN], start, des, res, D;
maxm m;
maxa c[maxN][maxN], f[maxN][maxN];
int Opt;


void Prepare() {
	std::cin >> m >> n >> D;
	N = n;
	start = clone(0);

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa a;
		std::cin >> u >> v >> a;

		c[u][v] = c[v][u] = c[u][v] + a;
	}
}


void Modify() {
	for (maxn u = 0; u < N; u++) {
		for (maxn v = 0; v < N; v++) {
			if (!c[u][v]) continue;

			c[u][clone(u)] += c[u][v];
			c[clone(u)][v] = c[u][v];
			c[u][v] = 0;
		}
	}
	N *= 2;
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


maxa MaxFlow() {
	maxn v = des, u = trace[v];
	maxa re = INF;
	trace[start] = 0;

	while (u) {
		re = std::min(re, c[u][v] - f[u][v]);
		v = u;
		u = trace[v];
	}

	return re;
}


void Update() {
	maxa delta = MaxFlow();
	maxn v, u = des;

	while (u != start) {
		v = u;
		u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


void Opt0_Init() {
	Modify();
	des = n - 1;
}


void Opt1_Init() {
	for (maxn u = 0; u < N; u++) {
		for (maxn v = 0; v < N; v++) {
			if (c[u][v]) c[u][v] = 1;
		}
		std::fill(f[u], f[u] + N, 0);
	}

	N++;
	des = N - 1;
	while (D--) {
		maxn u;
		std::cin >> u;
		c[u][des] = INF;
	}
}


void Process() {
	while (Path()) Update();

	res = 0;
	for (maxn i = 0; i < N; i++)
		res += std::max(f[i][des], (maxa)0);

	std::cout << res << '\n';
}


int main() {
	//freopen("mld.inp", "r", stdin);
	//freopen("mld.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	Opt0_Init();
	Process();

	Opt1_Init();
	Process();
}