// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 10001
#define maxM 100001

typedef long maxn, maxm;

maxn n, low[maxN], num[maxN], CNT, cmp[maxN], comp_cnt, root_cnt;
maxm m;
bool root[maxN], del[maxN];
std::vector <maxn> ad[maxN], V;


void Init() {
	std::fill(num, num + maxN, 0);
	CNT = comp_cnt = root_cnt = 0;
	std::fill(del, del + maxN, 0);
	for (maxn i = 0; i < n; i++) ad[i].clear();
	V.clear();
}


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v, --u, --v;
		ad[u].push_back(v);
	}
}


void DFS(const maxn u) {
	V.push_back(u);
	low[u] = num[u] = ++CNT;

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (del[v]) continue;
		if (num[v]) low[u] = std::min(low[u], num[v]);
		else {
			DFS(v);
			low[u] = std::min(low[u], low[v]);
		}
	}
	if (low[u] != num[u]) return;

	for (maxn v = V.back(); v != u; v = V.back()) {
		cmp[v] = comp_cnt, del[v] = 1; V.pop_back();
	}
	cmp[u] = comp_cnt, del[u] = 1; V.pop_back();
	++comp_cnt;
}


void Process() {
	for (maxn i = 0; i < n; i++) if (!num[i]) DFS(i);

	root_cnt = comp_cnt;
	std::fill(root, root + comp_cnt, 1);

	for (maxn u = 0; u < n; u++) for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (cmp[u] == cmp[v]) continue;
		root_cnt -= root[cmp[v]], root[cmp[v]] = 0;
	}

	std::cout << root_cnt << '\n';
}


int main() {
	freopen("11770.inp", "r", stdin);
	freopen("11770.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		std::cout << "Case " << cnt << ": ";
		Init();
		Prepare();
		Process();
	}
}