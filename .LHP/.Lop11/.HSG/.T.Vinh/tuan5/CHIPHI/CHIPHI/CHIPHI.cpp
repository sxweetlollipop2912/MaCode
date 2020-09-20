#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 251
//#define maxM 10001
#define maxD (maxa)100000000000001
#define fill(a, val) for(maxn i = 0; i < n; i++) std::fill(a[i], a[i] + n, val)
#define Max(x, y, z) std::max(x, std::max(y, z))

typedef int maxn, maxm;
typedef long long maxa;

maxn n, id[maxN];
maxm m, q;
maxa c[maxN], dg[maxN][maxN], d[maxN][maxN];


bool cmp(const maxn x, const maxn y) {
	return c[x] < c[y];
}


void Prepare() {
	std::cin >> n >> m >> q;

	for (maxn i = 0; i < n; i++) std::cin >> c[i], id[i] = i;
	std::sort(id, id + n, cmp);

	fill(d, maxD);
	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa l;
		std::cin >> u >> v >> l, --u, --v;
		d[u][v] = d[v][u] = std::min(d[u][v], l);
	}
	for (maxn i = 0; i < n; i++) d[i][i] = 0;
}


void Process() {
	fill(dg, maxD);

	for (maxn kk = 0; kk < n; kk++) for (maxn ii = 0; ii < n; ii++) for (maxn jj = 0; jj < n; jj++) {
		maxn k = id[kk], i = id[ii], j = id[jj];
		if (d[i][j] < d[i][k] + d[k][j]) continue;
		d[i][j] = d[i][k] + d[k][j];
		dg[i][j] = std::min(dg[i][j], d[i][j] + Max(c[i], c[j], c[k]));
	}

	while (q--) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		std::cout << dg[u][v] << '\n';
	}
}


int main() {
	//freopen("chiphi.inp", "r", stdin);
	//freopen("chiphi.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}