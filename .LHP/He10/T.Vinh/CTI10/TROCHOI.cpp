#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 201
#define maxM 1001
#define delta 1
#define clone(x) ((x) + n)
#define des n - 1

typedef int maxn, maxm, maxa;

maxn n, N, S, T, trace[maxN], start, res;
maxm m;
bool c[maxN][maxN];
maxa f[maxN][maxN];
int Opt;


void Prepare() {
	std::cin >> n >> m >> Opt;
	N = n;
	start = 0;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u; --v;

		c[u][v] = 1;
	}
}


void Lock(const maxn &u) {
	for (maxn v = 0; v < N; v++)
		c[u][v] = c[v][u] = 0;
}


void Opt2_Prep() {
	maxn k;
	std::cin >> k;

	while (k--) {
		maxn u;
		std::cin >> u;
		Lock(u);
	}
}


void Modify() {
	for (maxn u = 0; u < N; u++) {
		for (maxn v = 0; v < N; v++) {
			if (!c[u][v]) continue;
			c[u][v] = 0;
			c[u][clone(u)] = c[clone(u)][v] = 1;
		}
	}
	N *= 2;
	start = clone(0);
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

	res = 0;
	for (maxn i = 0; i < N; i++)
		res += f[i][des] > 0;

	std::cout << res;
}


int main() {
	freopen("trochoi.inp", "r", stdin);
	freopen("trochoi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Opt == 2) Opt2_Prep(), Modify();
	Process();
}