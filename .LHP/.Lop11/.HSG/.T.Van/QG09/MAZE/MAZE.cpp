#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 125002
//#define maxH 51
#define cost (maxn)5
#define N (H * m * n)
#define pos(x) ((x) % (n * m))
#define row(x) (pos(x) / n)
#define col(x) (pos(x) % n)
#define floor(x) ((x) / (m * n))
#define idx(h, x, y) ((h) * (m * n) + (x) * m + (y))

typedef long maxn;

maxn H, m, n, step[maxN];
maxn st, en;
std::queue <maxn> bfs;


void Prepare() {
	std::cin >> H >> m >> n;

	for (maxn h = 0; h < H; h++) for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		if (c == 'o') step[idx(h, i, j)] = -1;

		else if (c == '1') st = idx(h, i, j);
		else if (c == '2') en = idx(h, i, j);
	}
}


maxn BFS(const maxn st, const maxn en) {
	maxn f[4] = { -1,1,-n,n };
	bfs.push(st); step[st] = 1;

	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop();
		if (u == en) return step[u] - 1;

		for (int i = 0; i < 4; i++) {
			maxn v = u + f[i];
			//std::cout << i << ' ' << u << ' ' << v << '\n';
			if (v < 0 || floor(v) != floor(u) || (row(v) != row(u) && col(v) != col(u)) || step[v]) continue;

			step[v] = step[u] + cost;
			bfs.push(v);
		}

		if (u + (m * n) < N && !step[u + (m * n)]) {
			step[u + (m * n)] = step[u] + cost;
			bfs.push(u + (m * n));
		}
	}

	return 0;
}


void Process() {
	std::cout << BFS(st, en);
}


int main() {
	freopen("maze.inp", "r", stdin);
	freopen("maze.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}