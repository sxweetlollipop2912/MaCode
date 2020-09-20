// AC SPOJ
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define maxN 100001
#define maxA 1000001
#define maxL 18
#define L 17
#define vert first
#define dist second

typedef long maxn, maxa;
typedef std::pair <maxn, maxa> ad_t;

maxn n, d[maxN], par[maxN][maxL], mn[maxN][maxL], mx[maxN][maxL];
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 1; i < n; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d, --u, --v;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
	}
}


void DFS(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		if (d[v]) continue;
		d[v] = d[u] + 1, par[v][0] = u, mn[v][0] = mx[v][0] = ad[u][i].dist;
		DFS(v);
	}
}


void Build() {
	for (maxn l = 1; (1 << l) <= n; l++) for (maxn i = 0; i < n; i++) {
		par[i][l] = par[par[i][l - 1]][l - 1];
		mn[i][l] = std::min(mn[i][l - 1], mn[par[i][l - 1]][l - 1]);
		mx[i][l] = std::max(mx[i][l - 1], mx[par[i][l - 1]][l - 1]);
	}
}


void Min_Max(maxn x, maxn y) {
	maxa rmn = maxA, rmx = 0;
	if (d[x] < d[y]) std::swap(x, y);

	while (d[x] != d[y]) {
		maxn l = log2(d[x] - d[y]);
		rmn = std::min(rmn, mn[x][l]), rmx = std::max(rmx, mx[x][l]);
		x = par[x][l];
	}

	for (maxn l = L; l >= 0; l--) {
		if (par[x][l] == par[y][l]) continue;
		rmn = std::min(rmn, mn[x][l]), rmx = std::max(rmx, mx[x][l]);
		rmn = std::min(rmn, mn[y][l]), rmx = std::max(rmx, mx[y][l]);
		x = par[x][l], y = par[y][l];
	}
	if (x != y) rmn = std::min(rmn, std::min(mn[x][0], mn[y][0])), rmx = std::max(rmx, std::max(mx[x][0], mx[y][0]));

	std::cout << rmn << ' ' << rmx << '\n';
}


void Process() {
	d[0] = 1, par[0][0] = 0; DFS(0);
	Build();

	long q; std::cin >> q;
	while (q--) {
		maxn u, v; 
		std::cin >> u >> v, --u, --v;
		Min_Max(u, v);
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}