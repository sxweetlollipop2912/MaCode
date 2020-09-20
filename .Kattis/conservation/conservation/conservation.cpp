#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 100001
#define maxM 1000001

typedef long maxn, maxm;

maxn n, res0, res1, deg[maxN];
maxm m;
bool lab[maxN], last, done[maxN];
std::vector <maxn> ad[maxN], q[2];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < n; i++) {
		int x; std::cin >> x;
		lab[i] = x - 1;
		ad[i].clear();
	}

	for (maxm i = 0; i < m; i++) {
		maxn u, v; 
		std::cin >> u >> v, --u, --v;
		ad[u].push_back(v);
	}
}


void Add(const maxn u) {
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (done[v] || (--deg[v])) continue;
		q[lab[v]].push_back(v); done[v] = 1;
	}
}


void Init() {
	q[0].clear(); q[1].clear();
	for (maxn i = 0; i < n; i++) deg[i] = done[i] = 0;
	for (maxn u = 0; u < n; u++) for (maxm i = 0; i < ad[u].size(); i++) ++deg[ad[u][i]];
	for (maxn i = 0; i < n; i++) {
		if (deg[i]) continue;
		q[lab[i]].push_back(i); done[i] = 1;
	}
}


void Process() {
	Init();
	last = 0, res0 = q[last].empty() ? maxN : -1;
	while (!q[last].empty()) {
		++res0;
		while (!q[last].empty()) {
			maxn cur = q[last].back(); q[last].pop_back();
			Add(cur);
		}
		last = !last;
	}

	Init();
	last = 1, res1 = q[last].empty() ? maxN : -1;
	while (!q[last].empty()) {
		++res1;
		while (!q[last].empty()) {
			maxn cur = q[last].back(); q[last].pop_back();
			Add(cur);
		}
		last = !last;
	}

	std::cout << std::min(res0, res1) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long t; std::cin >> t;

	while (t--) {
		Prepare();
		Process();
	}
}