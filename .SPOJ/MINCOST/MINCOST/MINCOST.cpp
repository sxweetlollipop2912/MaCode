// AC SPOJ
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define maxN 101
#define maxA 1000000001
#define maxD 99999999999
#define never 0
#define inq 1
#define outq 2

typedef int maxn, maxm;
typedef long long maxa;

maxn n, S, T, par[maxN];
maxm m;
maxa capacity[maxN][maxN], cost[maxN][maxN], f[maxN][maxN], dist[maxN], lim, res;
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m >> lim >> S >> T;
	--S, --T;
	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		std::cin >> cost[u][v] >> capacity[u][v];

		capacity[v][u] = capacity[u][v], cost[v][u] = cost[u][v];
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	for (maxn i = 0; i < n; i++) capacity[i][i] = maxA, cost[i][i] = 0;
}


bool Find_Path(const maxn S, const maxn T) {
	std::deque <maxn> dq;
	int color[maxN] = {};
	std::fill(dist, dist + n, maxD);

	dq.push_back(S);
	dist[S] = 0, color[S] = inq;

	while (!dq.empty()) {
		maxn u = dq.front(); dq.pop_front();
		color[u] = outq;

		for (maxn i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i]; 
			maxa duv = ((f[u][v] < 0) ? -1 : 1) * cost[u][v];

			if (f[u][v] >= capacity[u][v] || dist[v] <= dist[u] + duv) continue;
			dist[v] = dist[u] + duv, par[v] = u;

			if (color[v] == never) dq.push_back(v);
			if (color[v] == outq) dq.push_front(v);
			color[v] = inq;
		}
	}

	return dist[T] != maxD;
}


void Update(const maxn S, const maxn T) {
	maxa delta = lim;
	maxn v = T;

	while (v != S) {
		delta = std::min(delta, f[par[v]][v] >= 0 ? (capacity[par[v]][v] - f[par[v]][v]) : -f[par[v]][v]); //***********
		v = par[v];
	}
	lim -= delta, res += delta * dist[T];

	v = T;
	while (v != S) {
		f[par[v]][v] += delta;
		f[v][par[v]] -= delta;
		v = par[v];
	}
}


bool Process() {
	res = 0;
	while (lim && Find_Path(S, T)) Update(S, T);
	if (lim != 0) return 0;

	std::cout << res << '\n';
	for (maxn u = 0; u < n; u++) for (maxn v = 0; v < n; v++)
		if (f[u][v] > 0) std::cout << u + 1 << ' ' << v + 1 << ' ' << f[u][v] << '\n';
	std::cout << "0 0 0";
	
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "-1";
}