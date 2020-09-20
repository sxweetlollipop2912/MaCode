#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>

#define maxN 11
#define empty 0
#define desti 1
#define block 2

typedef int maxn, maxa;
typedef long long maxr;

struct co {
	maxn x, y;
};

struct mem {
	co v1, v2;
	maxr step;
};

maxa a[maxN][maxN];
maxn n, m;
bool done[maxN][maxN][maxN][maxN];
std::queue <mem> bfs;
co des, start[2];
maxr res;


co newCo(maxn x, maxn y) {
	co re;
	re.x = x; re.y = y;
	return re;
}


mem newMem(co v1, co v2, maxr step){
	mem re;
	re.v1 = v1; re.v2 = v2; re.step = step;
	return re;
}


void Done(mem x) {
	co v1 = x.v1, v2 = x.v2;

	done[v1.x][v1.y][v2.x][v2.y] = 1;
	done[v2.x][v2.y][v1.x][v1.y] = 1;
}


void Prepare() {
	std::cin >> n >> m;

	bool p = 0;
	for(maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			char c;
			std::cin >> c;

			if (c == '#') a[i][j] = block;

			else if (c == 'M') {
				a[i][j] = desti;
				des = newCo(i, j);
			}

			else a[i][j] = empty;

			if (c != '1' && c != '2') continue;

			start[p] = newCo(i, j);
			p = !p;
		}
}


mem Up(co v, co stand, maxr step) {
	maxn x = v.x, y = v.y, xs = stand.x, ys = stand.y;

	for (x = x; x >= 0; x--) {
		if (!x) break;
		if (a[x - 1][y] == block || (x - 1 == xs && y == ys)) break;
	}

	return newMem(newCo(x, y), stand, step);
}


mem Down(co v, co stand, maxr step) {
	maxn x = v.x, y = v.y, xs = stand.x, ys = stand.y;

	for (x = x; x < m; x++) {
		if (x == m - 1) break;
		if (a[x + 1][y] == block || (x + 1 == xs && y == ys)) break;
	}

	return newMem(newCo(x, y), stand, step);
}


mem Left(co v, co stand, maxr step) {
	maxn x = v.x, y = v.y, xs = stand.x, ys = stand.y;

	for (y = y; y >= 0; y--) {
		if (!y) break;
		if (a[x][y - 1] == block || (x == xs && y - 1 == ys)) break;
	}

	return newMem(newCo(x, y), stand, step);
}


mem Right(co v, co stand, maxr step) {
	maxn x = v.x, y = v.y, xs = stand.x, ys = stand.y;

	for (y = y; y < n; y++) {
		if (y == n - 1) break;
		if (a[x][y + 1] == block || (x == xs && y + 1 == ys)) break;
	}

	return newMem(newCo(x, y), stand, step);
}


void Add(mem x) {
	co v1 = x.v1, v2 = x.v2;
	if (done[v1.x][v1.y][v2.x][v2.y]) return;

	done[v1.x][v1.y][v2.x][v2.y] = done[v2.x][v2.y][v1.x][v1.y] = 1;
	bfs.push(newMem(v1, v2, x.step));

	if (a[v1.x][v1.y] == desti || a[v2.x][v2.y] == desti) res = x.step;
}


void Push(mem x) {
	co v1 = x.v1, v2 = x.v2;
	maxr step = x.step;

	Add(Up(v1, v2, step + 1));
	Add(Up(v2, v1, step + 1));

	Add(Down(v1, v2, step + 1));
	Add(Down(v2, v1, step + 1));

	Add(Left(v1, v2, step + 1));
	Add(Left(v2, v1, step + 1));
	
	Add(Right(v1, v2, step + 1));
	Add(Right(v2, v1, step + 1));
}


void BFS() {
	Add(newMem(start[0], start[1], 0));

	while (!res) {
		Push(bfs.front());
		bfs.pop();
	}
}


int main() {
	Prepare();
	BFS();
	std::cout << res;
}