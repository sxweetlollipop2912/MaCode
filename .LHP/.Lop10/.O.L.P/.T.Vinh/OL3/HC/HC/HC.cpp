#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#define maxN 1001
#define maxH 4
#define gold 0
#define sil 1
#define cop 2
#define ste 3

typedef int maxn, maxa;
typedef long long maxr;

struct quantity {
	maxa q[maxH];
};


struct queue {
	quantity q[maxH];
	maxr step;
};


void incQ(queue &x, maxa root, maxa inc) {
	x.q[root].q[inc]++;
}

void decQ(queue &x, maxa root, maxa dec) {
	x.q[root].q[dec]--;
}

maxn val(const queue &x, maxa root, maxa dif) {
	return x.q[root].q[dif];
}

maxa medal(const char &c) {
	return c == 'V' ? gold : c == 'B' ? sil : c == 'D' ? cop : ste;
}


maxn n;
queue start;


void Prepare() {
	std::cin >> n;

	maxn cnt[maxH];
	std::fill(cnt, cnt + maxH, 0);
	maxa a[maxN], map[maxN];

	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		a[i] = medal(c);
		cnt[a[i]]++;
	}

	maxn len = 0;
	for (maxa i = 0; i < maxH; i++)
		for (maxn j = 0; j < cnt[i]; j++) map[len++] = i;

	for (maxn i = 0; i < n; i++) 
		incQ(start, map[i], a[i]);
}


std::queue <queue> bfs;

bool Add_BFS(const queue &root) {
	bool check = 0;

	for (maxa i = 0; i < maxH; i++) {
		for (maxa j = 0; j < maxH; j++) {
			if (i == j || val(root, i, j) == 0) continue;

			queue tmp = root;
			tmp.step++;

			decQ(tmp, i, j);
			incQ(tmp, j, j);

			for (maxa k = 0; k < maxH; k++) {
				if (k == j || val(root, j, k) == 0) continue;
				check = 1;

				decQ(tmp, j, k);
				incQ(tmp, i, k);

				bfs.push(tmp);

				incQ(tmp, j, k);
				decQ(tmp, i, k);
			}
		}
	}

	return check;
}


void BFS() {

	start.step = 0;
	bfs.push(start);

	while (!bfs.empty() && Add_BFS(bfs.front())) bfs.pop();

	std::cout << bfs.front().step;
}


int main() {
	Prepare();
	BFS();
}