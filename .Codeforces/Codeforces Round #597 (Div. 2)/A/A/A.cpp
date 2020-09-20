#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 2002
#define maxR 100000000000000001
#define vert first
#define cost second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n, st, par[maxN];
maxa x[maxN], y[maxN], d[maxN][maxN], c[maxN], k[maxN], mn[maxN], res, res_s, res_e;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> x[i] >> y[i];
	for (maxn i = 0; i < n; i++) std::cin >> c[i], st = (c[st] >= c[i]) ? i : st;
	for (maxn i = 0; i < n; i++) std::cin >> k[i];

	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		d[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
	}
}


class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;
bool done[maxN];


void Fill(const maxn u) {
	for (maxn v = 0; v < n; v++) {
		if (done[v] || mn[v] <= d[u][v]) continue;
		mn[v] = d[u][v], par[v] = u;
		pq.push(pq_t(v, mn[v]));
	}
}


void Prim() {
	std::fill(mn, mn + n, maxR);
	mn[st] = 0, par[st] = st;
	pq.push(pq_t(st, mn[st]));

	for (maxn i = 0; i < n; i++) {
		while (done[pq.top().vert]) pq.pop();
		maxn u = pq.top().vert; pq.pop();
		done[u] = 1;
		Fill(u);
	}
}


void Process() {
	Prim();
	res = 0, res_s = 1, res_e = n - 1;
	for (maxn v = 0; v < n; v++) {
		if (par[v] != v && d[par[v]][v] > c[v]) par[v] = v, ++res_s, --res_e;
		res += (par[v] == v) ? c[v] : d[par[v]][v];
	}

	std::cout << res << '\n' << res_s << '\n';
	for (maxn i = 0; i < n; i++) if (par[i] == i) std::cout << i + 1 << ' ';
	std::cout << '\n' << res_e << '\n';
	for (maxn i = 0; i < n; i++) if (par[i] != i) std::cout << par[i] + 1 << ' ' << i + 1 << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}