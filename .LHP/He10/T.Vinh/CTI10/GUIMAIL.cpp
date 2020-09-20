#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 201
#define maxM 1001
#define delta 1
#define N n * 2
#define clone(x) x + n
#define start clone(S)
#define des T

typedef int maxn, maxm, maxa;

maxn n, S, T, trace[maxN], res;
maxm m;
bool c[maxN][maxN];
maxa f[maxN][maxN];


void Prepare() {
	std::cin >> n >> m >> S >> T;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;

		c[u][v] = c[v][u] = 1;
	}
}


void Modify() {
	for (maxn u = 1; u <= n; u++) {
		for (maxn v = 1; v <= n; v++) {
			if (!c[u][v]) continue;
			c[u][v] = 0;
			c[u][clone(u)] = c[clone(u)][v] = 1;
		}
	}
}


bool Path() {
	std::queue <maxn> bfs;
	bfs.push(start);

	std::fill(trace + 1, trace + N + 1, -1);
	trace[start] = start;

	while (!bfs.empty()) {
		maxn u = bfs.front();
		bfs.pop();

		for (maxn v = 1; v <= N; v++) {
			if (trace[v] != -1 || (maxa)c[u][v] == f[u][v]) continue;
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
		//std::cout << u << ' ' << v << ' ' << f[u][v] << '\n';
	}
}


void Process() {
	while (Path()) Update();

	for (maxn i = clone(1); i <= clone(n); i++)
		res += f[i][des] > 0;

	std::cout << res;
}


int main() {
	freopen("guimail.inp", "r", stdin);
	freopen("guimail.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Modify();
	Process();
}