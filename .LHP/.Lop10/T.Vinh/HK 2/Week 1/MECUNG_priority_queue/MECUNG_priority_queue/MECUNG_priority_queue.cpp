#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 103
#define maxL 101
#define maxR 100000

typedef int maxn;
typedef long long maxl;

struct coordinates {
	maxn x, y;
};

struct pqueue {
	coordinates c;
	maxl min_c;
};

maxl a[maxN][maxN], min_cur[maxN][maxN], L, res = maxR - 1;
bool done[maxN][maxN];
maxn n, m, cnt;
coordinates cur;

// ***********************************************************
// **** PRIORITY QUEUE _ SET UP ******************************

class cmp {
public:
	maxl operator() (const pqueue& p1, const pqueue& p2) {
		return p1.min_c > p2.min_c;
	}
};
std::priority_queue < pqueue, std::vector <pqueue>, cmp > pq;

// ***********************************************************


coordinates newCo(maxn x, maxn y) {
	coordinates re;
	re.x = x; re.y = y;
	return re;
}

pqueue newPQ(coordinates c, maxl min_c) {
	pqueue re;
	re.c = c; re.min_c = min_c;
	return re;
}


maxl Wait(char c) {
	if (c == '.') return 1;
	if (c == 'C') return L + 1;
	if (c == '#') return maxR;
	return maxR + 1;
}


void Count() {
	for (maxn i = 1; i <= n; i++)
		cnt += (a[1][i] != maxR) + (a[m][i] != maxR);
	for (maxn i = 2; i < m; i++)
		cnt += (a[i][1] != maxR) + (a[i][n] != maxR);
}


void Prepare() {
	std::cin >> m >> n >> L;

	for (maxn i = 1; i <= m; i++)
		for (maxn j = 1; j <= n; j++) {
			char c;
			std::cin >> c;

			if (c == 'A') cur = newCo(i, j);
			a[i][j] = Wait(c);
		}

	for (maxn i = 0; i <= m + 1; i++)
		std::fill(min_cur[i], min_cur[i] + n + 2, maxR);

	Count();
}


bool check(maxn x, maxn y) {
	bool re = x < 1 || x > m || y < 1 || y > n;
	if (re) res = std::min(res, min_cur[x][y]);

	return re;
}


void CheckF() {
	maxn x = cur.x, y = cur.y;
	cnt = cnt - check(x - 1, y) - check(x + 1, y) - check(x, y - 1) - check(x, y + 1);
}


void Fill() {
	maxn x = cur.x, y = cur.y;

	if (!done[x - 1][y] && min_cur[x - 1][y] > min_cur[x][y] + a[x - 1][y]) {
		min_cur[x - 1][y] = min_cur[x][y] + a[x - 1][y];
		pq.push(newPQ(newCo(x - 1, y), min_cur[x - 1][y]));
	}

	if (!done[x + 1][y] && min_cur[x + 1][y] > min_cur[x][y] + a[x + 1][y]) {
		min_cur[x + 1][y] = min_cur[x][y] + a[x + 1][y];
		pq.push(newPQ(newCo(x + 1, y), min_cur[x + 1][y]));
	}

	if (!done[x][y - 1] && min_cur[x][y - 1] > min_cur[x][y] + a[x][y - 1]) {
		min_cur[x][y - 1] = min_cur[x][y] + a[x][y - 1];
		pq.push(newPQ(newCo(x, y - 1), min_cur[x][y - 1]));
	}

	if (!done[x][y + 1] && min_cur[x][y + 1] > min_cur[x][y] + a[x][y + 1]) {
		min_cur[x][y + 1] = min_cur[x][y] + a[x][y + 1];
		pq.push(newPQ(newCo(x, y + 1), min_cur[x][y + 1]));
	}

	CheckF();
	min_cur[x][y] = maxR;
}


bool Find() {
	while (done[pq.top().c.x][pq.top().c.y]) pq.pop();
	cur = pq.top().c;
	pq.pop();

	return min_cur[cur.x][cur.y] < res;
}

void Dijkstra() {
	min_cur[cur.x][cur.y] = 0;
	done[cur.x][cur.y] = 1;

	do {
		Fill();
		if (!Find()) return;
		//std::cout << "o\n";
		done[cur.x][cur.y] = 1;
	} while (cnt != 0);
}


int main() {
	Prepare();
	Dijkstra();
	std::cout << res + 1;
}