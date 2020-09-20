#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 3001
#define maxM 100001
#define maxA 1000001
#define maxR maxA
#define maxK 1001
#define des first
#define cost second

typedef int maxn, maxk;
typedef long maxa;
typedef long maxm;
typedef std::pair <maxn, maxa> info;

maxn n, trace[maxN];
maxm m;
maxa cmin[maxN], res;
bool done[maxN];
std::vector <info> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa d;
		std::cin >> u >> v >> d;
		--u; --v;

		ad[u].push_back(std::make_pair(v, d));
		ad[v].push_back(std::make_pair(u, d));
	}
}


class cmp {
public:
	bool operator() (const info &x, const info &y) {
		return x.cost > y.cost;
	}
};
std::priority_queue <info, std::vector <info>, cmp > pq;


void Fill(const maxn &u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].des;
		maxa d = ad[u][i].cost;

		if (done[v] || d >= cmin[v]) continue;

		cmin[v] = d;
		trace[v] = u;
		pq.push(std::make_pair(v, cmin[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().des]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().des;
	pq.pop();
	return re;
}


void Prim() {
	maxn cur = 0;
	cmin[cur] = 0;
	trace[cur] = cur;
	pq.push(std::make_pair(cur, cmin[cur]));

	for (maxn i = 0; i < n; i++) {
		cur = Find();
		done[cur] = 1;
		Fill(cur);
	}
}


void NewGraph() {
	for (maxn i = 0; i < n; i++) ad[i].clear();

	for (maxn v = 1; v < n; v++) {
		maxn u = trace[v];
		maxa d = cmin[v];

		ad[u].push_back(std::make_pair(v, d));
		ad[v].push_back(std::make_pair(u, d));
	}
}


void Cost(const maxn &u, const maxn& T, const maxa &C) {
	if (u == T) res = C;
	if (res != -1) return;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].des;
		maxa d = ad[u][i].cost;

		if (done[v]) continue;
		done[v] = 1;
		Cost(v, T, std::max(C, d));
		done[v] = 0;
	}
}


void Process() {
	std::fill(cmin, cmin + n, maxA);
	Prim();
	NewGraph();

	maxk k;
	std::cin >> k;

	while (k--) {
		maxn u, v;
		std::cin >> u >> v;
		--u; --v;
		
		res = -1;
		std::fill(done, done + n, 0);
		done[u] = 1;
		Cost(u, v, 0);

		std::cout << res << '\n';
	}
}


int main() {
	//freopen("knight.inp", "r", stdin);
	//freopen("knight.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}