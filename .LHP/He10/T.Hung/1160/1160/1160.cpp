// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 100002
#define maxM 10000000001
#define root first
#define rank second
#define fin -1

typedef int maxn;
typedef long long maxm;
typedef std::pair <maxn, maxn> info_t;

info_t info[maxN];
maxm res;


void Init() {
	res = 0;
	for (maxn i = 0; i < maxN - 1; i++) {
		info[i].root = i;
		info[i].rank = 0;
	}
}


maxn Root(maxn x) {
	while (x != info[x].root) x = info[x].root;
	return x;
}


void Union(maxn x, maxn y) {
	x = Root(x); y = Root(y);
	if (x == y) {
		++res;
		return;
	}

	if (info[x].rank < info[y].rank) 
		info[x].root = y;
	else {
		info[y].root = x;
		if (info[y].rank == info[x].rank) ++info[x].rank;
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Init();

	maxn a, b;
	while (std::cin >> a) {
		if (a == fin) {
			std::cout << res << '\n';
			Init();
		}
		else {
			std::cin >> b;
			a; b;
			Union(a, b);
		}
	}
}