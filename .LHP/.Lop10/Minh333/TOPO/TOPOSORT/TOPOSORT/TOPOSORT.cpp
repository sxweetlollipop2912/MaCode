#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)
#define maxN 1000
#define maxM 500000

typedef int maxn;

maxn n;
bool d[maxN][maxN];
maxn cnt[maxN];
std::vector<maxn> Save[maxN];


void Prepare() {
	freopen("TOPOSORT.inp", "r", stdin);
	freopen("TOPOSORT.out", "w", stdout);
	long m = 0;
	std::cin >> n >> m;
	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		d[u - 1][v - 1] = 1;
	}
	std::fill(cnt, cnt + n, -1);
}


void Trace(maxn a) {
	cnt[a] = 0;
	for (maxn i = 0; i < n; i++) {
		if (d[i][a]) {
			if (cnt[i] == -1) Trace(i);
			cnt[a] = std::max(cnt[a], cnt[i] + 1);
		}
	}
	Save[cnt[a]].push_back(a);
}

int main() {
	Prepare();
	
	for (maxn i = 0; i < n; i++)
		if (cnt[i] == -1) Trace(i);
	
	maxn count = 0, ii = -1;
	while (count < n) {
		ii++;
		for (maxn i = 0; i < Save[ii].size(); i++) {
			std::cout << Save[ii][i] + 1 << ' ';
			count++;
		}
	}

	std::cout << '\n';
	for (maxn i = 0; i < n; i++) std::cout << cnt[i] << ' ';
}