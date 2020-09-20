#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#pragma warning(disable:4996)

#define maxN 501
#define maxA 101
#define maxD 50001
#define maxF 4

typedef int maxn, maxa;

struct co {
	maxn x, y;
};
co newCo(maxn x, maxn y);

maxn m, n;
maxa a[maxN][maxN], re_m[maxN][maxN];
bool done[maxN][maxN];
int sp[maxF][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };


co newCo(maxn x, maxn y) {
	co re;
	re.x = x; re.y = y;
	return re;
}


void Prepare() {
	std::cin >> m >> n;

	for(maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			std::cin >> a[i][j];
			re_m[i][j] = maxD;
		}
}


struct pqueue {
	co Co;
	maxa a;
};
pqueue newPQ(co Co, maxa a);


class pq_cmp {
public:
	bool operator() (const pqueue &x, const pqueue &y) {
		return x.a > y.a;
	}
};
std::priority_queue < pqueue, std::vector < pqueue >, pq_cmp > pq;


pqueue newPQ(co Co, maxa a) {
	pqueue re;
	re.Co = Co; re.a = a;
	return re;
}


bool check(maxn x, maxn y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}


void Fill(co Co) {
	maxn x = Co.x, y = Co.y;

	for (maxn i = 0; i < maxF; i++) {
		maxn x1 = x + sp[i][0], y1 = y + sp[i][1];
		if (!check(x1, y1) || done[x1][y1] || re_m[x1][y1] < re_m[x][y] + a[x1][y1]) continue;

		re_m[x1][y1] = re_m[x][y] + a[x1][y1];
		pq.push(newPQ(newCo(x1, y1), re_m[x1][y1]));
	}
}


co Find() {
	while (!pq.empty() && done[pq.top().Co.x][pq.top().Co.y]) pq.pop();
	if (pq.empty()) return newCo(-1, -1);

	co re = pq.top().Co;

	//std::cout << re.x + 1 << ' ' << re.y + 1 << ' ' << re_m[re.x][re.y] << '\n';
	pq.pop();
	return re;
}


void Dijkstra() {
	for (maxn i = 0; i < m; i++) {
		pq.push(newPQ(newCo(i, 0), a[i][0]));
		re_m[i][0] = a[i][0];
		done[i][0] = 1;

		Fill(newCo(i, 0));
	}
	
	co cur = Find();

	while (cur.y != n - 1) {
		done[cur.x][cur.y] = 1;
		Fill(cur);
		cur = Find();
	}

	std::cout << re_m[cur.x][cur.y];
}


int main() {
	//freopen("fair.inp", "r", stdin);
	Prepare();
	Dijkstra();
}