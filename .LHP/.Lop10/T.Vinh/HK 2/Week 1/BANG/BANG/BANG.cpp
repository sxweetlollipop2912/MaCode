#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 302
#define maxD 1000000001 //10^9

typedef int maxn;
typedef long maxd;

struct coordinates {
	maxn x, y;
};

struct info {
	maxd re;
	bool done;
};

maxn m, n, xx, xy, yx, yy;
maxd a[maxN][maxN];
info r[maxN][maxN];


coordinates newCo(maxn x, maxn y) {
	coordinates re;
	re.x = x; re.y = y;
	return re;
}


info newInfo(maxd re, bool done) {
	info res;
	res.re = re; res.done = done;
	return res;
}


void Prepare() {
	std::cin >> m >> n >> xx >> xy >> yx >> yy;

	for (maxn i = 1; i <= m; i++) {
		for (maxn j = 1; j <= n; j++)
			std::cin >> a[i][j];

		std::fill(r[i] + 1, r[i] + n + 1, newInfo(maxD, 0));
	}

	r[0][0] = newInfo(maxD, 1);
}


bool cmp(info x, info y) {
	return x.re < y.re;
}


coordinates Find() {
	coordinates	res = newCo(0, 0);

	for (maxn i = 1; i <= m; i++) {
		maxn y = std::min_element(r[i] + 1, r[i] + n + 1, cmp) - r[i];
		if (r[res.x][res.y].re > r[i][y].re) res = newCo(i, y);
	}
			
	return res;
}


void Fill(coordinates c) {
	maxn x = c.x, y = c.y;

	if (x > 1 && !r[x - 1][y].done) 
		r[x - 1][y].re = std::min(r[x - 1][y].re, r[x][y].re + a[x - 1][y]);

	if (x < m && !r[x + 1][y].done)
		r[x + 1][y].re = std::min(r[x + 1][y].re, r[x][y].re + a[x + 1][y]);

	if (y > 1 && !r[x][y - 1].done)
		r[x][y - 1].re = std::min(r[x][y - 1].re, r[x][y].re + a[x][y - 1]);

	if (y < n && !r[x][y + 1].done)
		r[x][y + 1].re = std::min(r[x][y + 1].re, r[x][y].re + a[x][y + 1]);

	r[x][y].re = maxD;
}


bool check(coordinates a) {
	return a.x == yx && a.y == yy;
}


void Dijkstra() {
	coordinates cur = newCo(xx, xy);
	r[cur.x][cur.y] = newInfo(0, 1);

	while (!check(cur)) {
		Fill(cur);
		cur = Find();
		r[cur.x][cur.y].done = 1;
	}
}


int main() {
	Prepare();
	Dijkstra();
	std::cout << r[yx][yy].re;
}