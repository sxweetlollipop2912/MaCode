#include <iostream>
#include <cstdio>
#include <queue>

#define maxN 1001
#define e '*'
#define V 'V'
#define T 'T'
#define id(x, y) ((x) * n + (y))
#define row(x) ((x) / n)
#define col(x) ((x) % n)

typedef long maxn;
typedef char maxa;

maxn m, n, f[4][2]{ {-1,0},{0,-1},{0,1},{1,0} }, res;
maxa a[maxN][maxN], c[2] = { 'V','T' };
bool bp = 0;
std::queue <maxn> bfs[2];


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


void BFS(const maxa val) {
	bp = !bp;

	while (!bfs[bp].empty()) {
		maxn x = row(bfs[bp].front()), y = col(bfs[bp].front()); bfs[bp].pop();

		for (int k = 0; k < 4; k++) {
			maxn x1 = x + f[k][0], y1 = y + f[k][1];
			if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n || a[x1][y1] != val) continue;
			bfs[bp].push(id(x1, y1)); bfs[!bp].push(id(x1, y1));
			a[x1][y1] = e;
		}
	}
}


void Process() {
	bool p = c[0] == a[0][0] ? 1 : 0;
	bfs[!bp].push(0); a[0][0] = e;
	res = -1;

	while (!bfs[!bp].empty()) {
		p = !p; BFS(c[p]);
		++res;
	}
	std::cout << res;
}


int main() {
	//freopen("animal.inp", "r", stdin);
	//freopen("animal.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}