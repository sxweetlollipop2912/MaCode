#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 10002
#define maxM 1000001
#define v1 first
#define v2 second

typedef long maxn, maxm;
typedef std::pair <maxn, maxn> edge_t;

maxn n, cnt_v[maxN], gr_v[maxN], cnt_e[maxN], par[maxN], low[maxN], num[maxN], res_v, res_e, CNT;
maxm m;
edge_t edge[maxM];
std::vector <maxm> ad[maxN];
bool isBridge[maxM], done_e[maxM], done_v[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		std::cin >> edge[i].v1 >> edge[i].v2;
		ad[edge[i].v1].push_back(i);
		ad[edge[i].v2].push_back(i);
	}
}


void DFS_bridge(const maxn u) {
	low[u] = num[u] = ++CNT;

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = edge[ad[u][i]].v1 != u ? edge[ad[u][i]].v1 : edge[ad[u][i]].v2;
		if (!par[v]) {
			par[v] = u;
			DFS_bridge(v);
			low[u] = std::min(low[u], low[v]);
			
			isBridge[ad[u][i]] = low[v] > num[u];
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}
}


void DFS_cnt(const maxn u, const maxn gr) {
	++cnt_v[gr];
	done_v[u] = 1, gr_v[u] = gr;

	for (maxm i = 0; i < ad[u].size(); i++) {
		if (isBridge[ad[u][i]] || done_e[ad[u][i]]) continue;
		++cnt_e[gr];
		done_e[ad[u][i]] = 1;

		maxn v = edge[ad[u][i]].v1 != u ? edge[ad[u][i]].v1 : edge[ad[u][i]].v2;
		if (!done_v[v]) DFS_cnt(v, gr);
	}
}


void Process() {
	for (maxn u = 1; u <= n; u++) {
		if (par[u]) continue;
		par[u] = u;
		DFS_bridge(u);
	}
	for (maxn u = 1; u <= n; u++) {
		if (done_v[u]) continue;
		DFS_cnt(u, u);
		if (cnt_v[u] > cnt_v[res_v]) res_v = u;
		if (cnt_e[u] > cnt_e[res_e]) res_e = u;
	}

	std::cout << cnt_e[res_e] << '\n';
	for (maxn i = 1; i <= n; i++) 
		if (gr_v[i] == res_e) std::cout << i << ' ';

	std::cout << '\n' << cnt_v[res_v] << '\n';
	for (maxn i = 1; i <= n; i++) 
		if (gr_v[i] == res_v) std::cout << i << ' ';
	
}


int main() {
	//freopen("city.inp", "r", stdin);
	//freopen("city.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}