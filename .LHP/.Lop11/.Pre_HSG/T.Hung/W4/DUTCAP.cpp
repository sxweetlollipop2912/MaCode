#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define maxN 100002
#define maxM 1000002

typedef long maxn, maxm;

maxn n, C, I, low[maxN], num[maxN], par[maxN], CNT, cntC[maxN], cntI[maxN], res;
maxm m;
std::vector <maxn> ad[maxN];
bool isC[maxN], isI[maxN];


void Prepare() {
	std::cin >> n >> m >> C >> I;

	for (maxn i = 0; i < C; i++) {
		maxn u;
		std::cin >> u, isC[u] = 1;
	}
	for (maxn i = 0; i < I; i++) {
		maxn u;
		std::cin >> u, isI[u] = 1;
	}
	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void DFS(maxn u) {
	low[u] = num[u] = ++CNT;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (!par[v]) {
			par[v] = u; DFS(v);

			low[u] = std::min(low[u], low[v]);
			cntC[u] += cntC[v], cntI[u] += cntI[v];
			res += (low[v] > num[u] && (cntC[v] == 0 || cntC[v] == C || cntI[v] == 0 || cntI[v] == I));
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}

	if (isC[u]) ++cntC[u];
	if (isI[u]) ++cntI[u];
}


void Process() {
	for (maxn u = 1; u <= n; u++) {
		if (par[u]) continue;
		par[u] = u;
		DFS(u);
	}
	std::cout << res;
}


int main() {
	freopen("dutcap.inp", "r", stdin);
	freopen("dutcap.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}