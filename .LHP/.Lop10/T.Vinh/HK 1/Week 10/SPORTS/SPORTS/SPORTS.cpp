#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning (disable:4996)

#define maxN 1001
#define maxM 1000001
#define maxK 251

typedef int maxn, maxk;

maxn n, low[maxN], num[maxN], re, numb;
maxk K;
bool d[maxN][maxN], fr[maxN];
std::vector <maxn> stack;


void Prepare() {
	freopen("SPORTS.inp", "r", stdin);
	//freopen("SPORTS.out", "w", stdout);

	long m = 0;
	std::cin >> n >> m >> K;

	for (long i = 0; i < m; i++) {
		maxn u, v;
		maxk k;
		std::cin >> u >> v >> k;
		if (k >= K) d[u - 1][v - 1] = 1;
	}
}



void DFS(maxn u) {
	num[u] = ++numb;
	low[u] = num[u];
	stack.push_back(u);

	for (maxn v = 0; v < n; v++) {
		if (!d[u][v] || fr[v]) continue;

		if (num[v] == 0) {
			DFS(v);
			low[u] = std::min(low[u], low[v]);
		}
		else low[u] = std::min(low[u], num[v]);
	}

	if (low[u] == num[u]) {
		re++;
		maxn v;
		do {	
			v = stack.back();
			fr[v] = 1;
			stack.pop_back();
		} while (u != v);
	}
}


int main() {
	Prepare();
	for (maxn i = 0; i < n; i++)
		if (num[i] == 0) DFS(i);
	std::cout << re;
}