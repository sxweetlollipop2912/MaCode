#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 200001
#define DN first
#define amount second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t;

maxn n;
std::vector <ad_t> ad[maxN];
ad_t no[maxN];
maxa has[maxN], res;


void Prepare() {
	std::cin >> n;
	for (maxn v = 0; v < n; v++) {
		maxn u; maxa a;
		std::cin >> u >> a;
		--u, no[v].DN = u, no[v].amount = a;
		ad[u].push_back(ad_t(v, a));
		has[v] = -1;
	}
}


void DFS(const maxn u) {
	has[u] = 0;
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].DN; maxa a = ad[u][i].amount;
		if (v == no[u].DN) continue;

		if (has[v] == -1) DFS(v);
		res += std::max((maxa)0, a - has[v]);
		has[u] += a;
	}
	
	if (no[no[u].DN].DN == u) {
		maxn v = no[u].DN;
		if (has[v] == -1) DFS(v);
		res += std::max((maxa)0, no[v].amount - has[v]);
		has[u] += no[v].amount;
	}
}


void Process() {
	for (maxn u = 0; u < n; u++) if (has[u] == -1) DFS(u);
	std::cout << res;
}


int main() {
	Prepare();
	Process();
}