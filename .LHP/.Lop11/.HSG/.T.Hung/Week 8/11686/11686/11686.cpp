// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

#define maxN 1000001

typedef long maxn, maxm;

maxn n;
maxm m;
bool done[maxN], inS[maxN];
std::vector <maxn> ad[maxN], res;


void Prepare() {
	for (maxn i = 0; i < n; i++) {
		ad[i].clear();
		done[i] = inS[i] = 0;
	}

	for (maxn i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		ad[v].push_back(u);
	}
}


bool DFS(const maxn u) {
	done[u] = inS[u] = 1;
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (inS[v] || (!done[v] && !DFS(v))) return 0;
	}
	res.push_back(u); 
	inS[u] = 0; return 1;
}


bool Process() {
	res.clear();
	for (maxn i = 0; i < n; i++) if (!done[i] && !DFS(i)) return 0;
	for (maxn i = 0; i < n; i++) std::cout << res[i] + 1 << '\n';
	return 1;
}


int main() {
	//freopen("11686.inp", "r", stdin);
	//freopen("11686.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> m && n) {
		Prepare();
		if (!Process()) std::cout << "IMPOSSIBLE\n";
	}
}