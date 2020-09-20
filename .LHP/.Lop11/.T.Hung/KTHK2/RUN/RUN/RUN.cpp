#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 103
#define maxNN 10609
#define maxA 99999999
#define idx(i, j) ((i) * n + (j))
#define row(x) ((x) / n)
#define col(x) ((x) % n)
#define valid(i, j) ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n)
#define V first
#define cost second

typedef int maxn;
typedef long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn m, n, P, L, T, Q, f[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, K, S;
char a[maxN][maxN];
maxa d[maxN][maxN], mnS[maxNN], mnK[maxNN], res;


void Prepare() {
	std::cin >> m >> n >> P >> L >> T >> Q;
	for (maxn i = 0; i < m; i++) for (maxn j = 0; j < n; j++) {
		std::cin >> a[i][j];
		if (a[i][j] == 'K') K = idx(i, j);
		if (a[i][j] == 'S') S = idx(i, j);
		d[i][j] = a[i][j] == '#' ? maxA : a[i][j] == 'K' ? P : a[i][j] == 'D' ? L : a[i][j] == 'C' ? T : a[i][j] == 'H' ? Q : 0;
	}
}

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn S, maxa mn[]) {
	std::fill(mn, mn + maxNN, maxA);
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();
	mn[S] = 0;
	pq.push(pq_t(S, mn[S]));
	//std::cout << K << ' ' << mn[K] << '\n';

	while (!pq.empty()) {
		maxn u = pq.top().V; pq.pop();
		maxn ui = row(u), uj = col(u);

		for (maxn k = 0; k < 4; k++) {
			maxn vi = ui + f[k][0], vj = uj + f[k][1], v = idx(vi, vj);
			if (!valid(vi, vj) || a[vi][vj] == '#' || mn[v] <= mn[u] + d[ui][uj] + 1) continue;
			mn[v] = mn[u] + d[ui][uj] + 1;
			pq.push(pq_t(v, mn[v]));
		}
		while (!pq.empty() && mn[pq.top().V] != pq.top().cost) pq.pop();
	}
}



void Process() {
	Dijkstra(S, mnS);
	Dijkstra(K, mnK);

	res = maxA;
	for (maxn i = 0; i < m; i++) res = std::min(res, std::min(mnK[idx(i, 0)] + d[i][0], mnK[idx(i, n - 1)] + d[i][n - 1]));
	for (maxn j = 0; j < n; j++) res = std::min(res, std::min(mnK[idx(0, j)] + d[0][j], mnK[idx(m - 1, j)] + d[m - 1][j]));
	res += mnS[K] + 5;

	if (res >= maxA) std::cout << -1;
	else std::cout << res;
}


int main() {
	freopen("run.inp", "r", stdin);
	freopen("run.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}