// AC UVa
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

#pragma warning (disable:4996)

#define maxN 52
#define maxT 12
#define x first      // co
#define y second     // co
#define scene first  // sc
#define dist second  // sc
#define info first   // bfs
#define coo second   // bfs
#define Scene (maxn)2048
#define unable 0
#define able 1
#define treasure -1
#define none -1

typedef int maxn;
typedef std::pair <maxn, maxn> co_t, sc_t;
typedef std::pair <sc_t, co_t> bfs_t;

maxn ROW, COL, id[maxN][maxN], mn[Scene + 2][maxN][maxN], n, res;
int map[maxN][maxN];
int f[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int f1[8][2] = { {0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1} };
co_t st;


bool check(const co_t c) {
	return c.x >= 0 && c.y >= 0 && c.x < ROW && c.y < COL;
}


void Prepare() {
	std::cin >> COL;
	memset(map, able, sizeof(map));
	memset(id, 0, sizeof(id));

	n = 0;
	for (maxn i = 0; i < ROW; i++) 
		for (maxn j = 0; j < COL; j++) {
			char c;
			std::cin >> c;

			if (c == '@') st.x = i, st.y = j, id[i][j] = 0;
			else if (c == '!') map[i][j] *= treasure, id[i][j] = 1 << n, ++n;
			else if (c != '.') {
				map[i][j] = unable;
				if (c != '*') continue;

				for (int k = 0; k < 8; k++) {
					maxn x1 = i + f1[k][0], y1 = j + f1[k][1];
					if (check(co_t(x1, y1))) map[x1][y1] = unable;
				}
			}
		}
}


void BFS() {
	std::queue <bfs_t> bfs;

	bfs.push(bfs_t(sc_t(0, 0), st));
	mn[0][st.x][st.y] = 0;

	while (!bfs.empty()) {
		bfs_t u = bfs.front();
		bfs.pop();

		for (int k = 0; k < 4; k++) {
			maxn vx = u.coo.x + f[k][0], vy = u.coo.y + f[k][1];
			bfs_t v = bfs_t(sc_t(u.info.scene | id[vx][vy], u.info.dist + 1), co_t(vx, vy));

			if (!check(v.coo) || map[vx][vy] == unable || mn[v.info.scene][vx][vy] != none) continue;
			mn[v.info.scene][vx][vy] = v.info.dist;
			bfs.push(v);
		}
	}
}


void Process() {
	memset(mn, none, sizeof(mn));
	BFS();
	std::cout << mn[(1 << n) - 1][st.x][st.y] << '\n';
}


int main() {
	//freopen("10937.inp", "r", stdin);
	//freopen("10937.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> ROW && ROW) {
		Prepare();
		Process();
	}
}