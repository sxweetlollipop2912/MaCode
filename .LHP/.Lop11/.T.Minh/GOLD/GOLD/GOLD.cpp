#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#pragma warning (disable:4996)

#define maxR 202
#define maxC 202
#define maxN 404
#define maxA 2001
#define getR(x) (x)
#define getC(x) ((x) + R)
#define N (R + C + 2)
#define st 0
#define en (N - 1)

typedef int maxn, maxa;

maxn R, C, trace[maxN];
maxa row[maxR], col[maxC], map[maxR][maxC], cost[maxN][maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> R >> C;
	for (maxn i = 1; i <= R; i++) std::cin >> row[i];
	for (maxn i = 1; i <= C; i++) std::cin >> col[i];

	maxn x, y;
	while (std::cin >> x >> y) std::cin >> map[x][y], row[x] -= map[x][y], col[y] -= map[x][y];

	for (maxn r = 1; r <= R; r++) for (maxn c = 1; c <= C; c++) if (!map[r][c]) cost[getR(r)][getC(c)] = maxA;
	for (maxn r = 1; r <= R; r++) cost[st][getR(r)] = row[r];
	for (maxn c = 1; c <= C; c++) cost[getC(c)][en] = col[c];
}


bool Path() {
	std::queue <maxn> bfs;
	bfs.push(st);

	std::fill(trace, trace + N, -1);
	trace[st] = st;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();
		for (maxn v = 0; v < N; v++) {
			if (trace[v] != -1 || cost[u][v] == f[u][v]) continue;
			trace[v] = u;
			if (v == en) return 1;
			bfs.push(v);
		}
	}
	return 0;
}


void Update() {
	maxn delta = maxA, u, v = en;
	do {
		u = trace[v];
		delta = std::min(delta, cost[u][v] - f[u][v]);
		v = u;
	} while (v != st);

	v = en;
	do {
		u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
		v = u;
	} while (v != st);
}


void Process() {
	while (Path()) 
		Update();

	for (maxn r = 1; r <= R; r++) {
		for (maxn c = 1; c <= C; c++) {
			if (f[getR(r)][getC(c)] > 0) map[r][c] = f[getR(r)][getC(c)];
			std::cout << map[r][c] << ' ';
		}
		std::cout << '\n';
	}
}


int main() {
	freopen("gold.inp", "r", stdin);
	//freopen("gold.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}