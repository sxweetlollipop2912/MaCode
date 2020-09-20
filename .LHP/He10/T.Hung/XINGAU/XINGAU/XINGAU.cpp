#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 51
#define maxX 2502
#define bground '.'
//#define xn '*'
#define pix 'X'

typedef int maxn;

maxn n, m, xid[maxN][maxN], cntp[maxX];
char map[maxN][maxN];
int sp[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
std::vector <maxn> res;


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			std::cin >> map[i][j];
		}
	}
}


bool check(const maxn x) {
	return x >= 0 && x < n;
}

void DFS1(const maxn x, const maxn y, const maxn fill) {
	xid[x][y] = fill;

	for (int ii = 0; ii < 4; ii++) {
		maxn i = x + sp[ii][0], j = y + sp[ii][1];
		if (!check(i) || !check(j) || map[i][j] == bground || xid[i][j]) continue;
		DFS1(i, j, fill);
	}
}


void DFS2(const maxn x, const maxn y) {
	xid[x][y] = 0;

	for (int ii = 0; ii < 4; ii++) {
		maxn i = x + sp[ii][0], j = y + sp[ii][1];
		if (!check(i) || !check(j) || !xid[i][j] || map[i][j] != pix) continue;
		DFS2(i, j);
	}
}


void Process() {
	maxn fill = 0;
	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			if (xid[i][j] || map[i][j] == bground) continue;
			DFS1(i, j, ++fill);
		}
	}

	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			if (!xid[i][j] || map[i][j] != pix) continue;
			++cntp[xid[i][j]];
			//std::cout << i << ' ' << j << ' ' << xid[i][j] << ' ' << cntp[xid[i][j]] << '\n';
			DFS2(i, j);
		}
	}

	res.clear();
	for (maxn i = 0; i < maxX; i++)
		if (cntp[i]) res.push_back(cntp[i]);
	
	std::sort(res.begin(), res.end());

	for (maxn i = 0; i < res.size(); i++)
		std::cout << res[i] << ' ';
}


int main() {
	//freopen("xingau.inp", "r", stdin);
	//freopen("xingau.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}