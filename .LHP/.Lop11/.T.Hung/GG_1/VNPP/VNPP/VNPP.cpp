#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>

#define maxN 102

typedef int maxn;
typedef std::string str;

maxn n, res, par[maxN], low[maxN], num[maxN], child[maxN], CNT;
bool g[maxN][maxN], cnt[maxN];


void Prepare() {
	CNT = 0; res = 0;
	std::fill(par, par + n + 1, 0);
	std::fill(low, low + n + 1, 0);
	std::fill(num, num + n + 1, 0);
	std::fill(child, child + n + 1, 0);
	for (maxn i = 1; i <= n; i++) std::fill(g[i], g[i] + n + 1, 0);
	std::fill(cnt, cnt + n + 1, 0);

	for (maxn u; std::cin >> u && u != 0;) {
		str s; std::getline(std::cin, s);
		std::stringstream ss(s);

		for (maxn v; ss >> v;) g[u][v] = g[v][u] = 1;
	}
}


void DFS(const maxn u) {
	num[u] = low[u] = ++CNT;

	for (maxn v = 1; v <= n; v++) {
		if (!g[u][v]) continue;
		if (!par[v]) {
			++child[u], par[v] = u;
			DFS(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}
}


void Process() {
	for (maxn i = 1; i <= n; i++)
		if (!par[i]) {
			par[i] = i; 
			DFS(i);
		}

	
	for (maxn v = 1; v <= n; v++) {
		maxn u = par[v];
		if (u == v) cnt[u] = child[u] > 1;
		else if (par[u] != u && low[v] >= num[u]) cnt[u] = 1;
	}
	for (maxn i = 1; i <= n; i++) res += cnt[i];
	std::cout << res << '\n';
}


int main() {
	//freopen("vnpp.inp", "r", stdin);
	//freopen("vnpp.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}