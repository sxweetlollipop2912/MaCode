#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define maxN 100001
#define maxM 200001
#define maxD 2000000001

typedef long maxn, maxd;

struct info {
	maxn v;
	maxd d;
};

maxn n, m, A, B, C, cur;
std::vector <info> adj[maxN];
maxd dist[maxN], res;
bool done[maxN];


class cmp {
public:
	maxd operator() (info x, info y) {
		return x.d > y.d;
	}
};

std::priority_queue < info, std::vector <info>, cmp > pq;


info newInfo(maxn v, maxd d) {
	info re;
	re.v = v; re.d = d;
	return re;
}


void Prepare() {
	std::cin >> m >> n >> A >> B >> C;
	A--; B--; C--;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		maxd d;
		std::cin >> u >> v >> d;
		u--; v--;

		adj[u].push_back(newInfo(v, d));
		adj[v].push_back(newInfo(u, d));
	}
}


void PrepDijkstra() {
	std::fill(dist, dist + n, maxD);
	std::fill(done, done + n, 0);
}


void Fill() {
	for (maxn i = 0; i < adj[cur].size(); i++) {
		maxn v = adj[cur][i].v;
		maxd d = adj[cur][i].d;
		if (done[v] || dist[v] <= dist[cur] + d) continue;

		dist[v] = dist[cur] + d;
		pq.push(newInfo(v, dist[v]));
	}
}


void Find() {
	while (done[pq.top().v]) pq.pop();
	cur = pq.top().v;
	pq.pop();
}


void Dijkstra_AB_AC() {

	PrepDijkstra();
	
	cur = A;
	done[cur] = 1;
	dist[cur] = 0;

	do {
		Fill();
		Find();
		done[cur] = 1;
	} while (!done[B] && !done[C]);

	res = std::min(dist[B], dist[C]);
	//std::cout << dist[B] << ' ' << dist[C] << '\n';
}


void Dijkstra_BC() {

	PrepDijkstra();

	cur = B;
	done[cur] = 1;
	dist[cur] = 0;

	do {
		Fill();
		Find();
		done[cur] = 1;
	} while (!done[C]);

	res += dist[C];
	//std::cout << dist[C] << '\n';
}


int main() {
	Prepare();

	Dijkstra_AB_AC();
	Dijkstra_BC();

	std::cout << res;
}