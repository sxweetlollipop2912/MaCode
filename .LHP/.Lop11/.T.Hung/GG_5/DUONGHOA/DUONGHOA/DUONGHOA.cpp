#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 10001
#define maxM 250001
#define maxD 99999999999999999
#define V first
#define cost second
#define st 0
#define en (n - 1)

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m;
maxa mn[maxN], res;
std::vector <ad_t> ad[maxN];
bool done[maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
	}
}


//-------------------- DIJKSTRA --------------------------------

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue  <pq_t, std::vector <pq_t>, cmp> pq;


maxa Dijkstra() {
	std::fill(mn, mn + n, maxD);
	mn[st] = 0;
	pq.push(pq_t(st, mn[st]));

	while (!pq.empty() && pq.top().V != en) {
		maxn u = pq.top().V; pq.pop();

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V; maxa d = mn[u] + ad[u][i].cost;
			if (mn[v] <= d) continue;
			mn[v] = d;
			pq.push(pq_t(v, mn[v]));
		}
		while (!pq.empty() && mn[pq.top().V] != pq.top().cost) pq.pop();
	}
	return mn[en];
}

//------------------ END_OF_DIJKSTRA -------------------------------


maxa DFS(const maxn v, const maxa len) {
	if (done[v]) return 0;
	done[v] = 1;

	maxa re = 0;
	for (maxn i = 0; i < ad[v].size(); i++) {
		maxn u = ad[v][i].V;
		if (mn[u] + ad[v][i].cost == len)
			re += ad[v][i].cost + DFS(u, len - ad[v][i].cost);
	}
	return re;
}


void Process() {
	res = Dijkstra();

	std::fill(done, done + n, 0);
	std::cout << DFS(en, res) * 2;
}


int main() {
	//freopen("duonghoa.inp", "r", stdin);
	//freopen("duonghoa.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}