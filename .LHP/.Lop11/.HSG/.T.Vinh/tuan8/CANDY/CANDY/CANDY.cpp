#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002

typedef long maxn;

maxn n, next[maxN], res[maxN], st;
bool inQ[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> next[i];
}	


void DFS(const maxn u, const maxn depth) {
	inQ[u] = 1;
	if (inQ[next[u]]) {
		st = next[u], res[u] = depth;
	}
	else {
		if (!res[next[u]]) DFS(next[u], depth + 1);
		res[u] = st ? res[next[u]] : res[next[u]] + 1;
	}
	inQ[u] = 0;
	st = u == st ? 0 : st;
}


void Process() {
	for (maxn i = 1; i <= n; i++) {
		if (!res[i]) DFS(i, 1);
		std::cout << res[i] << '\n';
	}
}


int main() {
	//freopen("candy.inp", "r", stdin);
	//freopen("candy.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}