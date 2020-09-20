#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxN 10001
#define maxM 100001
#define maxD 200000001

typedef long maxn, maxm, maxd;

struct info {
	maxn v;
	maxd d;
};

maxn n, parent[maxN];
std::vector <info> g[maxN];
maxd min_cur[maxN], T;
bool done[maxN];


info newInfo(maxn v, maxd d) {
	info re;
	re.v = v; re.d = d;
	return re;
}


void Prepare() {
	maxm m = 0;
	std::cin >> n >> m;

	maxd t[maxN];
	for (maxn i = 0; i < n; i++) std::cin >> t[i];
	T = t[0];

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		maxd d;
		std::cin >> u >> v >> d;
		u--; v--;

		g[u].push_back(newInfo(v, 2 * d + t[u] + t[v]));
		g[v].push_back(newInfo(u, 2 * d + t[u] + t[v]));
	}

	std::fill(min_cur, min_cur + n, maxD);
	std::fill(parent, parent + n, -1);
}


maxn minv() {
	int i;
	for (i = 0; done[i]; i++);
	maxn min = i;

	for (i = i + 1; i < n; i++)
		if (!done[i] && min_cur[i] < min_cur[min]) min = i;

	return min;
}


void Update(maxn u) {
	for (maxn i = 0; i < g[u].size(); i++) {
		maxn v = g[u][i].v;
		if (done[v]) continue;

		maxd d = g[u][i].d;
		if (d < min_cur[v]) {
			min_cur[v] = d;
			parent[v] = u;
		}
	}
}


void Prim() {
	maxn u = 0;
	parent[u] = u;
	min_cur[u] = 0;

	for (maxn i = 0; i < n; i++) {
		u = minv();
		done[u] = 1;
		Update(u);
	}

	for (maxn i = 0; i < n; i++) T += min_cur[i];
}


int main() {
	//freopen("bear.inp", "r", stdin);
	//freopen("bear.out","w",stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Prim();

	std::cout << T;
}
