#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 301
#define maxs 603
#define idx(x) ((x) + 300)
#define bl 0
#define wh 1

typedef int maxn;

maxn n, D, cut[maxN], cnt_wh;
bool col[maxN];
std::vector <maxn> ad[maxN], s[maxN];


void Prepare() {
	std::cin >> n >> D;

	for (maxn i = 0; i < n; i++) {
		maxn u, c; std::cin >> u, std::cin >> col[u] >> c, cnt_wh += col[u];
		while (c--) {
			maxn v; std::cin >> v;
			ad[u].push_back(v);
		}
		s[i].resize(maxs, maxN);
	}
}


void DFS(const maxn u) {
	s[u][idx(0)] = 0; maxn d = (col[u] == bl ? 1 : -1);

	if (ad[u].size() < 2) {
		if (!ad[u].empty()) {
			DFS(ad[u][0]);
			s[u] = s[ad[u][0]], cut[u] = cut[ad[u][0]] + d;
			s[u][idx(cut[u])] = std::min(s[u][idx(cut[u])], 1);
		}
		else cut[u] = d, s[u][idx(d)] = std::min(s[u][idx(cut[u])], 1);
		return;
	}
	maxn v1 = ad[u][0], v2 = ad[u][1];
	DFS(v1); DFS(v2);
	for (maxn i = -n; i <= n; i++) for (maxn j = -n; j <= n; j++) {
		if (i + j > n || i + j < -n || s[v1][idx(i)] == maxN || s[v2][idx(j)] == maxN) continue;
		s[u][idx(i + j)] = std::min(s[u][idx(i + j)], s[v1][idx(i)] + s[v2][idx(j)]);
	}

	cut[u] = cut[v1] + cut[v2] + d;
	s[u][idx(cut[u])] = std::min(s[u][idx(cut[u])], 1);
}


void Process() {
	DFS(0);
	if (s[0][idx(D - (2 * cnt_wh - n))] != maxN) std::cout << s[0][idx(D - (2 * cnt_wh - n))];
	else std::cout << -1;
}


int main() {
	//freopen("prune.inp", "r", stdin);
	//freopen("prune.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}