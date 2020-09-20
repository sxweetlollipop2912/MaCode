#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 1001
#define maxM 10001
#define maxA 10001
#define des first
#define cost second

typedef int maxn, maxm, maxa;
typedef std::pair <maxn, maxa> info;

maxn n, S, T;
maxm m;
maxa cmin[maxN];
bool done[maxN];
std::vector <info> ad[maxN];


void Prepare() {
	std::cin >> n >> m >> S >> T;
	--S; --T;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxa c;
		std::cin >> u >> v >> c;
		--u; --v;

		ad[u].push_back(std::make_pair(v, c));
		ad[v].push_back(std::make_pair(u, c));
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
		maxa c = std::min(cmin[u], ad[u][i].cost);

		if (c <= cmin[v]) continue;
		
		cmin[v] = c;
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


void Dijkstra() {
	maxn cur = S;
	cmin[cur] = maxA;

	while (cur != -1 && cur != T) {
		done[cur] = 1;
		Fill(cur);
		cur = Find();
	}
}


void Process() {
	Dijkstra();
	std::cout << cmin[T];
}


int main() {
	//freopen("taitrong.inp", "r", stdin);
	//freopen("taitrong.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}