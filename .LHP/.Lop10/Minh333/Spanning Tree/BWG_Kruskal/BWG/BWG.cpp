// Kruskal
//#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define maxN 501
#define maxM 10001
#define maxD 0
#define White 1
#define Black 2
#define Gray  3

typedef int maxn, maxm;
typedef int maxd;

struct graph {
	maxn u, v;
	maxd d;
	maxm id;
};

struct parent {
	maxn par, rank;
};

std::vector <graph> edge;
maxn n;
parent info[2][maxN];
maxm m, cnt, cntg;
bool re[maxM];


graph newGraph(maxn u, maxn v, maxd d, maxm id) {
	graph re;
	re.u = u; re.v = v; re.d = d; re.id = id;
	return re;
}


bool cmp(graph x, graph y) {
	return x.d < y.d;
}


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxd d;
		std::cin >> u >> v >> d;

		edge.push_back(newGraph(u - 1, v - 1, d, i));
	}

	std::sort(edge.begin(), edge.end(), cmp);
}


bool Union(maxn x, maxn y, bool id) {
	maxn xr = x, yr = y;
	while (info[id][xr].par != xr) xr = info[id][xr].par;
	while (info[id][yr].par != yr) yr = info[id][yr].par;

	if (xr == yr) return 0;

	if (info[id][xr].rank > info[id][yr].rank) info[id][yr].par = xr;
	else {
		info[id][xr].par = yr;
		if (info[id][xr].rank == info[id][yr].rank) info[id][yr].rank++;
	}

	return 1;
}


void KruskalG() {
	bool id = 0;
	cntg = 1;

	for (maxn i = 0; i < n; i++) {
		info[id][i].par = i;
		info[id][i].rank = 0;
	}

	for (maxm i = 0; i < m; i++) {
		if (edge[i].d != Gray) continue;

		maxn u = edge[i].u, v = edge[i].v;
		if (Union(u, v, id)) {
			re[edge[i].id] = 1;
			cnt++;
			cntg++;
		}
	}
}


bool KruskalB() {
	maxm cntb = cntg;
	bool id = 1;

	for (maxn i = 0; i < n; i++) {
		info[id][i].par  = info[!id][i].par;
		info[id][i].rank = info[!id][i].rank;
	}

	for (maxm i = 0; i < m; i++) {
		if (edge[i].d != Black) continue;

		maxn u = edge[i].u, v = edge[i].v;
		if (Union(u, v, id)) {
			re[edge[i].id] = 1;
			cnt++;
			cntb++;
		}
	}

	return cntb >= n;
}


bool KruskalW() {
	maxm cntw = cntg;
	bool id = 0;

	for (maxm i = 0; i < m; i++) {
		if (edge[i].d != White) continue;

		maxn u = edge[i].u, v = edge[i].v;
		if (Union(u, v, id)) {
			re[edge[i].id] = 1;
			cnt++;
			cntw++;
		}
	}

	return cntw >= n;
}


bool Process() {
	// G -> B -> W
	KruskalG();
	if (!KruskalB()) return 0;
	if (!KruskalW()) return 0;
	return 1;
}


int main() {
	Prepare();
	if (!Process()) {
		std::cout << -1;
		return 0;
	}

	std::cout << m - cnt << '\n';
	for (maxm i = 0; i < m; i++) if (!re[i]) std::cout << i + 1 << '\n';
}