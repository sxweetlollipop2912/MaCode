#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

#define maxN 501
//#define maxM 10001
#define maxA 10000001
#define vert first
#define cost second

typedef int maxn, maxm;
typedef long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;
typedef std::vector <ad_t> vad_t;

maxn n, st, en;
maxm m;
maxa mn_st[maxN], mn_en[maxN];
bool del[maxN][maxN];
vad_t ad[maxN], adr[maxN];


void Init() {
	for (maxn i = 0; i < n; i++) {
		ad[i].clear(); adr[i].clear();
		std::fill(del[i], del[i] + n, 0);
	}
}


void Prepare() {
	std::cin >> st >> en;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v, std::cin >> d;
		ad[u].push_back(ad_t(v, d));
		adr[v].push_back(ad_t(u, d));
	}
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn st, maxa mn[], const vad_t ad[]) {
	std::fill(mn, mn + n, maxA);
	
	mn[st] = 0; pq.push(pq_t(st, mn[st]));

	while (!pq.empty()) {
		maxn u = pq.top().vert; pq.pop();

		for (maxm i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].vert;
			if (del[u][v] || mn[v] <= mn[u] + ad[u][i].cost) continue;
			mn[v] = mn[u] + ad[u][i].cost;
			pq.push(pq_t(v, mn[v]));
		}

		while (!pq.empty() && pq.top().cost != mn[pq.top().vert]) pq.pop();
	}
}


void Process() {
	Dijkstra(st, mn_st, ad); Dijkstra(en, mn_en, adr);

	for (maxn u = 0; u < n; u++) for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		if (mn_st[u] + ad[u][i].cost + mn_en[v] == mn_st[en]) del[u][v] = 1;
	}

	Dijkstra(st, mn_st, ad);
	if (mn_st[en] == maxA) std::cout << "-1\n";
	else std::cout << mn_st[en] << '\n';
}


int main() {
	//freopen("12144.inp", "r", stdin);
	//freopen("12144.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> m && n) {
		Init();
		Prepare();
		Process();
	}
}