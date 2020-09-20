#include "pch.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

#define maxB 101
#define maxD 101
#define maxT 101
#define maxN 403
#define N D + T + B + B + 2
#define delta 1
#define start 0
#define des N - 1
#define getB(x) (x)
#define getD(x) ((x) + B)
#define getT(x) ((x) + B + D)
#define cloneB(x) ((x) + B + D + T)

typedef int maxn, maxa, maxf;

maxn D, T, B, trace[maxN], res;
bool c[maxN][maxN];
maxf f[maxN][maxN];


void Prepare() {
	std::cin >> B >> D >> T;

	for (maxn b = 1; b <= B; b++) {
		maxn dcnt, tcnt;
		std::cin >> dcnt >> tcnt;

		while (dcnt--) {
			maxn d;
			std::cin >> d;
			c[start][getD(d)] = c[getD(d)][b] = 1;
		}

		while (tcnt--) {
			maxn t;
			std::cin >> t;
			c[getT(t)][des] = c[cloneB(b)][getT(t)] = 1;
		}

		c[getB(b)][cloneB(b)] = 1;
	}
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
			if (trace[v] != -1 || (maxf)c[u][v] == f[u][v]) continue;
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


void Process() {
	while (Path()) Update();

	for (maxn t = getT(1); t <= getT(T); t++)
		res += f[t][des] > 0;

	std::cout << res;
}


int main() {
	//freopen("sinhnhat.inp", "r", stdin);
	//freopen("sinhnhat.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}