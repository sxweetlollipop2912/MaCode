#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 1001
#define maxM 100001
#define maxA 5001
#define maxR 15000000001
#define vertice first
#define cost second

typedef int maxn;
typedef long maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> info;

maxn n, start;
maxm m;
std::vector <maxn> des;
std::vector <info> ad[maxN];
maxa mn[maxN];
bool done[maxN];


void Prepare() {
	maxn k = 0;
	std::cin >> n >> m >> start >> k;
	--start;

	while (k--) {
		maxn x;
		std::cin >> x;
		des.push_back(--x);
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa c;
		std::cin >> u >> v >> c;
		--u; --v;
		ad[u].push_back(info(v, c));
		ad[v].push_back(info(u, c));
	}
}


class cmp {
public:
	bool operator() (const info &x, const info &y) {
		return x.cost > y.cost;
	}
};
std::priority_queue <info, std::vector <info>, cmp > pq;


void Fill(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vertice;
		maxa c = ad[u][i].cost;
		if (done[v] || mn[u] + c >= mn[v]) continue;

		mn[v] = mn[u] + c;
		pq.push(info(v, mn[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().vertice]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().vertice;
	pq.pop();
	return re;
}


void Init() {
	pq = std::priority_queue <info, std::vector <info>, cmp >();
	std::fill(done, done + n, 0);
	std::fill(mn, mn + n, maxR);
}


maxa Dijkstra(const maxn start, const maxn des) {
	Init();

	mn[start] = 0;
	pq.push(info(start, mn[start]));
	maxn cur = start;

	while (cur != -1 && cur != des) {
		done[cur] = 1;
		Fill(cur);
		cur = Find();
	}

	return mn[des];
}


maxa Process() {
	if (des.size() == 1) return Dijkstra(start, des.back());
	
	maxa sA = Dijkstra(start, des[0]), sB = Dijkstra(start, des[1]), AB = Dijkstra(des[0], des[1]);
	return std::min(sA + AB, sB + AB);
}


int main() {
	//freopen("mecung.inp", "r", stdin);
	//freopen("mecung.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	std::cout << Process();
}