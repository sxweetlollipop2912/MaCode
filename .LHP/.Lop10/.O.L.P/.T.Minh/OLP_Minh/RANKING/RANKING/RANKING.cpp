#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 32678
#define maxA 1000000

typedef int maxn;
typedef long maxa;

maxn n, m, bit[maxN], pos[maxN], rank[maxN];
maxa a[maxN];


bool cmp(const maxn &x, const maxn &y) {
	return a[x] > a[y];
}

void Prepare() {
	std::cin >> n >> m;

	maxn id[maxN];
	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}
	std::sort(id + 1, id + n + 1, cmp);

	for (maxn i = 1; i <= n; i++) 
		pos[id[i]] = i;
}


void Update(maxn id) {
	while (id <= n) {
		bit[id]++;
		id += id & (-id);
	}
}


maxn Get_Sum(maxn id) {
	maxn re = 0;
	while (id > 0) {
		re += bit[id];
		id -= id & (-id);
	}
	return re;
}


maxn Get_Rank(maxn id_x) {
	maxn id_pos = pos[id_x];
	return Get_Sum(id_pos);
}


void Process() {
	for (maxn i = 1; i <= n; i++) {
		Update(pos[i]);
		rank[i] = Get_Rank(i);
	}

	while (m--) {
		maxn x;
		std::cin >> x;
		std::cout << rank[x] << '\n';
	}
}


int main() {
	Prepare();
	Process();
}