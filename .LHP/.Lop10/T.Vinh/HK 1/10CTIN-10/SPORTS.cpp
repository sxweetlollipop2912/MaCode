#include <iostream>
#include <fstream>
#include <algorithm>

#define maxN 1001
#define maxM 100001
#define maxK 251

typedef int maxn;

maxn n, cnt, re[maxN], num = 1;
bool d[maxN][maxN], mark[maxN], count[maxN];


void Prepare() {
	freopen("SPORTS.inp", "r", stdin);
	freopen("SPORTS.out", "w", stdout);
	int m = 0, K = 0;
	std::cin >> n >> m >> K;
	for (int i = 0; i < m; i++) {
		maxn u, v;
		int k;
		std::cin >> u >> v >> k;
		if (k >= K) d[u - 1][v - 1] = 1;
	}
}

void DFS(maxn a) {
	mark[a] = 1;
	re[a] = num++;
	for (maxn i = 0; i < n; i++) {
		if (!d[a][i]) continue;
		if (!mark[i]) DFS(i);
		if (re[a] > re[i]) {
			re[a] = re[i];
		}
	}
	mark[a] = 0;
}

int main() {
	Prepare();
	for (int i = 0; i < n; i++) {
		if (re[i] == 0) DFS(i);
		cnt += 1 - count[re[i]];
		count[re[i]] = 1;
	}
	std::cout << cnt;
}
