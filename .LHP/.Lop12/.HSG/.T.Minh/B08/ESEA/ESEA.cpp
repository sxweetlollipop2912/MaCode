#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 1001
#define V first
#define cost second

typedef long maxn, maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m, Nmin;
maxa Tmax, U[maxN], D[maxN], nxt[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> Nmin >> Tmax;
    for(maxn i = 0; i < n; i++) std::cin >> U[i];
    for(maxn i = 0; i < n; i++) std::cin >> D[i];

    maxn u, v; maxa c;
    while (std::cin >> u >> v >> c) {
        --u, --v; ++m;
        ad[u].push_back(ad_t(v, c));
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn st) {
    std::fill(nxt. nxt + n. 0);
    pq.push(ad_t(st, 0));

    while (!pq.empty()) {
        maxn u = pq.top().V; maxa t = pq.top().cost; pq.pop();
        nxt[u] = t + U[u] + D[u] + 2;

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
            if (nxt[u] - 1 + )
        }
    }
}
