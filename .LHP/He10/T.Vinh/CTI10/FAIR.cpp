#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#define maxMN 201
#define maxN 403
#define N CTY + DD + 2
#define delta 1
#define start 0
#define des N - 1
#define get_dd(x) x + CTY

typedef int maxn;

maxn DD, CTY, trace[maxN], res;
bool c[maxN][maxN];
int f[maxN][maxN];


void Prepare() {
	std::cin >> CTY >> DD;

	for (maxn cty = 1; cty <= CTY; cty++) {
		maxn dd, dd_cnt;
		std::cin >> dd_cnt;

		for (maxn i = 0; i < dd_cnt; i++) {
			std::cin >> dd;
			c[cty][get_dd(dd)] = 1;
		}

		c[start][cty] = 1;
	}

	for (maxn dd = get_dd(1); dd <= get_dd(DD); dd++)
		c[dd][des] = 1;
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
			if (trace[v] != -1 || (maxn)c[u][v] == f[u][v]) continue;
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

	for (maxn dd = get_dd(1); dd <= get_dd(DD); dd++)
		res += f[dd][des] > 0;

	std::cout << res;
}


int main() {
	freopen("fair.inp","r",stdin);
	freopen("fair.out","w",stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}