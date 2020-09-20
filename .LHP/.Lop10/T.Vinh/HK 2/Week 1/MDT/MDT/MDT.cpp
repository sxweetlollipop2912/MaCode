/* 0 -> \ && 1 -> / */
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#pragma warning (disable:4996)

#define maxN 502
#define maxR 9999999

typedef long maxr, maxn;

struct info {
	maxn x, y;
	maxr r;
};

bool a[maxN][maxN], done[maxN][maxN];
maxr min_cur[maxN][maxN];
maxn n, m, cx, cy;


class cmp {
public:
	maxr operator() (info x, info y) {
		return x.r > y.r;
	}
};
std::priority_queue < info, std::vector <info>, cmp > pq;


info newInfo(maxn x, maxn y, maxr r) {
	info re;
	re.x = x; re.y = y; re.r = r;
	return re;
}


void Prepare() {
	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			char c;
			std::cin >> c;

			a[i][j] = c == '/';
		}

	for (maxn i = 0; i <= m; i++) std::fill(min_cur[i], min_cur[i] + n + 1, maxR);
}


void Fill(maxn x, maxn y) {

	if (x > 0 && y > 0 && !done[x - 1][y - 1]) {
		bool c = a[x - 1][y - 1] == 1;

		if (min_cur[x - 1][y - 1] > min_cur[x][y] + c) {
			min_cur[x - 1][y - 1] = min_cur[x][y] + c;
			pq.push(newInfo(x - 1, y - 1, min_cur[x - 1][y - 1]));
		}
	}

	if (x > 0 && y < n && !done[x - 1][y + 1]) {
		bool c = a[x - 1][y] == 0;

		if (min_cur[x - 1][y + 1] > min_cur[x][y] + c) {
			min_cur[x - 1][y + 1] = min_cur[x][y] + c;
			pq.push(newInfo(x - 1, y + 1, min_cur[x - 1][y + 1]));
		}
	}

	if (x < m && y > 0 && !done[x + 1][y - 1]) {
		bool c = a[x][y - 1] == 0;

		if (min_cur[x + 1][y - 1] > min_cur[x][y] + c) {
			min_cur[x + 1][y - 1] = min_cur[x][y] + c;
			pq.push(newInfo(x + 1, y - 1, min_cur[x + 1][y - 1]));
		}
	}

	if (x < m && y < n && !done[x + 1][y + 1]) {
		bool c = a[x][y] == 1;

		if (min_cur[x + 1][y + 1] > min_cur[x][y] + c) {
			min_cur[x + 1][y + 1] = min_cur[x][y] + c;
			pq.push(newInfo(x + 1, y + 1, min_cur[x + 1][y + 1]));
		}
	}

}


bool Find() {
	while (!pq.empty() && done[pq.top().x][pq.top().y]) pq.pop();
	if (pq.empty()) return 0;

	cx = pq.top().x;
	cy = pq.top().y;
	pq.pop();

	return 1;
}


void Dijkstra() {
	cx = 0; cy = 0;
	done[cx][cy] = 1;
	min_cur[cx][cy] = 0;

	do {
		Fill(cx, cy);
		if (!Find()) return;
		done[cx][cy] = 1;
	} while (!done[m][n]);
}


int main() {
	freopen("mdt.inp", "r", stdin);
	Prepare();
	Dijkstra();
	if (min_cur[m][n] != maxR) std::cout << min_cur[m][n];
	else std::cout << "NO";
}