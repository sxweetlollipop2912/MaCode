#include <iostream>
#include <algorithm>

#define maxN 8
#define maxA 6

typedef int t;

t n, m, id[maxN], cnt[maxA], ad[maxN], res;
bool g[maxN][maxN], p[maxA][maxA];


void Prepare() {
	std::cin >> n >> m;
	for (t i = 0; i < m; i++) {
		t u, v;
		std::cin >> u >> v;
		--u, --v;
		g[u][v] = g[v][u] = 1, ++ad[u], ++ad[v];
	}
	for (t i = 0; i < n; i++) id[i] = i;
}


void Trial(t id[]) {
	for (t i = 0; i < maxA; i++) std::fill(p[i], p[i] + maxA, 1);

	t re = 0;
	for (t i = 0; i < 6; i++) for (t j = i + 1; j < 6; j++) {
		if (!g[id[i]][id[j]]) continue;
		p[i][j] = p[j][i] = 0, ++re;
	}

	std::fill(cnt, cnt + maxA, 0);
	for (t i = 0; i < 6; i++) if (g[id[i]][id[6]]) for (t j = 0; j < 6; j++) cnt[j] += p[i][j];
	res = std::max(res, re + std::min(ad[id[6]], *std::max_element(cnt, cnt + maxA)));
}


void Process() {
	res = 0;
	if (n != 7) res = m;

	else for (t i = 0; i < 7; i++) {
		std::swap(id[i], id[6]);
		Trial(id);
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}