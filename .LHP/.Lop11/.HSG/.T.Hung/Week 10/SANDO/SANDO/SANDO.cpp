#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1000001
#define maxS 21
#define N (n * n)
#define idx(x, y) ((x) * n + (y))
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define valid(x, y) ((x) >= 0 && (x) < n && (y) >= 0 && (y) < n)
#define vert first
#define dist second
#define c(u, v) std::min(mx[u], mx[v])

typedef long maxn, maxq;
typedef std::pair <maxn, maxn> pq_t, ad_t;

maxn f[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }, f1[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
maxn n, mx[maxN], par[maxN][maxS], px[maxN], d[maxN], mnp[maxN][maxS];
bool map[maxN], done[maxN];
std::queue <maxn> bfs;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < N; i++) {
		char c; std::cin >> c;
		if (c == '.') map[i] = 1;
		else bfs.push(i);
	}
}


void Set_Mx() {
	while (!bfs.empty()) {
		maxn u = bfs.front(); bfs.pop();

		for (int i = 0; i < 8; i++) {
			maxn vx = row(u) + f[i][0], vy = col(u) + f[i][1], v = idx(vx, vy);
			if (!valid(vx, vy) || !map[v] || mx[v]) continue;

			mx[v] = mx[u] + 1; bfs.push(v);
		}
	}
	for (maxn i = 0; i < N; i++) {
		if (!map[i]) mx[i] = 0;
		else if (mx[i]) mx[i] = std::min(mx[i], std::min(row(i) + 1, std::min(col(i) + 1, std::min(n - row(i), n - col(i))))) * 2 - 1;
		else mx[i] = std::min(row(i) + 1, std::min(col(i) + 1, std::min(n - row(i), n - col(i)))) * 2 - 1;
	}
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.dist < p2.dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Prim() {
	for (maxn i = 0; i < N; i++) par[i][0] = -1;

	par[0][0] = 0, px[0] = mx[0];
	pq.push(pq_t(0, 0));

	for (maxn j = 0; j < N; j++) {
		while (done[pq.top().vert]) pq.pop();
		maxn u = pq.top().vert; done[u] = 1;
		pq.pop();

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (done[v] || px[v] > c(u, v)) continue;
			par[v][0] = u, px[v] = c(u, v);
			pq.push(pq_t(v, px[v]));
		}
	}
}


void DFS(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (d[v] != maxN) continue;
		d[v] = d[u] + 1; DFS(v);
	}
}


void BuildAnc() {
	for (maxn i = 0; i < N; i++) mnp[i][0] = c(i, par[i][0]);

	for (maxn p = 1; (1 << p) <= N; p++) for (maxn i = 0; i < N; i++) {
		par[i][p] = par[par[i][p - 1]][p - 1];
		mnp[i][p] = std::min(mnp[i][p - 1], mnp[par[i][p - 1]][p - 1]);
	}
}


maxn Min(maxn x, maxn y) {
	maxn re = mx[x];
	if (d[x] < d[y]) std::swap(x, y);
	while (d[x] != d[y])
		re = std::min(re, mnp[x][(maxn)log2(d[x] - d[y])]), x = par[x][(maxn)log2(d[x] - d[y])];

	for (maxn p = maxS - 2; p >= 0; p--)
		if (par[x][p] != par[y][p]) {
			re = std::min(re, std::min(mnp[x][p], mnp[y][p]));
			x = par[x][p], y = par[y][p];
		}

	return x == y ? re : std::min(re, mnp[x][0]);
}


void Process() {
	Set_Mx();
	for (maxn u = 0; u < N; u++) for (int k = 0; k < 4; k++) {
		maxn vx = row(u) + f1[k][0], vy = col(u) + f1[k][1], v = idx(vx, vy);
		if (valid(vx, vy)) ad[u].push_back(v);
	}
	Prim();
	BuildAnc();
	for (maxn i = 0; i < N; i++) ad[i].clear();
	for (maxn v = 0; v < N; v++) if (par[v][0] != v) ad[par[v][0]].push_back(v);

	std::fill(d, d + N, maxN);
	d[0] = 0; DFS(0);

	maxq Q; std::cin >> Q;
	while (Q--) {
		maxn vx, vy, ux, uy;
		std::cin >> vx >> vy >> ux >> uy, --vx, --vy, --ux, --uy;
		std::cout << Min(idx(vx, vy), idx(ux, uy)) << '\n';
	}
}


int main() {
	//freopen("sando.inp", "r", stdin);
	//freopen("sando.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}