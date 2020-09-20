#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 200001
#define rev 0
#define nrev 1
#define V first
#define dir second

typedef long maxn;
typedef std::pair <maxn, bool> ad_t;

maxn n, cost0, pf[maxN], res;
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 1; i < n; i++) {
		maxn u, v; std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(ad_t(v, nrev));
		ad[v].push_back(ad_t(u, rev));
	}
}


maxn DFS(const maxn u) {
	done[u] = 1; maxn re = 0;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].V;
		if (done[v]) continue;
		pf[v] = ad[u][i].dir == rev ? pf[u] - 1 : pf[u] + 1;
		re += (ad[u][i].dir == rev) + DFS(v);
	}
	return re;
}


void Process() {
	cost0 = DFS(0);
	res = cost0 + *std::min_element(pf, pf + n);

	std::cout << res << '\n';
	for (maxn i = 0; i < n; i++) if (pf[i] + cost0 == res) std::cout << i + 1 << ' ';
}


int main() {
	//freopen("treeland.inp", "r", stdin);
	//freopen("treeland.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}