#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 200001

typedef long maxn;
typedef long long maxr;

const maxr MOD = 1e9 + 7;

maxn n, m, low[maxN], num[maxN], par[maxN], cnt[maxN], deg[maxN], CNT, res_cnt;
std::vector <maxn> ad[maxN];
std::vector <maxn> st;
maxr res;


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--, v--;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	std::fill(par, par + n, -1);
}


void Tarjan(const maxn u) {
	low[u] = num[u] = CNT++;
	st.push_back(u);

	for (maxn& v : ad[u]) {
		if (par[v] == -1) {
			par[v] = u;
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if (par[u] != v)
			low[u] = std::min(low[u], num[v]);
	}

	if (low[u] != num[u]) return;

	for (maxn v = -1; v != u;) {
		v = st.back(); st.pop_back();
		++cnt[num[u]];
		num[v] = num[u];
	}
}


void Process() {
	par[0] = 0;
	Tarjan(0);

	for (maxn u = 0; u < n; u++) for (maxn& v : ad[u])
		if (u < v && num[u] != num[v])
			++deg[num[u]], ++deg[num[v]];
	
	res = 1, res_cnt = 0;
	for (maxn i = 0; i < n; i++)
		if (deg[i] == 1) res = (res * cnt[i]) % MOD, ++res_cnt;

	if (!res_cnt)
		std::cout << "1 " << cnt[0];
	else std::cout << res_cnt << ' ' << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}