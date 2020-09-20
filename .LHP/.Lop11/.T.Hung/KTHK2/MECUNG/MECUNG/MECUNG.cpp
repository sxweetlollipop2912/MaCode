#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 227
#define maxNN (maxN * maxN)
#define N (n * 3)
#define M (m * 3)
#define idx(i, j) ((i) * N + (j))
#define row(x) ((x) / N)
#define col(x) ((x) % N)
#define valid(i, j) ((i) >= 0 && (i) < M && (j) >= 0 && (j) < N)

typedef long maxn;

maxn m, n, res, res_cnt, f[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool a[maxNN];
std::queue <maxn> bfs;


void Prepare() {
	std::cin >> n >> m;
	
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		char c; std::cin >> c;
		maxn ii = i * 3, jj = j * 3;

		if (c == '\\') {
			a[idx(ii, jj)] = a[idx(ii + 1, jj + 1)] = a[idx(ii + 2, jj + 2)] = 1;
		}
		else {
			a[idx(ii, jj + 2)] = a[idx(ii + 1, jj + 1)] = a[idx(ii + 2, jj)] = 1;
		}
	}
}


maxn BFS(const maxn u) {
	bfs = std::queue <maxn>();
	bfs.push(u);

	maxn re = 1;
	while (!bfs.empty()) {
		maxn u = bfs.front(), ui = row(u), uj = col(u); 
		bfs.pop();
		re += (bool)re;
		
		for (int k = 0; k < 4; k++) {
			maxn vi = ui + f[k][0], vj = uj + f[k][1], v = idx(vi, vj);
			if (!valid(vi, vj))
				re = 0;
			else if (!a[v]) {
				a[v] = 1;
				bfs.push(v);
			}
		}
	}
	return re;
}


void Process() {
	res = res_cnt = 0;
	for (maxn i = 0; i < M; i++) for (maxn j = 0; j < N; j++) {
		if (a[idx(i, j)]) continue;
		maxn tmp = BFS(idx(i, j)) / 3;
		if (tmp) 
			++res_cnt, res = std::max(res, tmp);
	}
	std::cout << res_cnt << ' ' << res;
}


int main() {
	//freopen("mecung.inp", "r", stdin);
	//freopen("mecung.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}