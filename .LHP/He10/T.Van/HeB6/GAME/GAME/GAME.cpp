#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100001

typedef long maxn;

maxn n, ad[maxN], re[maxN], res;


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> ad[i];
		--ad[i];
		re[i] = -1;
	}
}


maxn DFS(const maxn &u) {
	re[u] = 0;
	re[u] = re[ad[u]] != -1 ? re[ad[u]] + 1 : DFS(ad[u]) + 1;
	return re[u];
}


void Process() {
	res = 0;
	for (maxn i = 0; i < n; i++)
		if (re[i] == -1 && DFS(i) > re[res]) res = i;
}


int main() {
	//freopen("game.inp", "r", stdin);
	//freopen("game.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
	std::cout << res + 1 << ' ' << re[res] << '\n';
}