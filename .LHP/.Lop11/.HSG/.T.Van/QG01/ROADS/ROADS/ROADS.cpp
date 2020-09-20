#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 101
#define maxA 10002
#define maxL 10000001
//#define maxM 10001
//#define maxV 1000001
#define st 0
#define en (n - 1)
#define cost first
#define dist second
#define vert first
#define info second 

typedef int maxk;
typedef long maxn, maxm, maxl;
typedef std::pair <maxk, maxl> val_t;
typedef std::pair <maxn, val_t> ad_t, pq_t;

maxn n;
maxm m;
maxk K;
std::vector <ad_t> ad[maxN];
maxl mn[maxN][maxA], res;


void Prepare() {
	std::cin >> K >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxk k; maxl l;
		std::cin >> u >> v >> l >> k;
		--u, --v;
		ad[u].push_back(ad_t(v, val_t(k, l)));
	}
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.info.dist > p2.info.dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u, const maxk ku) {
	maxl lu = mn[u][ku];

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		maxl lv = ad[u][i].info.dist;
		maxk kv = ad[u][i].info.cost;

		if (kv + ku > K || mn[v][kv + ku] <= lu + lv) continue;

		mn[v][kv + ku] = lu + lv;
		//std::cout << v << ' ' << kv + ku << ' ' << mn[v][kv + ku] << '\n';
		pq.push(pq_t(v, val_t(kv + ku, mn[v][kv + ku])));
	}
}


void Dijkstra() {
	for (maxn i = 0; i < n; i++) std::fill(mn[i], mn[i] + K + 1, maxL);

	mn[st][0] = 0;
	pq.push(pq_t(st, val_t(0, mn[st][0])));

	while (!pq.empty()) {
		maxn u = pq.top().vert; maxk ku = pq.top().info.cost;
		pq.pop();
		Fill(u, ku);
		while (!pq.empty() && mn[pq.top().vert][pq.top().info.cost] != pq.top().info.dist) pq.pop();
	}
}


void Process() {
	Dijkstra();

	res = maxL;
	for (maxk k = 0; k <= K; k++) res = std::min(res, mn[en][k]);
	
	if (res == maxL) std::cout << "-1";
	else std::cout << res;
}


int main() {
	//freopen("roads.inp", "r", stdin);
	//freopen("roads.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}