#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#pragma warning(disable:4996)
#define maxN 1000
#define maxM 5000000

typedef int maxn;

maxn n;
bool d[maxN][maxN], done[maxN];
maxn place[maxN], len[maxN], count = -1;

void Prepare() {
	freopen("TOPOSORT.inp", "r", stdin);
	freopen("TOPOSORT.out", "w", stdout);
	long m = 0;
	std::cin >> n >> m;
	maxn u, v;
	for (maxn i = 0; i < m; i++) {
		std::cin >> u >> v;
		d[u - 1][v - 1] = 1;
	}
}


void Trace(maxn x) {
	done[x] = 1;
	for (maxn i = 0; i < n; i++) {
		if (d[i][x]) {
			if (!done[i]) Trace(i);
			len[x] = std::max(len[x], len[i] + 1);
		}
	}
	place[++count] = x + 1;
}


int main() {
	Prepare();
	for (maxn i = 0; i < n; i++)
		if (!done[i]) Trace(i);
	for (maxn i = 0; i < n; i++) std::cout << place[i] << ' ';
	std::cout << '\n';
	for (maxn i = 0; i < n; i++) std::cout << len[i] << ' ';
}
