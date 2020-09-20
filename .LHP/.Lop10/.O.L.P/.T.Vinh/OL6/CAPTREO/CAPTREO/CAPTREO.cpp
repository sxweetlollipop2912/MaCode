#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 1002
#define maxC 50001
#define up 0
#define down 1

typedef int maxn, maxc;
typedef long maxr;

maxn N, C, h[maxC];
maxn A[maxC], B[maxC];
bool dir[maxC], hooman[maxC], gone_h[maxN], used[maxC][2];
//std::queue <maxn> bfs;
std::vector <maxc> present[maxN];
std::vector <maxn> pos;


void Prepare() {
	std::cin >> N >> C;

	for (maxn i = 0; i < C; i++) {
		std::cin >> A[i] >> B[i]; // A < B
		h[i] = B[i];
		present[h[i]].push_back(i);
		dir[i] = up;
	}
}


bool nextDir(maxc x) {
	return h[x] == A[x] ? up : h[x] == B[x] ? down : dir[x];
}

maxn nextStop(maxc x) {
	return nextDir(x) == up ? B[x] : A[x];
}

bool Next(maxc x) {
	dir[x] = nextDir(x);
	if (used[x][dir[x]]) return 0;

	h[x] = dir[x] == up ? h[x] + 1 : h[x] - 1;
	return h[x] == A[x] || h[x] == B[x];
}


void Update() {
	for (maxn i = 0; i <= N; i++) present[i].clear();

	for (maxc i = 0; i < C; i++) {
		if (!Next(i)) continue;
		present[h[i]].push_back(i);

		if (!hooman[i]) continue;
		pos.push_back(h[i]);
		gone_h[h[i]] = 1;
	}
}


bool Add(maxn n) {
	if (n == 1) return 1;

	for (maxc ii = 0; ii < present[n].size(); ii++) {
		maxc i = present[n][ii];

		if (gone_h[nextStop(i)]) continue;
		hooman[i] = 1;
		used[i][nextDir(i)] = 1;
	}

	return 0;
}


maxn BFS() {
	maxn start = N;
	pos.push_back(start);
	gone_h[start] = 1;

	maxr time = 0;
	while (!pos.empty()) {
		for (maxn i = 0; i < pos.size(); i++)
			if (Add(pos[i])) return time;

		time++;
		Update();
	}

	return -1;
}


int main() {
	Prepare();
	std::cout << BFS();
}