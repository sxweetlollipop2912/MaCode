#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 52
#define maxM 1001
#define maxA 5000000
#define start 1
#define des n

typedef int maxn, maxm;
typedef long maxa;

maxn n, trace[maxN];
maxm m;
maxa c[maxN][maxN], f[maxN][maxN], res;


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		maxa a;
		std::cin >> u >> v >> a;
		c[u][v] += a;
	}
}


bool Path() {
	std::queue <maxn> bfs;
	std::fill(trace, trace + n + 1, 0);
	bfs.push(start);
	trace[start] = start;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();

		for (maxn v = 1; v <= n; v++) {
			if (trace[v] || c[u][v] == f[u][v]) continue;
			trace[v] = u;

			if (v == des) return 1;
			bfs.push(v);
		}
	}

	return 0;
}


maxa MaxFlow() {
	maxn v = des, u = trace[v];
	maxa re = maxA;
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

	maxn v = des, u = trace[v];

	while (u) {
		f[u][v] += delta;
		f[v][u] -= delta;
		v = u;
		u = trace[v];
	}
}


void Process() {
	while (Path()) Update();

	for (maxn v = 1; v <= n; v++)
		if (f[start][v] > 0) res += f[start][v];

	std::cout << res;
}


int main() {
	freopen("gqsc.inp", "r", stdin);
	freopen("gqsc.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare(); 
	Process();
}