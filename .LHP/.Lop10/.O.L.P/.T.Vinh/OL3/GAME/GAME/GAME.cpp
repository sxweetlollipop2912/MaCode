#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
#define block 1
#define empt 0
#define maxT 3

typedef int maxn;
typedef long maxr;

struct pq {
	maxn x, y;
	maxr blocked;
};
pq newPQ(maxn x, maxn y, maxr blocked);

pq newPQ(maxn x, maxn y, maxr blocked) {
	pq re;
	re.x = x; re.y = y; re.blocked = blocked;
	return re;
}


maxn m, n;
bool a[maxN][maxN], done[maxN][maxN];
int sp[3][2] = { {-1,1},{0,1},{1,1} };


void Prepare() {
	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			char c;
			std::cin >> c;

			a[i][j] = c == '#';
		}
	}
}


bool check(maxn x, maxn y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}


class cmp {
public:
	bool operator()(const pq &p1, const pq &p2) {
		return p1.blocked < p2.blocked;
	}
};
std::priority_queue <pq, std::vector <pq>, cmp> bfs;


bool Add(const pq root) {
	bfs.pop();
	bool did = 0;

	for (maxr i = 0; i < maxT; i++) {
		maxn x = root.x + sp[i][0], y = root.y + sp[i][1];
		if (!check(x, y) || done[x][y]) continue;

		did = 1;
		bfs.push(newPQ(x, y, root.blocked + a[x][y]));
		done[x][y] = 1;
	}

	return did;
}


void BFS() {
	for (maxn i = 0; i < m; i++) {
		bfs.push(newPQ(i, 0, a[i][0]));
		done[i][0] = 1;
	}

	while (!bfs.empty() && Add(bfs.top()));

	if (!bfs.empty()) std::cout << n - bfs.top().blocked;
	else std::cout << -1;
}


int main() {
	Prepare();
	BFS();
}