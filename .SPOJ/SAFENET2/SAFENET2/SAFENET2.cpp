// AC SPOJ
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 30002
//#define maxM 100001

typedef long maxn, maxm;

maxn n, res, low[maxN], num[maxN], comp[maxN], CNT, compCNT;
maxm m;
std::vector <maxn> ad[maxN], stack;


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


void DFS(const maxn u) {
	low[u] = num[u] = ++CNT;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (num[v]) low[u] = std::min(low[u], num[v]);
		else {
			stack.push_back(u);
			DFS(v);
			low[u] = std::min(low[u], low[v]);
			
			if (low[v] < num[u]) continue;
			maxn cnt = 0;
			++compCNT;
			do {
				v = stack.back();
				stack.pop_back();
				if (comp[v] != compCNT) comp[v] = compCNT, ++cnt;
			} while (v != u);
			res = std::max(res, cnt);
		}
	}

	stack.push_back(u);
}


void Process() {
	res = 1;
	for (maxn u = 0; u < n; u++)
		if (!num[u]) DFS(u);
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}