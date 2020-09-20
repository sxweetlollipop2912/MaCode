#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

#define maxN 103
#define maxC 10000
#define minC -10000
#define maxL 10000
#define maxR 100000001
#define des n + 1
#define start 0
#define def_b 0
#define def_d 1

typedef long maxd, maxb, maxdb, maxc;
typedef int maxn;

maxn n;
maxb b[maxN][maxN];
maxd d[maxN][maxN], L;
maxc W;


long sqr(long x) {
	return x * x;
}


void Prepare() {
	maxc x[maxN], y[maxN];

	std::cin >> W >> L >> y[start];
	x[start] = 0;

	std::cin >> n;
	x[des] = W;

	for (maxn i = 1; i <= n; i++) std::cin >> x[i] >> y[i];

	for (maxn i = 0; i <= n; i++) {
		for (maxn j = i + 1; j <= n + 1; j++) {

			y[des] = y[i];
			maxd tmp = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);

			if (i != start || tmp <= sqr(L)) {
				d[i][j] = tmp;
				b[i][j] = tmp <= sqr(L) ? 1 : maxR;
			}

			else {
				d[i][j] = sqr(abs(x[j] - x[i]));
				b[i][j] = x[j] - x[i] > L ? maxR : ceil(((double)abs(y[j] - y[i]) - pow(sqr(L) - sqr(x[j] - x[i]), 0.5)) / (double)L) + 1;
			}

			d[j][i] = d[i][j];
			b[j][i] = b[i][j];

			//std::cout << i << ' ' << j << ' ' << b[i][j] << ' ' << d[i][j] << '\n';
		}
	}
}


struct pqueue {
	maxn v;
	maxdb db;
};

// ***********************************************************
// **** PRIORITY QUEUE _ SET UP ******************************

class cmp {
public:
	bool operator() (const pqueue& p1, const pqueue& p2) {
		return p1.db > p2.db;
	}
};
std::priority_queue < pqueue, std::vector <pqueue>, cmp > pq;

// ***********************************************************

maxdb min_r[maxN];
bool done[maxN];


pqueue newPQ(const maxn v, const maxdb db) {
	pqueue re;
	re.v = v; re.db = db;
	return re;
}


void Init() {
	pq = std::priority_queue < pqueue, std::vector <pqueue>, cmp >();
	std::fill(min_r, min_r + n + 2, maxR);
	std::fill(done, done + n + 2, 0);

	min_r[start] = 0;
}


void Fill(const maxn u, const bool def) {
	for (maxn v = 0; v <= n + 1; v++) {
		maxdb tmp = 0;

		if (def == def_b) tmp = min_r[u] + b[u][v];
		else tmp = std::max(min_r[u], d[u][v]);

		if (done[v] || min_r[v] <= tmp) continue;

		min_r[v] = tmp;
		pq.push(newPQ(v, min_r[v]));
	}
}


maxn Find() {
	while (!pq.empty() && done[pq.top().v]) pq.pop();
	if (pq.empty()) return -1;

	maxn re = pq.top().v;
	pq.pop();

	return re;
}


void Dijkstra(const bool def) {
	Init();
	maxn cur = 0;

	while (cur != -1) {
		done[cur] = 1;
		Fill(cur, def);
		cur = Find();
	}

	if (def == def_d) min_r[des] = ceil(pow(min_r[des], 0.5));

	//std::cout << min_r[des] << '\n';
}


int main() {
	Prepare();

	Dijkstra(def_b);
	if (min_r[des] >= maxR) Dijkstra(def_d);

	std::cout << min_r[des];
}