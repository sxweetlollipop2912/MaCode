#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define maxN 1002
#define b 'b'
#define w 'w'
#define e '.'
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define num(r, c) ((r) * n + (c))
#define valid(r, c) ((r) < n && (r) >= 0 && (c) < n && (c) >= 0)

typedef long maxn;
typedef char maxa;

maxn n, f[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, res;
maxa a[maxN][maxN];
bool done[maxN][maxN], dw[maxN][maxN];
std::queue <maxn> bfs;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


maxn BFS(const maxn st) {
	bfs = std::queue <maxn>();
	memset(done, 0, sizeof(done));
	bool CNTb = 0; maxn CNTw = 0;

	bfs.push(st); done[row(st)][col(st)] = 1;

	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop(); ++CNTw, dw[row(u)][col(u)] = 1;
		
		for (int k = 0; k < 4; k++) {
			maxn vx = row(u) + f[k][0], vy = col(u) + f[k][1];
			if (!valid(vx, vy) || done[vx][vy]) continue;
			done[vx][vy] = 1;

			if (a[vx][vy] == e) {
				if (CNTb) return 0;
				CNTb = 1; continue;
			}

			if (a[vx][vy] == w) bfs.push(num(vx, vy));
		}
	}
	//std::cout << CNTb << ' ' << CNTw << '\n';

	return CNTb? CNTw : 0;
}


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++)
		if (a[i][j] == w && !dw[i][j]) res = std::max(res, BFS(num(i, j)));
	std::cout << res;
}


int main() {
	//freopen("covay.inp", "r", stdin);
	//freopen("covay.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}