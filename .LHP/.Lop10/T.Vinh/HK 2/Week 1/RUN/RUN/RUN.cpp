#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning (disable:4996)

#define maxN 1002
#define maxR 10000001

typedef long maxn;

struct coordinates {
	maxn x, y;
};

bool done[maxN][maxN];
bool f[maxN][maxN];
maxn n, m;
std::queue <coordinates> fire, Queue;


coordinates newCo(maxn x, maxn y) {
	coordinates re;
	re.x = x; re.y = y;
	return re;
}


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 1; i <= m; i++)
		for (maxn j = 1; j <= n; j++) {
			char c;
			std::cin >> c;

			if (c == 'S') Queue.push(newCo(i, j));
			else if (c == '*') {
				fire.push(newCo(i, j));
				f[i][j] = 1;
			}
			else if (c == '#') f[i][j] = 1;

			done[i][j] = c != '.';
		}
}


void FillFire(coordinates c) {
	maxn x = c.x, y = c.y;

	if (x > 1 && !f[x - 1][y]) {
		f[x - 1][y] = done[x - 1][y] = 1;
		fire.push(newCo(x - 1, y));
	}
	if (x < m && !f[x + 1][y]) {
		f[x + 1][y] = done[x + 1][y] = 1;
		fire.push(newCo(x + 1, y));
	}
	if (y > 1 && !f[x][y - 1]) {
		f[x][y - 1] = done[x][y - 1] = 1;
		fire.push(newCo(x, y - 1));
	}
	if (y < n && !f[x][y + 1]) {
		f[x][y + 1] = done[x][y + 1] = 1;
		fire.push(newCo(x, y + 1));
	}
}


void Fire() {
	maxn len = fire.size();

	while (len--) {
		FillFire(fire.front());
		fire.pop();
	}
}


bool Fill(coordinates c) {
	maxn x = c.x, y = c.y;

	if (x > 1 && !done[x - 1][y]) {
		done[x - 1][y] = 1;
		Queue.push(newCo(x - 1, y));
		if (x - 1 == 1) return 1;
	}
	if (x < m && !done[x + 1][y]) {
		done[x + 1][y] = 1;
		Queue.push(newCo(x + 1, y));
		if (x + 1 == m) return 1;
	}
	if (y > 1 && !done[x][y - 1]) {
		done[x][y - 1] = 1;
		Queue.push(newCo(x, y - 1));
		if (y - 1 == 1) return 1;
	}
	if (y < n && !done[x][y + 1]) {
		done[x][y + 1] = 1;
		Queue.push(newCo(x, y + 1));
		if (y + 1 == n) return 1;
	}

	return 0;
}


void BFS() {
	maxn step = 0;
	bool halt = Queue.front().x == 1 || Queue.front().x == m || Queue.front().y == 1 || Queue.front().y == n;

	while (!halt && !Queue.empty()) {
		step++;
		maxn len = Queue.size();
		Fire();

		while (len--) {
			if (Fill(Queue.front())) {
				halt = 1;
				break;
			}
			Queue.pop();
		}
	}

	if (halt) std::cout << step + 1;
	else std::cout << "NO";
}


int main() {
	freopen("run.inp", "r", stdin);
	Prepare();
	BFS();
}