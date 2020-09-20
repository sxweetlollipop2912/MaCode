#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 200001
#define maxM 200001
#define vert first
#define cost second

typedef long maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, id[maxN];
maxa a[maxN], res;
std::vector <ad_t> ad[maxN];


bool cmp_id(const maxn& x, const maxn& y) {
	return a[x] < a[y];
}


void Prepare() {
	maxm m = 0;
	std::cin >> n >> m;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], id[i] = i;
	std::sort(id, id + n, cmp_id);

	while (m--) {
		maxn u, v; maxa w;
		std::cin >> u >> v >> w;
		--u, --v;
		ad[u].push_back(ad_t(v, w));
		ad[v].push_back(ad_t(u, w));
	}

	for (maxn i = 1; i < n; i++) {
		ad[id[i]].push_back(ad_t(id[0], a[id[0]] + a[id[i]]));
		ad[id[0]].push_back(ad_t(id[i], a[id[0]] + a[id[i]]));
	}
}


class cmp_pq {
public:
	bool operator() (const pq_t& p1, const pq_t& p2) {
		return p1.cost > p2.cost;
	}
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp_pq > pq;
bool done[maxN];


void Fill(const maxn u) {
	for (maxm i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i].vert;
		if (!done[v]) pq.push(pq_t(v, ad[u][i].cost));
	}
}


void Prim() {
	pq.push(pq_t(id[0], 0));
	res = 0;

	for (maxn i = 0; i < n; i++) {
		while (done[pq.top().vert]) pq.pop();
		maxn u = pq.top().vert;
		res += pq.top().cost;
		pq.pop();

		done[u] = 1;
		Fill(u);
	}
}


void Process() {
	Prim();
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}