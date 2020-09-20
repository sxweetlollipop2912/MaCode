#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 251
#define maxM 62251
#define LIMIT 20
#define maxR maxN * LIMIT

typedef int maxn, maxm, maxr;

struct bfs_t {
	maxn x1, x2;
};
bfs_t newBFS_t(maxn x1, maxn x2) {
	bfs_t re;
	re.x1 = x1; re.x2 = x2;
	return re;
}

maxn n, x1, x2;
maxm m;
std::vector <maxn> ad[maxN];
bool done[maxN][maxN];
std::queue <bfs_t> bfs;


void Prepare() {
	std::cin >> n >> m >> x1 >> x2;

	x1--; x2--;
	bfs.push(newBFS_t(x1, x2));

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		ad[u].push_back(v);
	}
}


bool Add(bfs_t cur) {
	maxn u1 = cur.x1, u2 = cur.x2;

	for (maxn i1 = 0; i1 < ad[u1].size(); i1++) {
		for (maxn i2 = 0; i2 < ad[u2].size(); i2++) {
			maxn v1 = ad[u1][i1];
			maxn v2 = ad[u2][i2];
			if (done[v1][v2]) continue;

			done[v1][v2] = done[v2][v1] = 1;
			bfs.push(newBFS_t(v1, v2));

			if (v1 == v2) return 1;
		}
	}

	return 0;
}


maxr BFS() {
	if (x1 == x2) return 0;

	maxr lim = n * LIMIT;

	for (maxr time = 1; time < lim && !bfs.empty(); time++) {
		maxm avai = bfs.size();

		while (avai--) {
			if (Add(bfs.front())) return time;
			bfs.pop();
		}
	}

	return -1;
}


int main() {
	Prepare();
	std::cout << BFS();
}