#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 300001
#define maxA 10000000000000001
#define LIM 1000000000000001
#define cost(u) (d[u] + mn[u])

typedef long maxn, maxm;
typedef long long maxa;

maxn n, st, par[maxN], resid;
maxm m;
maxa d[maxN], mn[maxN], fix[maxN];
std::vector <maxn> U, V, C, res;


void Prepare() {
	std::cin >> n >> m >> st, --st;
	for (maxn i = 0; i < n; i++) std::cin >> fix[i];

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa c;
		std::cin >> u >> v >> c, --u, --v;
		U.push_back(u); V.push_back(v); C.push_back(c);
	}
}


void Process() {
	std::fill(d, d + n, maxA); std::fill(mn, mn + n, maxA);
	d[st] = 0, mn[st] = fix[st], par[st] = st;
	for (maxn i = 1; i < n; i++) for (maxm j = 0; j < m; j++) {
		maxn u = U[j], v = V[j]; maxa c = C[j];
		if (cost(v) > d[u] + c + std::min(mn[u], fix[v])) mn[v] = std::min(mn[u], fix[v]), d[v] = d[u] + c, par[v] = u;
	}

	resid = st;
	for (maxn i = 0; i < n; i++) if (cost(i) < LIM && cost(i) > cost(resid)) resid = i;
	std::cout << cost(resid) << ' ' << resid + 1 << '\n';

	for (; resid != st; resid = par[resid]) for (maxm i = 0; i < m; i++) {
		if (U[i] != par[resid] || V[i] != resid) continue;
		res.push_back(i + 1); break;
	}
	std::cout << res.size() << '\n';
	for (maxm i = (maxm)res.size() - 1; i >= 0; i--) std::cout << res[i] << ' ';
}


int main() {
	freopen("railway.inp", "r", stdin);
	freopen("railway.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (n * m <= 100000000) Process();
}