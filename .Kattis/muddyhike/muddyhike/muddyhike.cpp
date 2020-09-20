// AC Kattis
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 1001
#define maxA 1000001
#define x first
#define y second
#define coo first
#define depth second
#define st_c 0
#define en_c (C - 1)
#define valid(x, y) ((x) >= 0 && (x) < R && (y) >= 0 && (y) < C)

typedef int maxn;
typedef long maxa;
typedef std::pair <maxn, maxn> co_t;
typedef std::pair <co_t, maxa> pq_t;

maxn R, C, f[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
maxa a[maxN][maxN], mn[maxN][maxN];


void Prepare() {
	std::cin >> R >> C;
	for (maxn i = 0; i < R; i++) for (maxn j = 0; j < C; j++) std::cin >> a[i][j], mn[i][j] = maxA;
}


class cmp {
public:
	bool operator() (const pq_t& p1, const pq_t& p2) {
		return p1.depth > p2.depth;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const co_t u) {
	for (int i = 0; i < 4; i++) {
		maxn vx = u.x + f[i][0], vy = u.y + f[i][1];
		if (!valid(vx, vy) || std::max(mn[u.x][u.y], a[vx][vy]) >= mn[vx][vy]) continue;

		mn[vx][vy] = std::max(mn[u.x][u.y], a[vx][vy]);
		pq.push(pq_t(co_t(vx, vy), mn[vx][vy]));
	}
}


maxa Dijkstra() {
	for (maxn r = 0; r < R; r++) {
		mn[r][st_c] = a[r][st_c];
		pq.push(pq_t(co_t(r, st_c), mn[r][st_c]));
	}

	while (!pq.empty()) {
		co_t cur = pq.top().coo; pq.pop();
		if (cur.y == en_c) return mn[cur.x][cur.y];
		Fill(cur);
		while (!pq.empty() && pq.top().depth != mn[pq.top().coo.x][pq.top().coo.y]) pq.pop();
	}

	return 0;
}


void Process() {
	std::cout << Dijkstra();
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}