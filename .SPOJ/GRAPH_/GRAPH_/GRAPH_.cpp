// AC SPOJ
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 10001
#define maxM 50001

typedef int maxn, maxm;

maxn n, par[maxN], low[maxN], num[maxN], child[maxN], CNT, res_a;
bool isArti[maxN];
maxm m, res_b;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v, --u, --v;
		ad[u].push_back(v); ad[v].push_back(u);
	}
}


void DFS(const maxn u) {
	low[u] = num[u] = ++CNT, child[u] = 0;

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[v] == -1) {
			par[v] = u;
			DFS(v);
			low[u] = std::min(low[u], low[v]), ++child[u];
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}
}


void Process() {
	std::fill(par, par + n, -1);
	for (maxn i = 0; i < n; i++) {
		if (par[i] != -1) continue;
		par[i] = i; DFS(i);
	}

	for (maxn v = 0; v < n; v++) {
		maxn u = par[v];
		if (u == v && child[v] > 1) res_a += !isArti[v], isArti[v] = 1;
		if (par[u] != u && low[v] >= num[u]) res_a += !isArti[u], isArti[u] = 1;
		if (low[v] > num[u]) ++res_b;
	}

	std::cout << res_a << ' ' << res_b;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}