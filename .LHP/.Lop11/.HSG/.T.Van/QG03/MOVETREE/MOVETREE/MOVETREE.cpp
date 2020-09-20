#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 41
#define coo first
#define x first.first
#define y first.second
#define dir second
#define sta first
#define step second
#define vertica 0
#define horizon 1

typedef int maxn;
typedef std::pair <maxn, maxn> co_t;
typedef std::pair <co_t, bool> stage_t;
typedef std::pair <stage_t, maxn> bfs_t;

maxn n;
stage_t st, en;
bool block[maxN][maxN], done[maxN][maxN][2];
std::queue <bfs_t> bfs;


void Prepare() {
	std::cin >> n;

	st.coo = en.coo = co_t(-1, -1);

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		block[i][j] = c == '1';

		if (c == 'b') {
			if (st.x == -1) st.coo = co_t(i, j);
			else st.dir = i == st.x ? horizon : vertica;
		}
		if (c == 'e') {
			if (en.x == -1) en.coo = co_t(i, j);
			else en.dir = i == en.x ? horizon : vertica;
		}
	}
}


bool gol(const stage_t s) {
	if (s.dir == vertica) return s.y != 0 && !block[s.x][s.y - 1] && !block[s.x + 1][s.y - 1] && !block[s.x + 2][s.y - 1];
	return s.y != 0 && !block[s.x][s.y - 1];
}
bool gor(const stage_t s) {
	if (s.dir == vertica) return s.y != n - 1 && !block[s.x][s.y + 1] && !block[s.x + 1][s.y + 1] && !block[s.x + 2][s.y + 1];
	return s.y + 3 < n && !block[s.x][s.y + 3];
}
bool gou(const stage_t s) {
	if (s.dir == horizon) return s.x != 0 && !block[s.x - 1][s.y] && !block[s.x - 1][s.y + 1] && !block[s.x - 1][s.y + 2];
	return s.x != 0 && !block[s.x - 1][s.y];
}
bool god(const stage_t s) {
	if (s.dir == horizon) return s.x != n - 1 && !block[s.x + 1][s.y] && !block[s.x + 1][s.y + 1] && !block[s.x + 1][s.y + 2];
	return s.x + 3 < n && !block[s.x + 3][s.y];
}

stage_t rotate(stage_t s) {
	if (s.dir == vertica) ++s.x, --s.y;
	else --s.x, ++s.y;
	s.dir = !s.dir; return s;
}


bool Push(stage_t s, maxn ste) {
	if (done[s.x][s.y][s.dir]) return 0;
	bfs.push(bfs_t(s, ste)); done[s.x][s.y][s.dir] = 1;
	return 0;
}

maxn BFS(const stage_t st, const stage_t en) {
	bfs.push(bfs_t(st, 0)); done[st.x][st.y][st.dir] = 1;

	while (!bfs.empty()) {
		stage_t cur = bfs.front().sta; maxn ste = bfs.front().step;
		bfs.pop();
		if (cur == en) return ste;

		if (gol(cur)) Push(stage_t(co_t(cur.x, cur.y - 1), cur.dir), ste + 1);
		if (gor(cur)) Push(stage_t(co_t(cur.x, cur.y + 1), cur.dir), ste + 1);
		if (gou(cur)) Push(stage_t(co_t(cur.x - 1, cur.y), cur.dir), ste + 1);
		if (god(cur)) Push(stage_t(co_t(cur.x + 1, cur.y), cur.dir), ste + 1);

		if ((cur.dir == vertica && gol(cur) && gor(cur)) || (cur.dir == horizon && gou(cur) && god(cur))) Push(rotate(cur), ste + 1);
	}

	return -1;
}


void Process() {
	std::cout << BFS(st, en);
}


int main() {
	//freopen("movetree.inp", "r", stdin);
	//freopen("movetree.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}