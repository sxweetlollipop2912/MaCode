// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 30001
#define maxM 500001
#define root first
#define rank second

typedef int maxn;
typedef long maxm;
typedef std::pair <maxn, maxn> info_t;

maxn n, ppl[maxN];
maxm m;
info_t info[maxN];


void Prepare() {
	std::cin >> n >> m;
}


void Init() {
	for (maxn i = 0; i < n; i++) {
		ppl[i] = 1;
		info[i].root = i;
		info[i].rank = 0;
	}
}


maxn Root(maxn x) {
	while (x != info[x].root) x = info[x].root;
	return x;
}


void Union(maxn x, maxn y) {
	x = Root(x);
	y = Root(y);
	if (x == y) return;

	if (info[x].rank < info[y].rank) {
		info[x].root = y;
		ppl[y] += ppl[x];
	}
	else {
		info[y].root = x;
		if (info[y].rank == info[x].rank) ++info[x].rank;
		ppl[x] += ppl[y];
	}
	//std::cout << x << ' ' << y << ' ' << ppl[x] << ' ' << ppl[y] << '\n';
}


void Process() {
	while (m--) {
		maxn a, b;
		std::cin >> a >> b;
		--a; --b;
		Union(a, b);
	}
	std::cout << *std::max_element(ppl, ppl + n) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int test;
	std::cin >> test;
	
	while (test--) {
		Prepare();
		Init();
		Process();
	}
}