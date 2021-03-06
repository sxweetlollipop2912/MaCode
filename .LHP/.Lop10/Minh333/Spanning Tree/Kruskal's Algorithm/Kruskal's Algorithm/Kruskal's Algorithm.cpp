#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1001
#define maxM 1000001
#define maxD 1000000001

typedef long maxn, maxm;
typedef long maxd;

struct graph {
	maxn u, v;
	maxd d;
};

struct parent {
	maxn par, rank;
};

std::vector <graph> edge, re;
maxn n;
parent info[maxN];
maxm m;


graph newGraph(maxn u, maxn v, maxd d) {
	graph re;
	re.u = u; re.v = v; re.d = d;
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

		edge.push_back(newGraph(u - 1, v - 1, d));
	}

	std::sort(edge.begin(), edge.end(), cmp);
}


bool Union(maxn x, maxn y) {
	maxn xr = x, yr = y;
	while (info[xr].par != xr) xr = info[xr].par;
	while (info[yr].par != yr) yr = info[yr].par;

	if (xr == yr) return 0;

	if (info[xr].rank > info[yr].rank) info[yr].par = xr;
	else {
		info[xr].par = yr;
		if (info[xr].rank == info[yr].rank) info[yr].rank++;
	}

	return 1;
}


void Kruskal() {

	for (maxn i = 0; i < n; i++) {
		info[i].par = i;
		info[i].rank = 0;
	}

	for (maxm i = 0; i < m; i++) {
		maxn u = edge[i].u, v = edge[i].v;
		if (Union(u, v)) re.push_back(edge[i]);
	}
}


int main() {
	Prepare();
	Kruskal();
	
	for (maxm i = 0; i < re.size(); i++)
		std::cout << re[i].u << ' ' << re[i].v << ' ' << re[i].d << '\n';
}