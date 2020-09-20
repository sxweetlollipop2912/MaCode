// AC
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 101
#define maxK 10002
//#define maxM 10001
//#define maxA 101
#define maxL 1000001
//#define maxC 101
#define start 0
#define des n - 1
#define vertex second
#define cost first
#define dat second
#define length first
#define nonedat data(-1, -1)

typedef int maxn, maxm, maxa, maxc;
typedef std::pair <maxc, maxn> data;
typedef std::pair <maxa, data> info;

maxn n;
maxm m;
maxc K;
std::vector <info> ad[maxN];


void Prepare() {
	std::cin >> K >> n >> m;

	for (maxn i = 0; i < n; i++) ad[i].clear();

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa l; maxc t;
		std::cin >> u >> v >> l >> t;
		--u, --v;
		ad[u].push_back(info(l, data(t, v)));
	}
}


//*****// DIJKSTRA //****************************************

std::priority_queue <info, std::vector <info>, std::greater <info> > pq;
maxa f[maxN][maxK];
bool done[maxN][maxK];


void Init() {
	for (maxn i = 0; i < n; i++) {
		std::fill(f[i], f[i] + maxK, maxL);
		std::fill(done[i], done[i] + maxK, 0);
	}
	pq = std::priority_queue <info, std::vector <info>, std::greater <info> >();
}


void Fill(const data du) {
	maxn u = du.vertex; 
	maxc cu = du.cost; 
	maxa lu = f[u][cu];

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].dat.vertex;
		maxa lv = lu + ad[u][i].length;
		maxc cv = cu + ad[u][i].dat.cost;

		if (cv > K || done[v][cv] || f[v][cv] <= lv) continue;

		f[v][cv] = lv;
		pq.push(info(f[v][cv], data(cv, v)));
	}
}


data Find() {
	while (!pq.empty() && done[pq.top().dat.vertex][pq.top().dat.cost]) pq.pop();
	if (pq.empty()) return nonedat;

	data re = pq.top().dat;
	pq.pop();
	return re;
}


maxa Dijkstra() {
	Init();

	f[start][0] = 0;
	data cur = data(0, start);
	pq.push(info(f[cur.vertex][cur.cost], cur));

	while (cur != nonedat && cur.vertex != des) {
		done[cur.vertex][cur.cost] = 1;
		Fill(cur);
		cur = Find();
	}

	return cur == nonedat ? -1 : f[cur.vertex][cur.cost];
}

//*******// END_OF_DIJKSTRA //********************************************************************


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		Prepare();
		std::cout << Dijkstra() << '\n';
	}
}