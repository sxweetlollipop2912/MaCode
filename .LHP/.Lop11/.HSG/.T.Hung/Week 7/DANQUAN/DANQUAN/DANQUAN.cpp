#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001

typedef long maxn;

maxn n, nv, nt, f[maxN], fv[maxN], ft[maxN];
bool V[maxN], T[maxN], done[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> nv >> nt;

	for (maxn i = 0, x; i < nv; i++) std::cin >> x, --x, V[x] = 1;
	for (maxn i = 0, x; i < nt; i++) std::cin >> x, --x, T[x] = 1;

	for (maxn u = 0; u < n; u++) {
		maxn cnt; std::cin >> cnt;
		while (cnt--) {
			maxn v; std::cin >> v, --v;
			ad[u].push_back(v);
		}
	}
}


void DFS(const maxn u) {
	done[u] = 1;
	f[u] = maxN; fv[u] = V[u] ? 0 : maxN, ft[u] = T[u] ? 0 : maxN;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v]) continue;
		DFS(v);
		fv[u] = std::min(fv[u], fv[v] + 1), ft[u] = std::min(ft[u], ft[v] + 1), f[u] = std::min(f[u], f[v] + 1);
	}
	f[u] = std::min(f[u], fv[u] + ft[u]);
}


void Process() {
	DFS(0);
	if (f[0] != maxN) std::cout << f[0];
	else std::cout << "-1";
}


int main() {
	//freopen("danquan.inp", "r", stdin);
	//freopen("danquan.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}