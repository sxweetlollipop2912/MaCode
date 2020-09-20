#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

#define maxN 203
#define maxA 500
#define maxR 1001
#define delta 1
#define start 0
#define N n + 2
#define des N - 1
#define get_le(x) x + chan

typedef int maxn, maxa, maxf;

maxn le, chan, n, trace[maxN], res;
bool c[maxN][maxN], snt[maxR];
maxf f[maxN][maxN];
maxa a[maxN];
int opt;


bool cmp(const maxa &x, const maxa &y) {
	return x % 2 == 0 && y % 2 == 1;
}


void Prepare() {
	std::cin >> n >> opt;

	for (maxn i = 1; i <= n; ++i) {
		std::cin >> a[i];
		chan += a[i] % 2 == 0;
	}
	le = n - chan;

	std::sort(a + 1, a + n + 1, cmp);
}


void Era(const maxa &max) {
	snt[1] = 1;
	for (maxa i = 2; i < max; i++) {
		if (snt[i]) continue;
		maxa x = i + i;
		while (x <= max) {
			snt[x] = 1;
			x += i;
		}
	}
}


void Connect() {
	Era(maxR);
	for (maxn i = 1; i <= chan; i++) {
		for (maxn j = get_le(1); j <= get_le(le); j++) 
			c[i][j] = !snt[a[i] + a[j]];

		c[start][i] = 1;
	}

	for (maxn i = get_le(1); i <= get_le(le); i++) c[i][des] = 1;
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


void Process() {
	Connect();
	while (Path()) Update();

	for (maxn i = 1; i <= chan; i++)
		res += f[start][i] > 0;

	std::cout << res;
}


int main() {
	freopen("box.inp", "r", stdin);
	freopen("box.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();

	if (opt == 1) std::cout << std::min(le, chan);
	else Process();
}