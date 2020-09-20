#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 100003
#define root 0

typedef long maxn;

maxn n, N, st[maxN], en[maxN], cnt[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n;
	
	for (maxn i = 1; i < n; i++) {
		maxn u, v; std::cin >> u >> v, --u, --v;
		ad[u].push_back(v); ad[v].push_back(u);
	}
}


void DFS(const maxn u) {
	en[u] = st[u];
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (st[v]) continue;
		st[v] = en[u] + 1;
		DFS(v);
		en[u] = en[v];
	}
	N = std::max(N, en[u]);
}


void Update(maxn i, maxn val) {
	while (i <= N) cnt[i] += val, i += (i & (-i));
}

maxn Sum(maxn i) {
	maxn re = 0;
	while (i) re += cnt[i], i -= (i & (-i));
	return re;
}


void Process() {
	st[root] = 1; DFS(root);

	for (maxn i = 0, x; i < n; i++) {
		std::cin >> x, --x;
		std::cout << Sum(st[x]) << '\n';
		Update(st[x], 1); Update(en[x] + 1, -1);
	}
}


int main() {
	//freopen("counting.inp", "r", stdin);
	//freopen("counting.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}