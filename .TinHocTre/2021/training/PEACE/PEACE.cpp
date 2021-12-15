// AC
// LCA từng cặp, lấy đỉnh sâu nhất
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define maxN 100002
#define maxT 200003
#define maxL 19

typedef long maxn;

const maxn root = 1;

maxn n, Q, par[maxN], table[maxT][maxL], d[maxN], pos[maxN];
std::vector <maxn> ad[maxN], tour;


void Init() {
	for (maxn i = 0; i <= n; i++) ad[i].clear();
	std::fill(par, par + n + 1, 0);
	std::fill(d, d + maxN, maxN);
	tour.clear();
}


void Prepare() {
	std::cin >> n >> Q;

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


void DFS(const maxn u) {
	pos[u] = tour.size();
	tour.push_back(u);

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (par[v]) continue;
		d[v] = d[u] + 1;

        par[v] = u;
		DFS(v); tour.push_back(u);
	}
}


void Build() {
	d[root] = 0; par[root] = root;
    DFS(root);

	for (maxn i = 0; i < tour.size(); i++) table[i][0] = tour[i];
	for (maxn lg = 1; (1 << lg) <= tour.size(); lg++) {
		for (maxn i = 0; i <= tour.size() - (1 << lg); i++) {
			table[i][lg] = d[table[i][lg - 1]] < d[table[i + (1 << (lg - 1))][lg - 1]] ? table[i][lg - 1] : table[i + (1 << (lg - 1))][lg - 1];
		}
	}
}


maxn LCA(maxn x, maxn y) {
    x = pos[x], y = pos[y];

	if (x > y) std::swap(x, y);
	maxn lg = log2(y - x + 1);
	return d[table[x][lg]] < d[table[y - (1 << lg) + 1][lg]] ? table[x][lg] : table[y - (1 << lg) + 1][lg];
}


void Process() {
	Build();

	while (Q--) {
		maxn x, y, z;
		std::cin >> x >> y >> z;

        maxn a = LCA(x, y), b = LCA(x, z), c = LCA(y, z);

        if (d[a] > d[b] && d[a] > d[c]) std::cout << a << '\n';
        else if (d[b] > d[c]) std::cout << b << '\n';
        else std::cout << c << '\n';
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

    Init();
	Prepare();
    Process();
}