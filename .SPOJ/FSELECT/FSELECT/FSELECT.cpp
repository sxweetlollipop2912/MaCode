// AC SPOJ
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>

#define maxN 200002
#define maxT 400002
#define maxS 19

typedef long maxn;

maxn n, F, par[maxN], table[maxT][maxS], d[maxN], pos[maxN];
std::vector <maxn> ad[maxN], fac[maxN], tour;


void Prepare() {
	std::cin >> n >> F;
	for (maxn i = 1; i <= n; i++) {
		maxn f;
		std::cin >> f >> par[i];
		fac[--f].push_back(i);
		ad[par[i]].push_back(i);
	}
	std::fill(d, d + n + 1, maxN);
}


void DFS(const maxn u) {
	pos[u] = tour.size();
	tour.push_back(u);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (d[v] != maxN) continue;
		d[v] = d[u] + 1;
		DFS(v); tour.push_back(u);
	}
}


void BuildAnc() {
	for (maxn u = 1; u <= n; u++) 
		if (!par[u]) {
			d[u] = 0; DFS(u); 
		}

	for (maxn i = 0; i < tour.size(); i++) table[i][0] = tour[i];

	for (maxn lg = 1; (1 << lg) <= tour.size(); lg++) 
		for (maxn i = 0; i <= tour.size() - (1 << lg); i++) 
			table[i][lg] = d[table[i][lg - 1]] < d[table[i + (1 << (lg - 1))][lg - 1]] ? table[i][lg - 1] : table[i + (1 << (lg - 1))][lg - 1];
}


maxn Anc(maxn x, maxn y) {
	if (x > y) std::swap(x, y);
	maxn lg = log2(y - x + 1);
	return d[table[x][lg]] < d[table[y - (1 << lg) + 1][lg]] ? table[x][lg] : table[y - (1 << lg) + 1][lg];
}


void Process() {
	BuildAnc();

	for (maxn f = 0; f < F; f++) {
		maxn lowest = fac[f][0], re = 0;
		for (maxn i = 1; i < fac[f].size(); i++) if (d[fac[f][i]] > d[lowest]) lowest = fac[f][i];
		for (maxn i = 0; i < fac[f].size(); i++) re = std::max(re, d[fac[f][i]] + d[lowest] - 2 * d[Anc(pos[fac[f][i]], pos[lowest])]);
		std::cout << re << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}