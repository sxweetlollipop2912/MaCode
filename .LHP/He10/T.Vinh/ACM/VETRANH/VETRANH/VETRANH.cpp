#include "pch.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

//#define maxB 151
//#define maxD 151
//#define maxT 151
#define maxN 603
#define N HS + HS + BM + GV + 2
#define delta 1
#define start 0
#define des N - 1
#define getH(x) (x)
#define getB(x) ((x) + HS)
#define getG(x) ((x) + HS + BM)
#define cloneH(x) ((x) + BM + HS + GV)

typedef int maxn, maxf;

maxn HS, BM, GV, trace[maxN], res;
maxf f[maxN][maxN], c[maxN][maxN];


void Prepare() {
	std::cin >> HS >> GV >> BM;

	for (maxn h = 1; h <= HS; h++) {
		maxn gcnt, bcnt;
		std::cin >> gcnt >> bcnt;

		while (gcnt--) {
			maxn g;
			std::cin >> g;
			c[start][getG(g)] = 2;
			c[getG(g)][getH(h)] = 1;
		}

		while (bcnt--) {
			maxn b;
			std::cin >> b;
			c[getB(b)][des] = 2;
			c[cloneH(h)][getB(b)] = 1;
		}

		c[getH(h)][cloneH(h)] = 1;
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
			//std::cout << u << ' ' << v << ' ' << c[u][v] << ' ' << f[u][v] << '\n';
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
		//std::cout << v << ' ' << u << '\n';
	}
}


void Process() {
	while (Path()) Update();

	for (maxn b = getB(1); b <= getB(BM); b++) {
		res += std::max(0, f[b][des]);
	}

	std::cout << res;
}


int main() {
	//freopen("vetranh.inp", "r", stdin);
	//freopen("vetranh.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}