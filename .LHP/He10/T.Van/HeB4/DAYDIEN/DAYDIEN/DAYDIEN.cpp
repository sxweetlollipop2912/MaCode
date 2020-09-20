#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 1001
#define maxM 1000001
#define maxE 100
#define des first
#define cost second

typedef int maxn, maxa;
typedef long maxm;
typedef std::pair <maxn, maxa> info;

maxn n;
maxm m;
maxa emin[maxN];
bool done[maxN];
std::vector <info> ad[maxN];
double res;


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa e;
		std::cin >> u >> v >> e;
		--u; --v;

		ad[u].push_back(std::make_pair(v, e));
		ad[v].push_back(std::make_pair(u, e));
	}
}


class cmp {
public:
	bool operator() (const info &x, const info &y) {
		return x.cost < y.cost;
	}
};
std::priority_queue <info, std::vector <info>, cmp > pq;


void Fill(const maxn &u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].des;
		maxa e = ad[u][i].cost;

		if (done[v] || e <= emin[v]) continue;

		emin[v] = e;
		pq.push(std::make_pair(v, emin[v]));
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
	emin[cur] = 1;
	pq.push(std::make_pair(cur, emin[cur]));

	for (maxn i = 0; i < n; i++) {
		cur = Find();
		done[cur] = 1;
		res *= (emin[cur] / (double)100);

		Fill(cur);
	}
}


void Process() {
	res = 1;
	Prim();
	std::cout << res * 100;
}


int main() {
	//freopen("daydien.inp", "r", stdin);
	//freopen("daydien.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}