// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning (disable:4996)

#define maxN 200001
#define maxM 200001
#define maxD 99999999999999999
#define V first
#define cost second

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m;
maxa mn[maxN], res;
std::vector <ad_t> ad[maxN];
bool done[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) ad[i].clear();
	res = 0;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d;
		res += d;
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


maxa Prim() {
	std::fill(mn, mn + n, maxD);
	std::fill(done, done + n, 0);
	pq = std::priority_queue  <pq_t, std::vector <pq_t>, cmp>();

	mn[0] = 0;
	pq.push(pq_t(0, mn[0]));

	for(maxn i = 0; i < n - 1; i++) {
		maxn u = pq.top().V; pq.pop();
		done[u] = 1;

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V; maxa d = ad[u][i].cost;
			if (done[v] || mn[v] <= d) continue;
			mn[v] = d;
			pq.push(pq_t(v, mn[v]));
		}
		while (done[pq.top().V]) pq.pop();
	}

	maxa re = 0;
	for (maxn i = 0; i < n; i++) re += mn[i];
	return re;
}

//------------------ END_OF_PRIM -------------------------------

void Process() {
	std::cout << res - Prim() << '\n';
}


int main() {
	//freopen("11631.inp", "r", stdin);
	//freopen("11631.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while (std::cin >> n >> m && (m != 0 || n != 0)) {
		Prepare();
		Process();
	}
}