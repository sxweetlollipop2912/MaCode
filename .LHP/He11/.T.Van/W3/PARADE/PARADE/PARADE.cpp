#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 10001
#define maxA 100000001
#define V first
#define cost second

typedef long maxn, maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m;
maxa mn[maxN], sumT, sum;
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		maxn u, v; maxa c;
		std::cin >> u >> v >> c;
		u--; v--;
		ad[u].push_back(ad_t(v, c));
		ad[v].push_back(ad_t(u, c));
        sum += c;
	}
}


class cmp {
public:
    bool operator() (const pq_t &p1, const pq_t &p2) {
        return p1.cost < p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Prim() {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    std::fill(done, done + n, 0);
    std::fill(mn, mn + n, -1);

    mn[0] = 0;
    pq.push(pq_t(0, mn[0]));

    for (maxn i = 0; i < n; i++) {
        while (done[pq.top().V]) pq.pop();
        maxn u = pq.top().V; 
        done[u] = 1;
        pq.pop();

        for (maxn j = 0; j < ad[u].size(); j++) {
            maxn v = ad[u][j].V;
            maxa c = ad[u][j].cost;
            if (done[v] || mn[v] >= c) continue;
            mn[v] = c;
            pq.push(pq_t(v, mn[v]));
        }
    }
}


void Process() {
    Prim();
    for (maxn i = 0; i < n; i++) sumT += mn[i];
    std::cout << sum - sumT;
}


int main() {
    freopen("parade.inp", "r", stdin);
    freopen("parade.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}