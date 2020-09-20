#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxT 502
#define maxB 502
#define maxN 1003
#define maxA 30000
#define N (T + B + 2)
#define getB(x) ((x) + T)
#define x first
#define y second
#define delta (maxf)1
#define start (maxn)0
#define des (N - 1)

typedef int maxn, maxa, maxf;
typedef std::pair< maxa,maxa > size;

maxn T, B, trace[maxN], res;
bool c[maxN][maxN];
maxf f[maxN][maxN];


void Prepare() {
	size t[maxT], b[maxB];

	std::cin >> T >> B; 

	for (maxn i = 1; i <= T; i++) 
		std::cin >> t[i].x >> t[i].y;
	for (maxn i = 1; i <= B; i++) 
		std::cin >> b[i].x >> b[i].y;

	for (maxn i = 1; i <= T; i++) {
		for (maxn j = 1; j <= B; j++)
			c[i][getB(j)] = (t[i].x <= b[j].x && t[i].y <= b[j].y) || (t[i].x <= b[j].y && t[i].y <= b[j].x);

		c[start][i] = 1;
	}

	for (maxn i = getB(1); i <= getB(B); i++) c[i][des] = 1;
}


bool Path() {
	std::fill(trace, trace + N, -1);

	std::queue <maxn> bfs;
	bfs.push(start);
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
	//std::cout << "update\n";
	maxn v, u = des;

	while (u != start) {
		v = u, u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}


void Process() {
	while (Path()) Update();

	for (maxn i = 1; i <= T; i++) 
		res += f[start][i] > 0;
	std::cout << res;
}


int main() {
	freopen("tcm.inp", "r", stdin);
	freopen("tcm.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}