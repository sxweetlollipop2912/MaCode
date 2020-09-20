#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 201
#define INF 999999999
#define fill(a, val) for(maxn i = 0; i < n; i++) std::fill(a[i], a[i] + n, val)

typedef int maxn, maxm;
typedef long maxa;

maxn n, A, B, C;
maxm m;
maxa d[maxN][maxN], g[maxN][maxN];


void Prepare() {
	std::cin >> n >> m >> A >> B >> C, --A, --B, --C;

	fill(d, INF); fill(g, INF);
	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa duv, guv;
		std::cin >> u >> v >> duv >> guv, --u, --v;
		d[u][v] = std::min(d[u][v], duv);
		g[u][v] = std::min(g[u][v], guv);
	}
}


void Process() {
	for (maxn k = 0; k < n; k++) for (maxn u = 0; u < n; u++) for (maxn v = 0; v < n; v++) {
		d[u][v] = std::min(d[u][v], d[u][k] + d[k][v]);
		g[u][v] = std::min(g[u][v], std::max(g[u][k], g[k][v]));
	}
	std::cout << d[A][B] + d[B][C] << '\n' << std::max(g[A][B], g[B][C]);
}


int main() {
	//freopen("tiepte.inp", "r", stdin);
	//freopen("tiepte.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}