#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 101
#define direction 8
#define x first
#define y second

typedef int maxn;
typedef std::pair <maxn, maxn> co;

maxn m, n, res;
bool done[maxN][maxN];
int f[direction][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} };


void Prepare() {
	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			char c;
			std::cin >> c;
			done[i][j] = c == '.';
		}
	}
}


bool check(const maxn &i, const maxn &j) {
	return i >= 0 && i < m && j >= 0 && j < n;
}


void Mark(co cur) {
	std::queue <co> bfs;
	bfs.push(cur);
	done[cur.x][cur.y] = 1;

	while (!bfs.empty()) {
		cur = bfs.front();
		bfs.pop();

		for (int i = 0; i < direction; i++) {
			if (!check(cur.x + f[i][0], cur.y + f[i][1]) || done[cur.x + f[i][0]][cur.y + f[i][1]]) continue;
			bfs.push(co(cur.x + f[i][0], cur.y + f[i][1]));
			done[cur.x + f[i][0]][cur.y + f[i][1]] = 1;
		}
	}
}


void Process() {
	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			if (done[i][j]) continue;
			++res;
			Mark(co(i, j));
		}
	}
	std::cout << res;
}


int main() {
	//freopen("hoavan.inp", "r", stdin);
	//freopen("hoavan.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}