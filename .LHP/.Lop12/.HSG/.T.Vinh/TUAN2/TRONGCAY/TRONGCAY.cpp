#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>

#define maxN 10001
#define INF 999999999
#define V first
#define cost second

typedef long maxn, maxm;
typedef long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n;
maxm m;
maxa d1[maxN], dn[maxN], res;
std::vector <ad_t> ad[maxN];


void Prepare() {
    std::cin >> n >> m;

    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        ad[u].push_back(ad_t(v, c));
        ad[v].push_back(ad_t(u, c));
    }
}


class cmp {
public:
    bool operator()(const pq_t& p1, const pq_t& p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn st, const std::vector <ad_t> ad[], maxa d[], const maxn n) {
    std::fill(d, d + n, INF);
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();

    d[st] = 0;
    pq.push(pq_t(st, 0));

    while (!pq.empty()) {
        maxn u = pq.top().V; pq.pop();

        for(maxm i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i].V;
            maxa c = ad[u][i].cost;
            if (d[v] <= d[u] + c) continue;

            d[v] = d[u] + c;
            pq.push(pq_t(v, d[v]));
        }

        while (!pq.empty() && d[pq.top().V] != pq.top().cost) pq.pop();
    }
}


void Process() {
    Dijkstra(0, ad, d1, n);
    Dijkstra(n - 1, ad, dn, n);

    res = 0;
    for(maxn u = 0; u < n; u++) for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V;
        maxa c = ad[u][i].cost;
        if (d1[u] + dn[v] + c == dn[0]) res += c * 2;
    }

    std::cout << res;
}


int main() {
    freopen("trongcay.inp", "r", stdin);
    freopen("trongcay.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
