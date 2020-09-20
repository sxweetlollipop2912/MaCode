// AC SPOJ - MTREE
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning (disable:4996)

#define maxN 100001
#define MOD 1000000007
#define vert first
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t;

maxn n;
maxa res;
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i < n; i++) {
		maxn x, y; maxa a;
		std::cin >> x >> y >> a;
		--x, --y;
		ad[x].push_back(ad_t(y, a));
		ad[y].push_back(ad_t(x, a));
	}
}


maxa DFS(const maxn u) {
	done[u] = 1;
	maxa re = 0, sum = 0;

	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert; maxa c = ad[u][i].cost;
		if (done[v]) continue;
		maxa tmp = (c * DFS(v) + c) % MOD;
		re = (re + tmp) % MOD;
		res = (res + (tmp * sum) % MOD) % MOD, sum = (sum + tmp) % MOD;
	}

	res = (res + re) % MOD;
	return re;
}


void Process() {
	DFS(0);
	std::cout << res;
}


int main() {
	//freopen("tree.inp", "r", stdin);
	//freopen("tree.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}