#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 102
#define oppo(x) ((x) + 1 - 2 * ((x) & 1))
#define x first
#define y second
#define null -1

typedef long maxn, maxm;
typedef std::pair <maxn, maxn> e_t;

maxn n, st;
maxm m, pos[maxN], odd;
std::vector <e_t> edge;
std::vector <maxm> ad[maxN];
std::vector <maxn> v, res;
bool cnt[maxN];


void add_edge(const maxn u, const maxn v) {
	edge.push_back(e_t(u, v));
	ad[u].push_back(edge.size() - 1);

	edge.push_back(e_t(v, u));
	ad[v].push_back(edge.size() - 1);
}


bool Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v, --u, --v;
		add_edge(u, v);
		cnt[u] = !cnt[u], cnt[v] = !cnt[v];
	}

	for (maxn i = 0; i < n; i++) {
		if (!cnt[i]) continue;
		odd++, st = n;
		add_edge(i, n);
	}

	return odd == 0 || odd == 2;
}


bool nextPos(const maxn u) {
	while (pos[u] < ad[u].size() && edge[ad[u][pos[u]]].x == null) ++pos[u];
	return pos[u] != ad[u].size();
}


void del(const maxm m) {
	edge[m].x = edge[oppo(m)].x = null;
}


void Process() {
	v.push_back(st);

	while (!v.empty()) {
		maxn u = v.back();

		if (nextPos(u)) {
			v.push_back(edge[ad[u][pos[u]]].y);
			del(ad[u][pos[u]]);
		}
		else {
			v.pop_back();
			res.push_back(u);
		}
	}
	for (maxn i = 0; i < res.size() - 1; i++) if (res[i] != n) std::cout << res[i] + 1 << ' ';
	if (res.back() != res[0] && res.back() != n) std::cout << res.back() + 1;
}


int main() {
	//freopen("eulerhalf.inp", "r", stdin);
	//freopen("eulerhalf.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	if (!Prepare()) std::cout << -1;
	else Process();
}