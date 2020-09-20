#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 10001
#define maxM 100001
#define maxR 2000000001
#define A 0
#define B 1

typedef int maxn;
typedef long maxm, maxr;

maxn n, par[maxN];
bool c[maxN];
maxm m;
maxr c[2][maxN];
std::vector <maxn> ad[2][maxN];


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 1; i < n; i++) std::cin >> c[A][i];
	for (maxn i = 1; i < n; i++) std::cin >> c[B][i];

	for (maxm i = 0; i < m; i++) {
		maxn u, v; int op;
		std::cin >> u >> v >> op, --u, --v;
		ad[op - 1][u].push_back(v);
	}
}


void DFS(const maxn u, const int op) {
	if (op != B) 
		for (maxm i = 0; i < ad[A][u].size(); i++) {
			maxn v = ad[A][u][i];
			if (par[v] != -1) continue;
			par[v] = u, c[v] = A; DFS(v, op);
		}
	if (op != A)
		for (maxm i = 0; i < ad[B][u].size(); i++) {
			maxn v = ad[1][u][i];
			if (par[v] != -1) continue;
			par[v] = u, c[v] = B; DFS(v, op);
		}
}


void Process() {
	std::fill(par, par + n, -1);
	DFS(0, B);

	for (maxn i = 0; i < n; i++) ad[B][i].clear();
	for (maxn i = 0; i < n; i++) {
		if (par[i] == -1) continue;
		ad[B][par[i]].push_back(i);
		ad[B][i].push_back(par[i]);
	}
	std::fill(par, par + n, -1);
	DFS(0, 2);
}