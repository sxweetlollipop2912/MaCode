#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>

#define maxN 100002
#define maxA 100000000001
#define maxS 18
#define vert first
#define cost second

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t, ad_t;
typedef std::pair <maxn, maxn> e_t;

maxn n, par[maxN][maxS], d[maxN];
maxm m;
maxa mn[maxN][maxS], res;
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa a;
		std::cin >> u >> v >> a;
		ad[u].push_back(ad_t(v, a));
		ad[v].push_back(ad_t(u, a));
	}

	for (maxn i = 0; i <= n; i++) std::fill(mn[i], mn[i] + maxS, maxA);
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost < p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u) {
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert; 
		maxa a = ad[u][i].cost;
		if (done[v] || mn[v][0] >= a) continue;
		mn[v][0] = a, par[v][0] = u;
		pq.push(pq_t(v, mn[v][0]));
	}
}


void Prim() {
	for (maxn i = 0; i <= n; i++) mn[i][0] = 0;
	mn[1][0] = maxA, par[1][0] = 0;
	pq.push(pq_t(1, mn[1][0]));

	for (maxn i = 1; i < n; i++) {
		maxn cur = pq.top().vert; pq.pop();
		//std::cout << cur << ' ' << par[cur] << '\n';
		done[cur] = 1;
		Fill(cur);
		while (pq.top().cost != mn[pq.top().vert][0]) pq.pop();
	}
}


void DFS(const maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		if (par[v][0] != u || d[v] != maxN) continue;
		d[v] = d[u] + 1;
		DFS(v);
	}
}


void BuildAnc() {
	for (maxn p = 1; (1 << p) <= n; p++) for (maxn i = 1; i <= n; i++) {
		par[i][p] = par[par[i][p - 1]][p - 1], mn[i][p] = std::min(mn[i][p - 1], mn[par[i][p - 1]][p - 1]);
		//std::cout << i << ' ' << par[i][p] << ' ' << (1 << p) << ' ' << mn[i][p - 1] << ' ' << mn[par[i][p - 1]][p - 1] << ' ' << mn[i][p] << '\n';
	}
}


maxa Anc(maxn x, maxn y) {
	maxa re = maxA;

	if (d[x] < d[y]) std::swap(x, y);
	while (d[x] != d[y])
		re = std::min(re, mn[x][(maxn)log2(d[x] - d[y])]), x = par[x][(maxn)log2(d[x] - d[y])];

	for (maxn p = maxS - 2; p >= 0; p--)
		if (par[x][p] != par[y][p]) 
			re = std::min(re, std::min(mn[x][p], mn[y][p])), x = par[x][p], y = par[y][p];

	//return x == y ? x : par[x][0];
	return x == y ? re : std::min(re, mn[x][0]);
}


void Process() {
	Prim();

	std::fill(d, d + n + 1, maxN); d[1] = 0;
	DFS(1);
	BuildAnc();

	for (maxn u = 1; u <= n; u++) for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert; maxa a = ad[u][i].cost;
		res += std::max((maxa)0, Anc(u, v) - a);
		//std::cout << u << ' ' << v << ' ' << a << ' ' << Anc(u, v) << '\n';
	}
	res /= 2;
	std::cout << res;
}


int main() {
	//freopen("upgranet.inp", "r", stdin);
	//freopen("upgranet.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}