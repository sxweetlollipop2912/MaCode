#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 1001
#define vert first
#define dist second

typedef int maxn;
typedef std::pair <maxn, maxn> ad_t, pq_t;

maxn n, res;
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i < n; i++) {
		maxn u, v, d;
		std::cin >> u >> v >> d;
		--u, --v;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
	}
}

//-------------- DIJKSTRA --------------------------------

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.dist > p2.dist;
	}
};
std::priority_queue  <pq_t, std::vector <pq_t>, cmp > pq;
maxn mn[maxN];
bool done[maxN];


void Fill(const maxn u) {
	//std::cout << u << '\n';
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert, d = mn[u] + ad[u][i].dist;
		//std::cout << v << ' ' << d  << ' ' << mn[v] << '\n';
		if (done[v] || mn[v] <= d) continue;

		mn[v] = d;
		pq.push(pq_t(v, mn[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().vert]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().vert;
	pq.pop();
	return re;
}


void Dijkstra(maxn u) {
	std::fill(done, done + n, 0);
	std::fill(mn, mn + n, maxN);
	pq = std::priority_queue  <pq_t, std::vector <pq_t>, cmp >();

	mn[u] = 0;
	while (u != -1) {
		//std::cout << u << ' ' << mn[u] << '\n';
		done[u] = 1;
		res = std::max(res, mn[u]), done[u] = 1;
		Fill(u);
		u = Find();
	}
}

//------------------ END_OF_DIJKSTRA -------------------------------


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++) {
		//std::cout << "start " << i << '\n';
		if (ad[i].size() == 1) Dijkstra(i);
	}
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}