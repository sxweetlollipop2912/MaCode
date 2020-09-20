// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#pragma warning(disable:4996)

#define maxN 10001
#define maxM 100001
#define maxA 9999999999999999
#define V first
#define cost second

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, S, T;
maxm m;
maxa P, mns[maxN], mnt[maxN], res;
std::vector <ad_t> ds[maxN], dt[maxN];


void Prepare() {
	std::cin >> n >> m >> S >> T >> P;
	--S, --T;

	for (maxn i = 0; i < n; i++) {
		ds[i].clear();
		dt[i].clear();
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d, --u, --v;
		ds[u].push_back(ad_t(v, d));
		dt[v].push_back(ad_t(u, d));
	}
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn S, const maxn T, maxa mn[], std::vector <ad_t> ad[]) {
	std::fill(mn, mn + n, maxA);
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();
	mn[S] = 0;
	pq.push(pq_t(S, mn[S]));

	while (!pq.empty()) {
		maxn u = pq.top().V; pq.pop();

		for (maxm i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V; maxa d = ad[u][i].cost;
			if (mn[v] <= mn[u] + d) continue;
			mn[v] = mn[u] + d;
			pq.push(pq_t(v, mn[v]));
		}
		while (!pq.empty() && mn[pq.top().V] != pq.top().cost) pq.pop();
	}
}


void Process() {
	Dijkstra(S, T, mns, ds); 
	Dijkstra(T, S, mnt, dt);
	res = -1;
	for (maxn u = 0; u < n; u++) for (maxm i = 0; i < ds[u].size(); i++) {
		maxn v = ds[u][i].V; maxa d = ds[u][i].cost;
		if (mns[u] + mnt[v] + d <= P) res = std::max(res, d);
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("12047.inp", "r", stdin);
	//freopen("12047.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}