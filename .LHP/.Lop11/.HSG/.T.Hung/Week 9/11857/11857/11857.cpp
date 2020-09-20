// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 1000001
//#define maxD 10000000001
#define V first
#define Dist second

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t, ad_t;

maxn n;
maxm m;
maxa res;
std::vector <ad_t> ad[maxN];

class cmp {
public:
	bool operator() (const pq_t p1, const pq_t p2) {
		return p1.Dist > p2.Dist;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;
bool done[maxN];


void Init() {
	pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();
	std::fill(done, done + n, 0);
	res = 0;
	for (maxn i = 0; i < n; i++) ad[i].clear();
}


void Prepare() {
	std::cin >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; maxa d;
		std::cin >> u >> v >> d;
		ad[u].push_back(ad_t(v, d));
		ad[v].push_back(ad_t(u, d));
	}
}


bool Prim() {
	pq.push(pq_t(0, 0));

	maxn i;
	for (i = 0; i < n && !pq.empty(); i++) {
		maxn u = pq.top().V; done[u] = 1;
		res = std::max(res, pq.top().Dist); pq.pop();

		for (maxm i = 0; i < ad[u].size(); i++) {
			maxn v = ad[u][i].V;
			if (!done[v]) pq.push(pq_t(v, ad[u][i].Dist));
		}

		while (!pq.empty() && done[pq.top().V]) pq.pop();
	}
	
	return i == n;
}


void Process() {
	if (!Prim()) std::cout << "IMPOSSIBLE\n";
	else std::cout << res << '\n';
}


int main() {
	//freopen("11857.inp", "r", stdin);
	//freopen("11857.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Init();
		Prepare();
		Process();
	}
}