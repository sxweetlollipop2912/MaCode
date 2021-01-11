#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 200001
#define V first
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

const maxa INF = 9999999999999999;

maxn n, m;
maxa T[maxN], res_cost, res_lvl;
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
    std::cin >> n >> m;
    for(maxn i = 0; i < n; i++) std::cin >> T[i];

    for(maxn i = 0; i < m; i++) {
        maxn u, v; maxa c;
        std::cin >> u >> v >> c;
        --u, --v;
        ad[u].push_back(ad_t(v, c));
        ad[v].push_back(ad_t(u, c));
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


maxa Prim(const maxn st = 0, const maxn en = n - 1) {
    std::fill(done, done + n, 0);
    maxa minT = INF;
    res_cost = 0, res_lvl = 1;

    pq.push(pq_t(st, 1));

    for(maxn i = 0; i < n && !pq.empty(); i++) {
        maxn u = pq.top().V; maxa c = pq.top().cost;
        done[u] = 1;
        pq.pop();

        res_cost += std::max((maxa)0, c - res_lvl) * minT;
        res_lvl = std::max(c, res_lvl);
        minT = std::min(minT, T[u]);
        if (u == en) return res_cost;

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i].V; maxa c = ad[u][i].cost;
            if (done[v]) continue;
            pq.push(pq_t(v, c));
        }
        while (!pq.empty() && done[pq.top().V]) pq.pop();
    }

    return -1;
}


void Process() {
    std::cout << Prim();
}


int main() {
    freopen("pokemon.inp", "r", stdin);
    freopen("pokemon.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
