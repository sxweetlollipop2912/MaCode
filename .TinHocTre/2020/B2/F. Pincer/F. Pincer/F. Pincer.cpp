#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_set>

#define maxN ((maxn)(10001))
#define maxA ((maxa)(99999999999999999))
#define st ((maxn)0)
#define en ((maxn)(n - 1))
#define V first
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m;
maxa d[maxN];
std::vector <ad_t> ad[maxN], adr[maxN];
std::unordered_set <ad_t> set[maxN], setr[maxN];
std::vector <maxn> shortestPath;


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v; maxa c;
		std::cin >> u >> v >> c;
		--u, --v;

		ad[u].push_back(ad_t(v, c));
		ad[v].push_back(ad_t(u, c));

		adr[u].push_back(ad_t(v, c));
		adr[v].push_back(ad_t(u, c));
	}
}


void Construct_Shortest_Path(const std::vector <ad_t> adr[], const maxa d[], std::vector <maxn> re, const maxn T) {
	for (maxn i = 0; i < adr[T].size(); i++) {
		maxn u = adr[T][i].V; maxa c = adr[T][i].cost;
		if (d[u] + c != d[T]) continue;

		ConstrShortestPath(adr, d, re, u);
		break;
	}
	re.push_back(T);
}


class cmp {
public:
	bool operator()(const pq_t& p1, const pq_t& p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


maxa Dijkstra(const std::vector <ad_t> ad[], maxa d[], const maxn n, const maxn S, const maxn T = -1) {
	std::fill(d, d + n, maxA);
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();

	d[S] = 0;
	pq.push(ad_t(S, 0));

	while (!pq.empty() && pq.top().V != T) {
		maxn u = pq.top().V; pq.pop();

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
			if (d[v] <= d[u] + c) continue;
			d[v] = d[u] + c;
			pq.push(ad_t(v, d[v]));
		}

		while (!pq.empty() && d[pq.top().V] != pq.top().cost) pq.pop();
	}

	return T != -1? d[T] : -1;
}


maxa Dijkstra(const std::unordered_set <ad_t> set[], maxa d[], const maxn n, const maxn S, const maxn T = -1) {
	std::fill(d, d + n, maxA);
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();

	d[S] = 0;
	pq.push(ad_t(S, 0));

	while (!pq.empty() && pq.top().V != T) {
		maxn u = pq.top().V; pq.pop();

		for (auto i = set[u].begin(); i != set[u].end(); i++) {
			maxn v = i->V; maxa c = i->cost;
			if (d[v] <= d[u] + c) continue;
			d[v] = d[u] + c;
			pq.push(ad_t(v, d[v]));
		}

		while (!pq.empty() && d[pq.top().V] != pq.top().cost) pq.pop();
	}

	return T != -1 ? d[T] : -1;
}


void Modify_Cost() {
	for (maxn u = 0; u < n; u++) {
		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V; maxa* c = &ad[u][i].cost;
			*c = *c - d[v] + d[u];
		}
		for (maxn i = 0; i < adr[u].size(); i++) {
			maxn v = adr[u][i].V; maxa* c = &adr[u][i].cost;
			*c = *c - d[u] + d[v];
		}
	}
}


void Vec2Set_Graph(std::unordered_set <ad_t> set[], std::vector <ad_t> ad[], const maxn n) {
	for (maxn u = 0; u < n; u++)
		set[u] = std::unordered_set <ad_t>(ad[u].begin(), ad[u].end());
}


void Reverse_Edge(std::unordered_set <ad_t> set[], const maxn u, const maxn v) {
	auto it = std::find_if(set[u].begin(), set[u].end(), [](const ad_t& p) { return p.V == v; });
	if (it != st.end())
		st.erase(it);
}


void Process() {
	Dijkstra(ad, d, n, st);
	Modify_Cost();

	Vec2Set_Graph(set, ad, n); Vec2Set_Graph(setr, adr, n);

}