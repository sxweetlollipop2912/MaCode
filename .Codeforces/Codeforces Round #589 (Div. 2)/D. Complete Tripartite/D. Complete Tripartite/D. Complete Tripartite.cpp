#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 100001
#define maxM 300001

typedef long maxn, maxm;

maxn n;
maxm m;
std::vector <maxn> ad[maxN];
int col[maxN];
maxn fill[maxN][3];


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


bool Process() {
	maxn cnt1 = 0, cnt2 = 0, cnt3 = 0;

	for (maxn u = 0; u < n; u++) {
		if (fill[u][0]) continue;

		fill[u][0] = 1, ++cnt1, col[u] = 1;

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			++fill[v][0];
		}
	}
	if (!cnt1) return 0;

	for (maxn u = 0; u < n; u++) {
		if (col[u])  continue;
		if (fill[u][0] != cnt1) return 0;
		if (fill[u][1]) continue;

		fill[u][1] = 1, ++cnt2, col[u] = 2;

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			++fill[v][1];
		}
	}
	if (!cnt2) return 0;

	for (maxn u = 0; u < n; u++) {
		if (col[u]) continue;
		if (fill[u][1] != cnt2) return 0;
		if (fill[u][2]) continue;

		fill[u][2] = 1, ++cnt3, col[u] = 3;

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			++fill[v][2];
		}
	}
	if (!cnt3) return 0;

	for (maxn i = 0; i < n; i++) if (!col[i]) return 0;
	for (maxn i = 0; i < n; i++) std::cout << col[i] << ' ';

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}