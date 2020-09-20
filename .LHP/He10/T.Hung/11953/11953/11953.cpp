#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 101
#define water '.'
#define ship 'x'
#define wreck '@'
#define done 'X'

typedef int maxn;

maxn n, res;
char map[maxN][maxN];
int sp[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }, cntq;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		for (maxn j = 0; j < n; j++) std::cin >> map[i][j];
	}
}


bool check(const maxn x) {
	return x >= 0 && x < n;
}

void DFS(const maxn x, const maxn y) {
	map[x][y] = done;
	
	for (int ii = 0; ii < 4; ii++) {
		maxn i = x + sp[ii][0], j = y + sp[ii][1];
		if (!check(i) || !check(j) || map[i][j] == done || map[i][j] == water) continue;
		DFS(i, j);
	}
}


void Process() {
	res = 0;

	for (maxn i = 0; i < n; i++) {
		for (maxn j = 0; j < n; j++) {
			if (map[i][j] != ship) continue;
			DFS(i, j);
			++res;
		}
	}

	std::cout << "Case " << cntq << ": " << res << '\n';
}


int main() {
	//freopen("11953.inp", "r", stdin);
	//freopen("11953.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	cntq = 0;
	while (q--) {
		++cntq;
		Prepare();
		Process();
	}	
}