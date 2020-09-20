#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 10002

typedef int maxn;

maxn n, par[maxN], child[maxN], K, has[maxN], res;
std::queue <maxn> queue;
bool del[maxN];


void Push(const maxn x) {
	if (!child[x]) queue.push(x);
}


void Prepare() {
	std::cin >> K >> n;

	for (maxn i = 2; i <= n; i++) {
		std::cin >> par[i];
		child[par[i]]++;
	}

	for (maxn i = 1; i <= n; i++) {
		Push(i);
		has[i] = 1;
	}

	par[1] = 0; del[0] = 1;
}


void Delete(const maxn x) {
	del[x] = 1;
	--child[par[x]];
	Push(par[x]);

	++res;
}


void Up(const maxn x) {
	if (del[par[x]]) return;
	has[par[x]] += has[x];

	if (has[par[x]] >= K) Delete(par[x]);
	else {
		--child[par[x]];
		Push(par[x]);
	}
}


void Process() {
	while (!queue.empty()) {
		Up(queue.front());
		queue.pop();
	}
	std::cout << res;
}


int main() {
	//freopen("org.inp", "r", stdin);
	//freopen("org.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}