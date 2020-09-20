// AC SPOJ
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>

#define maxN 100001
#define maxM 100001
#define maxA 1000001
#define maxL 19
#define L 17
#define vert first
#define dist second
#define U second.first
#define V second.second
#define D first

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;
typedef std::pair <maxn, maxn> p_t;
typedef std::pair <maxa, p_t> e_t;

maxn n, par[maxN][maxL], d[maxN];
maxa mn[maxN][maxL], res;
maxm m;
bool done[maxN];
std::vector <ad_t> ad[maxN];
std::vector <e_t> e;


void Prepare() {
	std::cin >> n >> m;
	
	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d, --u, --v;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
		e.push_back(e_t(d, p_t(u, v)));
	}
}


class cmp {
public:
	bool operator()(const pq_t p1, const pq_t p2) {
		return p1.dist < p2.dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Prim() {
	mn[0][0] = 0, par[0][0] = 0; pq.push(pq_t(0, mn[0][0]));

	for (maxn i = 0; i < n; i++) {
		while (done[pq.top().vert]) pq.pop();
		maxn u = pq.top().vert; done[u] = 1; pq.pop();

		for (maxm j = 0; j < ad[u].size(); j++) {
			maxn v = ad[u][j].vert; maxa d = ad[u][j].dist;
			if (done[v] || mn[v][0] >= d) continue;
			mn[v][0] = d, par[v][0] = u;
			pq.push(pq_t(v, mn[v][0]));
		}
	}
}


void DFS(const maxn u) {
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		if (d[v]) continue;
		d[v] = d[u] + 1; DFS(v);
	}
}


void Build() {
	for (maxn l = 1; (1 << l) <= n; l++) for (maxn i = 0; i < n; i++) {
		par[i][l] = par[par[i][l - 1]][l - 1];
		mn[i][l] = std::min(mn[i][l - 1], mn[par[i][l - 1]][l - 1]);
	}
}


maxa Min(maxn x, maxn y) {
	maxa re = maxA;
	if (d[x] < d[y]) std::swap(x, y);

	while (d[x] != d[y]) {
		maxn l = log2(d[x] - d[y]);
		re = std::min(re, mn[x][l]), x = par[x][l];
	}

	for (maxn l = L; l >= 0; l--) {
		if (par[x][l] == par[y][l]) continue;
		re = std::min(re, std::min(mn[x][l], mn[y][l]));
		x = par[x][l], y = par[y][l];
	}

	return x == y ? re : std::min(re, std::min(mn[x][0], mn[y][0]));
}


void Process() {
	Prim();
	for (maxn i = 0; i < n; i++) ad[i].clear();
	for (maxn v = 0; v < n; v++) {
		ad[par[v][0]].push_back(ad_t(v, mn[v][0]));
		ad[v].push_back(ad_t(par[v][0], mn[v][0]));
	}
	d[0] = 1; DFS(0);

	Build();

	for (maxm i = 0; i < m; i++) 
		res += std::max((maxa)0, Min(e[i].U, e[i].V) - e[i].D);

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}