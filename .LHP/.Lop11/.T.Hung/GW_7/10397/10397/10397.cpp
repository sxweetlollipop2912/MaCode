// AC UVa
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <iomanip>

#pragma warning (disable:4996)

#define maxN 751
#define maxM 1001
#define maxD 999999999999
#define X first
#define Y second
#define V first
#define cost second

typedef int maxn, maxm;
typedef long double maxa;
typedef std::pair <maxa, maxa> co_t;
typedef std::pair <maxn, maxa> pq_t;

maxn n, m;
co_t p[maxN];
maxa mn[maxN], d[maxN][maxN];
bool done[maxN];


void Prepare() {
	for (maxn i = 0; i < n; i++) std::cin >> p[i].X >> p[i].Y;

	for (maxn i = 0; i < n; i++) for (maxn j = i; j < n; j++) {
		d[i][j] = d[j][i] = sqrt((p[i].X - p[j].X) * (p[i].X - p[j].X) + (p[i].Y - p[j].Y) * (p[i].Y - p[j].Y));
	}

	std::cin >> m;
	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v; --u, --v;
		d[u][v] = d[v][u] = 0;
	}
}


//-------------------- PRIM --------------------------------

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue  <pq_t, std::vector <pq_t>, cmp> pq;


maxa Prim() {
	std::fill(mn, mn + n, maxD);
	std::fill(done, done + n, 0);
	pq = std::priority_queue  <pq_t, std::vector <pq_t>, cmp>();

	mn[0] = 0;
	pq.push(pq_t(0, mn[0]));

	for (maxn i = 0; i < n - 1; i++) {
		maxn u = pq.top().V; pq.pop();
		done[u] = 1;

		for (maxn v = 0; v < n; v++) {
			if (done[v] || mn[v] <= d[u][v]) continue;
			mn[v] = d[u][v];
			pq.push(pq_t(v, mn[v]));
		}
		while (done[pq.top().V]) pq.pop();
	}

	maxa re = 0;
	for (maxn i = 0; i < n; i++) re += mn[i];
	return re;
}

//------------------ END_OF_PRIM -------------------------------

void Process() {
	std::cout << std::fixed; std::cout << std::setprecision(2);
	std::cout << Prim() << '\n';
}


int main() {
	freopen("10397.inp", "r", stdin);
	freopen("10397.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n) {
		Prepare();
		Process();
	}
}