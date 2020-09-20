// AC UVa
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 10001
#define rail first
#define val second

typedef int maxn;

maxn n, m, num[maxN], low[maxN], CNT, par[maxN], child[maxN], res[maxN];
std::vector <maxn> ad[maxN], list;
bool done[maxN];


bool cmp_res(const maxn x, const maxn y) {
	return res[x] > res[y] || (res[x] == res[y] && x < y);
}


void Init() {
	std::fill(par, par + n, -1);
	std::fill(res, res + n, 1);
	for (maxn i = 0; i < n; i++) ad[i].clear();
	list.clear();
	CNT = -1;
}


void Prepare() {
	maxn u, v;
	while (std::cin >> u >> v && u != -1) {
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void DFSArti(const maxn u, maxn low[], maxn num[], maxn child[], maxn par[], maxn &CNT) {
	low[u] = num[u] = ++CNT, child[u] = 0;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[v] == -1) {
			par[v] = u, ++child[u];
			DFSArti(v, low, num, child, par, CNT);
			low[u] = std::min(low[u], low[v]);
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}
}


void DFS(const maxn u, bool done[]) {
	done[u] = 1;
	for (maxn i = 0; i < ad[u].size(); i++) 
		if (!done[ad[u][i]]) DFS(ad[u][i], done);
}


maxn Pigeon_Value(const maxn a) {
	std::fill(done, done + n, 0); done[a] = 1;

	maxn re = 0;
	for (maxn i = 0; i < ad[a].size(); i++) {
		if (done[ad[a][i]]) continue;
		++re; DFS(ad[a][i], done);
	}
	return re;
}


void Process() {
	for (maxn i = 0; i < n; i++) if (par[i] == -1) DFSArti(i, low, num, child, par, CNT);

	for (maxn v = 1; v <= n; v++) {
		maxn u = par[v];
		if (u == v) res[v] = !(child[v] > 1);
		else if (par[u] != u && low[v] >= num[u]) res[u] = 0;
	}

	for (maxn a = 0; a < n; a++) {
		list.push_back(a);
		if (!res[a]) res[a] = Pigeon_Value(a);
	}

	std::sort(list.begin(), list.end(), cmp_res);
	for (maxn i = 0; i < m; i++) {
		std::cout << list[i] << ' ' << res[list[i]] << '\n';
	}
}


int main() {
	freopen("10765.inp", "r", stdin);
	freopen("10765.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> m && n) {
		Init();
		Prepare();
		Process();
		std::cout << '\n';
	}
}