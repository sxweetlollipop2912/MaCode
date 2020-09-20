#include <iostream>
#include <fstream>

int n, m, k;
bool f[10001][10001], done[10001];

void Prepare() {
	freopen("GIAOSUA.inp", "r", stdin);
	freopen("GIAOSUA.out", "w", stdout);
	std::cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		if (t < k) continue;
		f[u - 1][v - 1] = 1;
		f[v - 1][u - 1] = 1;
	}
}


void DFS(int ii) {
	done[ii] = 1;
	for (int i = 0; i < n; i++)
		if (f[ii][i] && !done[i]) DFS(i);
}

int main() {
	Prepare();
	int re = 0;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		re++;
		DFS(i);
	}
	std::cout << re;
}
