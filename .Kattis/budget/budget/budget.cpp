#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define maxR 201
#define maxC 21
#define maxN 223
#define INF 19999999999999999
#define N (ROW + COL + 2)
#define st 0
#define en (N - 1)
#define getR(x) (x)
#define getC(x) ((x) + ROW)

typedef int maxn;
typedef long long maxa;

maxn ROW, COL, trace[maxN];
maxa C[maxN][maxN], f[maxN][maxN], add[maxN][maxN];


void Set(const maxn r, const maxn c, const char opt, const maxa val) {
	if (opt == '=') add[getR(r)][getC(c)] = val, C[getR(r)][getC(c)] = 0, C[st][getR(r)] -= val, C[getC(c)][en] -= val;
	if (opt == '<') C[getR(r)][getC(c)] = val - 1;
	if (opt == '>') add[getR(r)][getC(c)] = val + 1, C[st][getR(r)] -= (val + 1), C[getC(c)][en] -= (val + 1);
}


void Prepare() {
	std::cin >> ROW >> COL;

	for (maxn i = 1; i <= ROW; i++) std::cin >> C[st][getR(i)], f[st][getR(i)] = add[st][getR(i)] = 0;
	for (maxn i = 1; i <= COL; i++) std::cin >> C[getC(i)][en], f[getC(i)][en] = add[getC(i)][en] = 0;

	for (maxn r = 1; r <= ROW; r++) for (maxn c = 1; c <= COL; c++) C[getR(r)][getC(c)] = INF, f[getR(r)][getC(c)] = add[getR(r)][getC(c)] = 0;

	maxn k; std::cin >> k;
	while (k--) {
		maxn r, c; char opt; maxa val;
		std::cin >> r >> c >> opt >> val;

		if (!r && !c) for (maxn r = 1; r <= ROW; r++) for (maxn c = 1; c <= COL; c++) Set(r, c, opt, val);
		else if (!r) for (maxn r = 1; r <= ROW; r++) Set(r, c, opt, val);
		else if (!c) for (maxn c = 1; c <= COL; c++) Set(r, c, opt, val);
		else Set(r, c, opt, val);
	}
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
			if (trace[v] != -1 || C[u][v] == f[u][v]) continue;
			trace[v] = u;

			if (v == en) return 1;
			bfs.push(v);
		}
	}

	return 0;
}


void Update() {
	maxn v, u = en; maxa delta = INF;
	while (u != st) {
		v = u, u = trace[v];
		delta = std::min(delta, C[u][v] - f[u][v]);
	}
	u = en;
	while (u != st) {
		v = u, u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


bool Process() {
	for (maxn r = 1; r <= ROW; r++) for (maxn c = 1; c <= COL; c++) if (C[getR(r)][getC(c)] < 0) return 0;
	for (maxn r = 1; r <= ROW; r++) if (C[st][getR(r)] < 0) return 0;
	for (maxn c = 1; c <= COL; c++) if (C[getC(c)][en] < 0) return 0;

	while (Path()) Update();

	for (maxn r = 1; r <= ROW; r++) if (C[st][getR(r)] != f[st][getR(r)]) return 0;
	for (maxn c = 1; c <= COL; c++) if (C[getC(c)][en] != f[getC(c)][en]) return 0;

	for (maxn r = 1; r <= ROW; r++, std::cout << '\n') for (maxn c = 1; c <= COL; c++) std::cout << f[getR(r)][getC(c)] + add[getR(r)][getC(c)] << ' ';
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		if (!Process()) std::cout << "IMPOSSIBLE\n";
		std::cout << '\n';
	}
}