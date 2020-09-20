#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 10001
#define maxM 10001

typedef int maxn, maxm;

maxn n, T, cnt[maxN], group[maxN], CNT;
maxm m, res;
std::vector <maxn> ad[maxN], scc[maxN];
bool del[maxN];


void Prepare() {
	std::cin >> n >> m >> T;
	--T;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(v);
	}
}


void SCC(maxn u, std::vector <maxn> &comp) {
	cnt[u] = ++CNT;
	group[u] = cnt[u];
	comp.push_back(u);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (del[v]) continue;
		if (cnt[v]) group[u] = std::min(group[u], cnt[v]);
		else {
			SCC(v, comp);
			group[u] = std::min(group[u], group[v]);
		}
	}

	if (group[u] != cnt[u]) return;

	maxn v;
	do {
		v = comp.back();
		scc[group[u]].push_back(v);
		del[v] = 1;
		comp.pop_back();
	} while (v != u);
}


void Process_SCC() {
	CNT = 0;
	std::vector <maxn> comp;
	for (maxn i = 0; i < n; i++)
		if (!cnt[i]) SCC(i, comp);
}


bool Connected(const maxn gr) {
	if (gr == group[T]) return 1;

	for (maxn i = 0; i < scc[gr].size(); i++) {
		maxn u = scc[gr][i];
		for (maxn j = 0; j < ad[u].size(); j++) {
			maxn v = ad[u][j];
			if (group[v] != gr) return 1;
		}
	}
	return scc[gr].empty();
}


void Process() {
	for (maxn i = 1; i <= CNT; i++) res += !Connected(i);
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process_SCC();
	Process();
}