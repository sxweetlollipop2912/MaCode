#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>

#define maxN 100002
#define maxT 200002
#define log 18
//#define maxM 500001
//#define maxQ 300001

typedef long maxn, maxm, maxq;

maxn n, pos[maxN], h[maxN], mn[maxT][log], tn, low[maxN], num[maxN], par[maxN], child[maxN], CNT;
maxm m;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
}


void DFS(const maxn u, const maxn step) {
	h[u] = step;
	low[u] = num[u] = ++CNT, child[u] = 0;
	pos[u] = tn, ++tn, mn[pos[u]][0] = u;

	//std::cout << u << ' ' << h[u] << ' ' << pos[u] << '\n';

	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];

		if (!par[v]) {
			par[v] = u, ++child[u];
			DFS(v, step + 1);
			mn[tn][0] = u, ++tn;

			low[u] = std::min(low[u], low[v]);
		}
		else if (par[u] != v) low[u] = std::min(low[u], num[v]);
	}
}


void Sparse_table() {
	for (int lg = 1; lg < log; lg++) for (maxn i = 0; i <= tn - (1 << lg); i++)
		mn[i][lg] = h[mn[i][lg - 1]] < h[mn[i + (1 << (lg - 1))][lg - 1]] ? mn[i][lg - 1] : mn[i + (1 << (lg - 1))][lg - 1];// std::cout << i << ' ' << lg << ' ' << mn[i][lg] << '\n';
}


maxn Anc(maxn x, maxn y) {
	if (pos[x] > pos[y]) std::swap(x, y);
	int lg = log2(pos[y] - pos[x] + 1);
	return h[mn[pos[x]][lg]] < h[mn[pos[y] - (1 << lg) + 1][lg]] ? mn[pos[x]][lg] : mn[pos[y] - (1 << lg) + 1][lg];
}


bool inWay(const maxn x, const maxn y, const maxn i) {
	return (Anc(x, i) == Anc(x, y) && Anc(i, y) == i) || (Anc(y, i) == Anc(x, y) && Anc(i, x) == i);
}

bool isBridge(const maxn u, const maxn v) {
	return par[v] == u && low[v] > num[u];
}


void Process() {
	tn = 0;
	par[1] = 1; DFS(1, 0);
	Sparse_table();

	maxq q; std::cin >> q;

	while (q--) {
		int opt; std::cin >> opt;

		if (opt == 1) {
			maxn a, b, x, y;
			std::cin >> a >> b >> x >> y;
			//std::cout << Anc(a, b) << '\n';
			//std::cout << isBridge(x, y) << '\n';
			if (isBridge(x, y) && inWay(a, b, x) && inWay(a, b, y)) std::cout << "no\n";
			else std::cout << "yes\n";
		}
		if (opt == 2) {
			maxn a, b, x, y;
			std::cin >> a >> b >> x;
			//std::cout << Anc(a, b) << '\n';
			std::cout << isArti[x] << '\n';
			if (isArti[x] && inWay(a, b, x)) std::cout << "no\n";
			else std::cout << "yes\n";
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}