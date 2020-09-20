// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100002
#define maxM 1000001

typedef long maxn, maxm;

maxn n, A, B, low[maxN], num[maxN], CNT, cntA, cntB, curA[maxN], curB[maxN], par[maxN];
maxm m, res;
bool isA[maxN], isB[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m >> A >> B;
	
	maxn u, v;
	for (maxn i = 0; i < A; i++) std::cin >> u, isA[u] = 1;
	for (maxn i = 0; i < B; i++) std::cin >> u, isB[u] = 1;

	for (maxm i = 0; i < m; i++) {
		std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void DFS_b(const maxn u) {
	low[u] = num[u] = ++CNT, curA[u] = isA[u], curB[u] = isB[u];

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[v] == u) {
			DFS_b(v);
			//if (num[u] < low[v]) std::cout << u << ' ' << v << '\n';
			if (num[u] < low[v] && (curA[v] == cntA || !curA[v] || curB[v] == cntB || !curB[v])) ++res;
			low[u] = std::min(low[u], low[v]), curA[u] += curA[v], curB[u] += curB[v];
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}

}


void DFS(const maxn u) {
	cntA += isA[u], cntB += isB[u];

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[v]) continue;
		par[v] = u; DFS(v);
	}
}


void Process() {
	for (maxn u = 1; u <= n; u++) {
		if (par[u]) continue;
		cntA = cntB = 0;
		par[u] = u;  DFS(u);
		DFS_b(u);
	}
	std::cout << res;
}


int main() {
	//freopen("mgt.inp", "r", stdin);
	//freopen("mgt.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}