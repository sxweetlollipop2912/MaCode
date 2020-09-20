// B -> CTV -> TC
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

#define maxB 201
#define maxD 201
#define maxT 201
#define maxN 803
#define N m + m + n + n + 2
#define delta 1
#define start 0
#define des N - 1
#define getB(x) (x)
#define getT(x) ((x) + m)
#define getCTV(x) ((x) + m + m)
#define cloneCTV(x) ((x) + m + m + n)

typedef int maxn, maxa, maxf;
typedef std::string str;

maxn m, n, trace[maxN], res;
bool c[maxN][maxN];
maxf f[maxN][maxN];


void Prepare() {
	std::cin >> n >> m;

	str s;
	std::getline(std::cin, s);
	//std::cin.ignore();

	for (maxn b = 1; b <= m; b++) {
		std::getline(std::cin, s);
		std::stringstream ss;
		ss << s;
		maxn i;
		while (ss >> i) c[getB(b)][getCTV(i)] = 1;
		c[start][getB(b)] = 1;
	}

	for (maxn t = 1; t <= m; t++) {
		std::getline(std::cin, s);
		std::stringstream ss;
		ss << s;
		maxn i;
		while (ss >> i) c[cloneCTV(i)][getT(t)] = 1;
		c[getT(t)][des] = 1;
	}

	for (maxn i = 1; i <= n; i++) c[getCTV(i)][cloneCTV(i)] = 1;
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


bool Process() {
	while (Path()) Update();

	for (maxn j = 1; j <= m; j++) {
		bool cb = 0, ct = 0;
		for (maxn i = 1; i <= n; i++) cb |= (f[getB(j)][getCTV(i)] > 0), ct |= (f[cloneCTV(i)][getT(j)] > 0);
		if (!ct || !cb) return 0;
	}

	for (maxn i = 1; i <= n; i++) {
		maxn ib = 0, it = 0;
		for (maxn b = 1; b <= m; b++) if (c[getB(b)][getCTV(i)])   ib = b;
		for (maxn t = 1; t <= m; t++) if (c[cloneCTV(i)][getT(t)]) it = t;

		for (maxn b = 1; b <= m; b++) if (f[getB(b)][getCTV(i)] == 1)   ib = b;
		for (maxn t = 1; t <= m; t++) if (f[cloneCTV(i)][getT(t)] == 1) it = t;

		std::cout << i << ' ' << ib << ' ' << it << '\n';
	}

	return 1;
}


int main() {
	//freopen("meeting.inp", "r", stdin);
	//freopen("meeting.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}