#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
#define maxA 10000000001
#define X first
#define Y second

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxn> e_t;

maxn n;
maxm m;
maxa g[maxN][maxN], d[maxN];
std::vector <e_t> e;


void Prepare() {
	maxn F, UF;
	std::cin >> n >> F >> UF;

	for (maxn i = 0; i < n; i++) std::fill(g[i], g[i] + n, maxA);

	for (maxm i = 0; i < F; i++) {
		maxn u, v; maxa a;
		std::cin >> u >> v >> a, --u. --v;
		if (u < v) std::swap(u, v);
		e.push_back(e_t(u, v));
		g[u][v] = std::min(g[u][v], a);
	}

	for (maxm i = 0; i < UF; i++) {
		maxn u, v;
		std::cin >> u >> v >> a, --u. --v;
		if (u > v) std::swap(u, v);
		e.push_back(e_t(u, v));
		g[u][v] = std::min(g[u][v], -a);
	}
}


bool Process() {
	std::fill(d, d + n, maxA); d[0] = 0;
	for (maxn in = 1; in < n; in++) for (maxn i = 0; i < e.size(); i++) {
		maxn u = e[i].X, v = e[i].Y;
		if (d[u] != maxA) d[v] = std::min(d[v], d[u] + g[u][v]);
	}

	for (maxn i = 0; i < e.size(); i++) {
		maxn u = e[i].X, v = e[i].Y;
		if (d[u] != maxA && d[v] > d[u] + g[u][v]) return 0;
	}

	if (d[n - 1] == maxA) std::cout << "-2"; else std::cout << d[n - 1];
	return 1;
}


int main() {
	//freopen("room.inp", "r", stdin);
	//freopen("room.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}