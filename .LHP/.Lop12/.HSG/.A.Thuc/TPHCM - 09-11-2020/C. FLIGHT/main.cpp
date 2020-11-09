#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 100001
#define INF 99999999999999999
#define V first
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, m;
maxa mn1[maxN], mn2[maxN], res;
std::vector <ad_t> ad[maxN], ad2[maxN];


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        --u, --v;
        ad[u].push_back(ad_t(v, c));
        ad2[v].push_back(ad_t(u, c));
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn st, maxa mn[], const std::vector <ad_t> ad[]) {
    std::fill(mn, mn + n, INF);
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();

    mn[st] = 0;
    pq.push(pq_t(st, mn[st]));

    while (!pq.empty()) {
        maxn u = pq.top().V; pq.pop();

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
            if (mn[v] <= mn[u] + c) continue;

            mn[v] = mn[u] + c;
            pq.push(pq_t(v, mn[v]));
        }

        while (!pq.empty() && mn[pq.top().V] != pq.top().cost) pq.pop();
    }
}


void Process() {
    Dijkstra(0, mn1, ad);
    Dijkstra(n - 1, mn2, ad2);

    res = INF;
    for(maxn u = 0; u < n; u++) for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
        res = std::min(res, mn1[u] + mn2[v] + (c / 2));
    }

    std::cout << res;
}


int main() {
    //freopen("C.inp", "r", stdin);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
