#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 101

typedef int maxn;

bool d[maxN][maxN];
bool isVer[maxN];
maxn n;
maxn br_re, ver_re, low[maxN], num[maxN], par[maxN], numb;


void Prepare() {
	freopen("TRUYENTIN.inp", "r", stdin);
	//freopen("TRUYENTIN.out", "w", stdout);

	int m = 0;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		d[u - 1][v - 1] = d[v - 1][u - 1] = 1;
	}
}


void DFS(maxn u) {
	low[u] = maxN;
	num[u] = ++numb;
	maxn children = 0;

	for (maxn v = 0; v < n; v++) {
		if (!d[u][v]) continue;

		d[v][u] = 0;
		if (par[v] != 0) {
			low[u] = std::min(low[u], num[v]);
			continue;
		}

		par[v] = u;
		children++;
		DFS(v);
		low[u] = std::min(low[u], low[v]);

		if (low[v] >= num[v]) br_re++;

		if (par[u] == -1 && children >= 2) isVer[u] = 1;

		else if (par[u] != -1 && low[v] >= num[u]) isVer[u] = 1;
	}
}


/*void Res() {
	maxn child[maxN];

	for (maxn v = 0; v < n; v++) {
		maxn u = par[v];
		if (u != -1) {
			if (low[v] >= num[v]) br_re++;
			child[u]++;
		}
	}

	for (maxn u = 0; u < n; u++) {
		if (par[u] == -1 && child[u] >= 2) isVer[u] = 1;;
	}

	for (maxn v = 0; v < n; v++) {
		maxn u = par[v];
		if (u != -1 && par[u] != -1 && low[v] >= num[u]) isVer[u] = 1;
	}

	for (maxn i = 0; i < n; i++) ver_re += isVer[i];
}*/


int main() {
	Prepare();
	for (maxn i = 0; i < n; i++) {
		if (par[i] == 0) {
			par[i] = -1;
			DFS(i);
		}
	}
	//Res();
	for (maxn i = 0; i < n; i++) ver_re += isVer[i];

	std::cout << br_re << ' ' << ver_re;
}