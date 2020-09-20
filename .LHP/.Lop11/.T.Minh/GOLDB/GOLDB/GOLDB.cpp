#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#pragma warning (disable:4996)

#define maxR 202
#define maxC 202
#define maxN 804
#define maxA 3
#define getR(x) (x)
#define getRm(x) ((x) + R)
#define getCm(x) ((x) + R + R)
#define getC(x) ((x) + R + R + C)
#define N (R + R + C + C + 2)
#define st 0
#define en (N - 1)
#define delta 1
#define female 0
#define male 1 
#define none 2

typedef int maxn, maxa;

maxn R, C, trace[maxN];
maxa row[maxR], col[maxC], cap[maxN][maxN], f[maxN][maxN];


void Prepare() {
	std::cin >> R >> C;
	
	for (maxn r = 1; r <= R; r++) for (maxn c = 1; c <= C; c++) {
		int x; std::cin >> x;
		if (x == female)    cap[getR(r)][getC(c)] = 1;
		else if (x == male) cap[getRm(r)][getCm(c)] = 1;
	}
	for (maxn r = 1; r <= R; r++) cap[st][getR(r)] = 2, cap[getR(r)][getRm(r)] = 1;
	for (maxn c = 1; c <= C; c++) cap[getCm(c)][getC(c)] = 1, cap[getC(c)][en] = 2;
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
			if (trace[v] != -1 || cap[u][v] == f[u][v]) continue;
			trace[v] = u;
			if (v == en) return 1;
			bfs.push(v);
		}
	}
	return 0;
}


void Update() {
	maxn v, u = en;

	while (u != st) {
		v = u, u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


void Process() {
	while (Path()) Update();

	for (maxn r = 1; r <= R; r++) {
		for (maxn c = 1; c <= C; c++) {
			if (cap[getRm(r)][getCm(c)] == 1) {
				if (f[getRm(r)][getCm(c)] == 1) std::cout << "M ";
				else std::cout << male << ' ';
			}
			else if (cap[getR(r)][getC(c)] == 1) {
				if (f[getR(r)][getC(c)] == 1) std::cout << "W ";
				else std::cout << female << ' ';
			}
			else std::cout << none << ' ';
		}
		std::cout << '\n';
	}
}


int main() {
	//freopen("goldb.inp", "r", stdin);
	//freopen("goldb.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}