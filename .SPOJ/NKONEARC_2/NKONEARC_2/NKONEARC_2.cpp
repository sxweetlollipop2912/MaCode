// AC SPOJ 100/100
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 2001
#define maxM 30001

typedef int maxn, maxm;

maxn n, low[maxN], num[maxN], CNT, cmp[maxN], comp_cnt, rootc_cnt;
maxm m;
bool not_rootc[maxN], del[maxN], adc[maxN];
std::vector <maxn> ad[maxN], V;


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

	++comp_cnt;
	for (maxn v = V.back(); v != u; v = V.back()) {
		cmp[v] = u, del[v] = 1; V.pop_back();
	}
	cmp[u] = u, del[u] = 1; V.pop_back();
}


bool Process() {
	for (maxn i = 0; i < n; i++) if (!num[i]) DFS(i);

	rootc_cnt = comp_cnt;
	for (maxn u = 0; u < n; u++) for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (cmp[u] == cmp[v]) continue;
		adc[cmp[u]] = 1; rootc_cnt -= !not_rootc[cmp[v]], not_rootc[cmp[v]] = 1;
	}
	if (rootc_cnt != 1) return 0;

	maxn st = -1, en = -1;
	for (maxn i = 0; i < n; i++) {
		if (cmp[i] != i) continue;
		if (!not_rootc[i]) st = i;
		if (adc[i]) continue;
		if (en != -1) return 0; en = i;
	}

	std::cout << "YES\n" << en + 1 << ' ' << st + 1;
	
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "NO";
}