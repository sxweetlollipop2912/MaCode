#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 101
#define maxA 10001
#define row first
#define col second
#define coo first
#define level second

typedef int maxn;
typedef long maxa;
typedef std::pair <maxn, maxn> co_t;
typedef std::pair <co_t, maxa> pq_t;

maxn m, n;
maxa a[maxN][maxN], water[maxN][maxN], res;
int f[4][2] = { {-1, 0},{1,0},{0,-1},{0,1} };


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j], water[i][j] = maxA;
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.level > p2.level;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Process() {
	for (maxn i = 0; i < m; i++) {
		water[i][0] = a[i][0], water[i][n - 1] = a[i][n - 1];
		pq.push(pq_t(co_t(i, 0), water[i][0]));
		pq.push(pq_t(co_t(i, n - 1), water[i][n - 1]));
	}
	for (maxn j = 0; j < n; j++) {
		water[0][j] = a[0][j], water[m - 1][j] = a[m - 1][j];
		pq.push(pq_t(co_t(0, j), water[0][j]));
		pq.push(pq_t(co_t(m - 1, j), water[m - 1][j]));
	}

	res = 0;

	while (!pq.empty()) {
		maxn x = pq.top().coo.row, y = pq.top().coo.col;
		pq.pop();
		res += water[x][y] - a[x][y];

		for (maxn k = 0; k < 4; k++) {
			maxn x1 = x + f[k][0], y1 = y + f[k][1];

			if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n || water[x1][y1] <= std::max(a[x1][y1], water[x][y])) continue;
			water[x1][y1] = std::max(a[x1][y1], water[x][y]);
			pq.push(pq_t(co_t(x1, y1), water[x1][y1]));
		}

		while (!pq.empty() && pq.top().level != water[pq.top().coo.row][pq.top().coo.col]) pq.pop();
	}

	std::cout << res;
}


int main() {
	//freopen("wod.inp", "r", stdin);
	//freopen("wod.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}