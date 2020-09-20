#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 501
#define maxA 5000000001
#define vert first
#define cost second
#define c(s, c) ((s) + (K / (c)))

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n;
maxm m;
maxa K, T[maxN][maxN], C[maxN][maxN], mn[maxN], S[maxN], Cmn[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> n >> m >> K;

	for (maxm i = 0; i < m; i++) {
		maxn x, y;
		std::cin >> x >> y, --x, --y;
		std::cin >> T[x][y] >> C[x][y], T[y][x] = T[x][y], C[y][x] = C[x][y];

		ad[x].push_back(y); ad[y].push_back(x);
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


maxa Dijkstra(const maxn st, const maxn en) {
	std::fill(mn, mn + n, maxA);
	std::fill(Cmn, Cmn + n, maxA);

	mn[st] = 0; pq.push(pq_t(st, mn[st]));

	while (!pq.empty() && pq.top().vert != en) {
		maxn u = pq.top().vert; pq.pop();
		done[u] = 1;
		for (maxm i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i];
			if (done[v] || mn[v] < c(S[u] + T[u][v], std::min(Cmn[u], C[u][v]))) continue;
			S[v] = S[u] + T[u][v], Cmn[v] = std::min(Cmn[u], C[u][v]), mn[v] = c(S[v], Cmn[v]);
			pq.push(pq_t(v, mn[v]));
		}
		while (!pq.empty() && done[pq.top().vert]) pq.pop();
	}

	return mn[en];
}


void Process() {
	std::cout << Dijkstra(0, n - 1);
}


int main() {
	//freopen("flow.inp", "r", stdin);
	//freopen("flow.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}