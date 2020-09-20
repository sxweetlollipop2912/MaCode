#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 2501
#define maxH 51

#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define idx(x, y) ((x) * m + (y))
#define floor first
#define pos second

typedef int maxn;
typedef std::pair <maxn, maxn> co_t;

maxn H, m, n, step[maxH][maxN], f[4][2] = { {-1, 0},{0,-1},{0,1},{1,0} };
co_t st, en;
std::queue <co_t> bfs;


void Prepare() {
	std::cin >> H >> m >> n;

	for (maxn h = 0; h < H; h++) for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		if (c == 'o') step[h][idx(i, j)] = -1;

		else if (c == '1') st = co_t(h, idx(i, j));
		else if (c == '2') en = co_t(h, idx(i, j));
	}
}


maxn BFS(const co_t st, const co_t en) {
	bfs.push(st); step[st.floor][st.pos] = 1;

	while (!bfs.empty()) {
		co_t u = bfs.front(); bfs.pop();
		if (u == en) return step[u.floor][u.pos] - 1;

		for (int i = 0; i < 4; i++) {
			maxn vx = row(u.pos) + f[i][0], vy = col(u.pos) + f[i][1], v = idx(vx, vy);
			if (vx < 0 || vx >= m || vy < 0 || vy >= n || step[u.floor][v]) continue;

			step[u.floor][v] = step[u.floor][u.pos] + 1;
			bfs.push(co_t(u.floor, v));
		}

		if (u.floor != H - 1 && !step[u.floor + 1][u.pos]) {
			step[u.floor + 1][u.pos] = step[u.floor][u.pos] + 1;
			bfs.push(co_t(u.floor + 1, u.pos));
		}
	}

	return 0;
}


void Process() {
	std::cout << BFS(st, en) * 5;
}


int main() {
	//freopen("maze.inp", "r", stdin);
	//freopen("maze.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}