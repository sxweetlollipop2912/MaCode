#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>

#define maxN 501
#define L 0
#define U 1
#define R 2
#define D 3
#define x first.first
#define y first.second
#define turn second
#define get_turn(x) ((x) % 4)

typedef int maxn, maxr;
typedef std::pair <maxn, maxn> co_t;
typedef std::pair <co_t, int> bfs_t;
typedef std::string str;

maxn ROW, COL;
int f[4][4] = { {L,U,R,D},{D,L,U,R},{R,D,L,U},{U,R,D,L} }, sp[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
bool dir[maxN][maxN][4];
maxr res, step[maxN][maxN][4];
std::queue <bfs_t> bfs;


void Init() {
	memset(dir, 0, sizeof(dir));
	memset(step, 0, sizeof(step));
	bfs = std::queue <bfs_t>();
}


void Prepare() {
	for (maxn i = 0; i < ROW; i++) for (maxn j = 0; j < COL - (i == ROW - 1); j++) {
		str s; std::cin >> s;
		for (int is = 0; is < s.size(); is++) {
			if (s[is] == 'N') dir[i][j][U] = 1;
			if (s[is] == 'S') dir[i][j][D] = 1;
			if (s[is] == 'W') dir[i][j][L] = 1;
			if (s[is] == 'E') dir[i][j][R] = 1;
		}
	}
}


bool valid(const maxn xx, const maxn yy) {
	return xx >= 0 && xx < ROW && yy >= 0 && yy < COL;
}


maxr BFS(const bfs_t st, const co_t en) {
	step[st.x][st.y][0] = 1;
	bfs.push(st);

	while (!bfs.empty()) {
		bfs_t cur = bfs.front(); bfs.pop();

		for (int d = 0; d < 4; d++) {
			maxn x1 = cur.x + sp[d][0], y1 = cur.y + sp[d][1];
			if (!dir[cur.x][cur.y][f[cur.turn][d]] || !valid(x1, y1) || step[x1][y1][get_turn(cur.turn + 1)]) continue;

			step[x1][y1][get_turn(cur.turn + 1)] = step[cur.x][cur.y][cur.turn] + 1;
			if (x1 == en.first && y1 == en.second) return step[x1][y1][get_turn(cur.turn + 1)];
			bfs.push(bfs_t(co_t(x1, y1), get_turn(cur.turn + 1)));
		}
	}

	return 0;
}


void Process() {
	res = BFS(bfs_t(co_t(0, 0), 0), co_t(ROW - 1, COL - 1));
	if (!res) std::cout << "no path to exit\n";
	else std::cout << res - 1 << '\n';
}


int main() {
	//freopen("985.inp", "r", stdin);
	//freopen("985.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> ROW >> COL) {
		Init();
		Prepare();
		Process();
	}
}