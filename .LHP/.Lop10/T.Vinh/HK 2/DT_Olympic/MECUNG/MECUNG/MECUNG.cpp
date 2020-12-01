#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 302
#define maxD 90602
#define maxC 4

typedef long maxn;

struct co {
	maxn x, y;
};

maxn m, n, a[maxN][maxN], S[maxD], s, cnt, K;
bool done[maxN][maxN], disq[maxD];
int f[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
std::vector <co> adj_c[maxD];
std::vector <maxn> adj[maxD];


co newCo(maxn x, maxn y) {
	co re;
	re.x = x; re.y = y;
	return re;
}


bool check(maxn x, maxn y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}


void DFS(maxn x, maxn y, maxn key, maxn cnt) {
	if (a[x][y] != key && a[x][y] != cnt) {
		adj_c[cnt].push_back(newCo(x, y));
		return;
	}
	if (done[x][y]) return;

	s++;
	a[x][y] = cnt;
	done[x][y] = 1;

	for (int i = 0; i < maxC; i++)
		if (check(x + f[i][0], y + f[i][1])) DFS(x + f[i][0], y + f[i][1], key, cnt);
}


void Prepare_DFS() {
	std::cin >> m >> n >> K;

	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			char c;
			std::cin >> c;
			a[i][j] = (long)c + maxD;
		}

	cnt = 0;
	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) 
			if (!done[i][j]) {
				s = 0;
				DFS(i, j, a[i][j], cnt);
				S[cnt++] = s;
			}
}


void Adjacent() {
	bool done[maxD];
	for (maxn i = 0; i < cnt; i++) {
		std::fill(done, done + cnt, 0);

		while (!adj_c[i].empty()) {
			maxn size = adj_c[i].size();
			maxn id = a[adj_c[i][size - 1].x][adj_c[i][size - 1].y];
			adj_c[i].pop_back();

			if (done[id]) continue;
			adj[i].push_back(id);
			done[id] = 1;
		}
	}
}


void DFS_disq(maxn id) {
	maxn re = 0;
	for (maxn i = 0; i < adj[id].size(); i++) 
		re += !disq[adj[id][i]];

	if (re >= K) return;
	disq[id] = 1;

	for (maxn i = 0; i < adj[id].size(); i++) 
		if (!disq[adj[id][i]]) DFS_disq(adj[id][i]);
}


void Disq() {
	for (maxn i = 0; i < cnt; i++)
		if (!disq[i]) DFS_disq(i);
}


maxn DFS_S(maxn id) {
	if (!S[id]) return 0;
	maxn re = S[id];
	S[id] = 0;

	for (maxn i = 0; i < adj[id].size(); i++)
		if (!disq[adj[id][i]]) re += DFS_S(adj[id][i]);

	return re;
}


void MaxS() {
	maxn res = 0;
	for (maxn i = 0; i < cnt; i++)
		if (S[i]) res = std::max(res, DFS_S(i));
	std::cout << res;
}


int main() {
	freopen("mecung.inp", "r", stdin);
	freopen("mecung.out", "w", stdout);

	Prepare_DFS();
	Adjacent();
	Disq();
	MaxS();
}