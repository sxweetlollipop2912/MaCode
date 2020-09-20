#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 1001
#define valid(co) (co.X >= 0 && co.X < m && co.Y >= 0 && co.Y < n)
#define valid_bfs(b) (valid(b.xy) && a[b.xy.X][b.xy.Y] && (a[b.xy.X][b.xy.Y] != 3 || b.lab))
#define L 0
#define R 1
#define U 2
#define D 3
#define direct(st, en) (st.X < en.X ? D : st.X > en.X ? U : st.Y < en.Y ? R : L)
#define X first
#define Y second
#define xy first
#define lab second

typedef int maxn;
typedef std::pair <maxn, maxn> co_t;
typedef std::pair <co_t, bool> bfs_t;

maxn m, n, f[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }, step[maxN][maxN];
int a[maxN][maxN];
bool done[maxN][maxN][4];
std::queue <bfs_t> bfs;


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


bfs_t Move(const co_t st, const int dir) {
	bfs_t re; re.xy = st, re.lab = 0;
	for (bfs_t b = re; valid_bfs(b); b.xy.X += f[dir][0], b.xy.Y += f[dir][1]) {
		re = b;
		if (a[b.xy.X][b.xy.Y] == 2) re.lab = 1;
		if (a[b.xy.X][b.xy.Y] == 4) re.lab = 0;
	}
	return re;
}


bool isDone(const bfs_t v, const int dir) {
	return (a[v.xy.X][v.xy.Y] == 4 && done[v.xy.X][v.xy.Y][dir]) || (a[v.xy.X][v.xy.Y] != 4 && step[v.xy.X][v.xy.Y]);
}
void Done(const bfs_t v, const int dir) {
	if (a[v.xy.X][v.xy.Y] == 4) done[v.xy.X][v.xy.Y][dir] = 1;
}


void BFS(const co_t st, const co_t en) {
	step[st.X][st.Y] = 1; bfs.push(bfs_t(st, 0));

	while (!bfs.empty()) {
		bfs_t u = bfs.front(); bfs.pop();
		if (u.xy == en) return;

		for (int i = 0; i < 4; i++) {
			bfs_t v;
			v.xy.X = u.xy.X + f[i][0], v.xy.Y = u.xy.Y + f[i][1], v.lab = a[v.xy.X][v.xy.Y] == 2 ? 1 : u.lab;

			if (!valid_bfs(v) || isDone(v, i)) continue;

			/*if (a[v.xy.X][v.xy.Y] == 4) {
				done[v.xy.X][v.xy.Y][i] = 1;
				v = Move(v.xy, i);
				if (a[v.xy.X][v.xy.Y] != 4 && isDone(v, i)) continue;
				step[v.xy.X][v.xy.Y] = !(a[v.xy.X][v.xy.Y] == 4);
			}
			step[v.xy.X][v.xy.Y] += step[u.xy.X][u.xy.Y] + 1;*/
		}
	}
}