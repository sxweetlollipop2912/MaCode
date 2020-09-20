// AC SPOJ
// Sparse table, nlogn preprocess, O(1) each query
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define maxN 1002
#define maxT 2003
#define maxL 12

typedef int maxn;

maxn n, par[maxN], table[maxT][maxL], d[maxN], pos[maxN], root;
std::vector <maxn> ad[maxN], tour;


void Init() {
	for (maxn i = 0; i <= n; i++) ad[i].clear();
	std::fill(par, par + n + 1, 0);
	std::fill(d, d + maxN, maxN);
	tour.clear();
}

void Prepare() {
	std::cin >> n;

	for (maxn u = 1; u <= n; u++) {
		maxn c; std::cin >> c;
		for (maxn i = 0; i < c; i++) {
			maxn v; std::cin >> v;
			par[v] = u;
			ad[u].push_back(v);
		}
	}
	for (maxn u = 1; u <= n; u++) if (!par[u]) root = u;
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


void Build_Table() {
	d[root] = 0; DFS(root);

	for (maxn i = 0; i < tour.size(); i++) table[i][0] = tour[i];
	for (maxn lg = 1; (1 << lg) <= tour.size(); lg++) {
		for (maxn i = 0; i <= tour.size() - (1 << lg); i++) {
			table[i][lg] = d[table[i][lg - 1]] < d[table[i + (1 << (lg - 1))][lg - 1]] ? table[i][lg - 1] : table[i + (1 << (lg - 1))][lg - 1];
		}
	}
}


maxn Get_from_Table(maxn x, maxn y) {
	if (x > y) std::swap(x, y);
	maxn lg = log2(y - x + 1);
	return d[table[x][lg]] < d[table[y - (1 << lg) + 1][lg]] ? table[x][lg] : table[y - (1 << lg) + 1][lg];
}


void Process() {
	Build_Table();

	int q; std::cin >> q;
	while (q--) {
		maxn x, y;
		std::cin >> x >> y;
		std::cout << Get_from_Table(pos[x], pos[y]) << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q; std::cin >> q;
	for (int cntq = 1; cntq <= q; cntq++) {
		std::cout << "Case " << cntq << ":\n";
		Init();
		Prepare();
		Process();
	}
}