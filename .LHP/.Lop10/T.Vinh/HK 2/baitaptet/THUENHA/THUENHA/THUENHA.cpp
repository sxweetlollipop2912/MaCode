#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define maxN 10001
#define maxM 50001
#define maxT 5000
#define maxR 250000001
#define maxP 5

typedef int maxn, maxm;
typedef long maxr;

struct info {
	maxn v;
	maxr d;
};

std::vector <info> ad[maxN];
maxr min[maxP][maxN], key, res = maxR;
maxn n, p, cur, P[maxP];
maxm m;
bool done[maxN], done2[maxP];
int id;

// ***********************************************************
// **** PRIORITY QUEUE _ SET UP ******************************

class cmp {
public:
	bool operator() (const info p1, const info p2) {
		return p1.d > p2.d;
	}
};
std::priority_queue < info, std::vector <info>, cmp > Queue;

// ***********************************************************


info newInfo(maxn v, maxr d) {
	info re;
	re.v = v; re.d = d;
	return re;
}


void clearQueue() {
	Queue = std::priority_queue < info, std::vector <info>, cmp >();
}


void Prepare() {
	std::cin >> n >> m >> p;
	
	for (maxn i = 0; i < p; i++)
		std::cin >> P[i];


	for (maxm i = 0; i < m; i++) {
		maxn u, v, d;
		std::cin >> u >> v >> d;

		ad[u].push_back(newInfo(v, d));
		ad[v].push_back(newInfo(u, d));
	}
}


// 1  /////////////////////////////////////////////////////////////////////////

void Fill1() {
	for (maxn i = 0; i < ad[cur].size(); i++) {
		maxn v = ad[cur][i].v;
		maxr d = ad[cur][i].d;

		if (done[v]) continue;

		if (min[id][v] > min[id][cur] + d) {
			min[id][v] = min[id][cur] + d;
			//std::cout << v << ' ' << min[id][v] << '\n';
			Queue.push(newInfo(v, min[id][v]));
		}
	}
}


maxn Find1() {
	while (!Queue.empty() && done[Queue.top().v]) Queue.pop();

	if (Queue.empty()) return -1;

	maxn re = Queue.top().v;
	Queue.pop();

	return re;
}


void Dijkstra1() {
	std::fill(done, done + n, 0);
	std::fill(min[id], min[id] + n, maxR);
	clearQueue();

	cur = P[id];
	min[id][cur] = 0;

	while (cur != -1) {
		done[cur] = 1;
		//std::cout << id << ' ' << P[id] << ' ' << cur << ' ' << min[id][cur] << '\n';
		Fill1();
		cur = Find1();
	}
}


void Process1() {
	for (id = 0; id < p; id++) Dijkstra1();
}

// 1* ////////////////////////////////////////////////////////////////////////////////


// 2  ////////////////////////////////////////////////////////////////////////////////

void Get2(maxn u, maxn v, maxr re) {
	key = std::min(key, re);
}


bool check2() {
	return done2[0] + done2[1] + done2[2] + done2[3] + done2[4] == p;
}


void Try2(maxn i, maxn j, maxn cur, maxr t) {
	if (check2()) {
		Get2(i, cur, t + min[cur][P[j]]);
		return;
	}

	for (maxn id = 0; id < p; id++) {
		if (done2[id]) continue;

		done2[id] = 1;
		Try2(i, j, id, t + min[cur][P[id]]);
		done2[id] = 0;
	}
}


maxr Process2(maxn i, maxn j) {
		done2[i] = done2[j] = 1;
		key = maxR;

		Try2(i, j, i, 0);
		done2[i] = done2[j] = 0;

		return key;
}

// 2* //////////////////////////////////////////////////////////////////////////


// 3  //////////////////////////////////////////////////////////////////////////


bool check3(maxn u) {
	for (maxn i = 0; i < p; i++)
		if (u == P[i]) return 0;
	return 1;
}


maxr home3(maxn i, maxn j) {
	maxr re = maxR;
	for (maxn u = 0; u < n; u++) {
		if (!check3(u)) continue;
		re = std::min(re, min[i][u] + min[j][u]);
	}
	return re;
}


void Process2_3() {
	for (maxn i = 0; i < p; i++)
		for (maxn j = i; j < p; j++) {
			res = std::min(res, Process2(i, j) + home3(i, j));
			//std::cout << i << ' ' << j << ' '<< Process2(i, j) << ' ' << home(i, j) << ' ' << res << '\n';
		}
}

// 3* ///////////////////////////////////////////////////////////////////////////


int main() {
	Prepare();
	Process1();
	Process2_3();
	std::cout << res;
}