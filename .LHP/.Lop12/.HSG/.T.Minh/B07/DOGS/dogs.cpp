#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 1001
#define V first
#define cost second

typedef int maxn, maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n, m;
maxa w[maxN], T, res[maxN];
bool inQ[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> w[i];

    std::cin >> m;
    for(maxn i = 0; i < m; i++) {
        maxn u, v;
        std::cin >> u >> v, --u, --v;
        ad[u].push_back(v);
    }
    std::cin >> T;
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};;
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


void Dijkstra(const maxn st) {
    std::fill(res, res + n, 0);
    std::fill(inQ, inQ + n, 0);
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp>();

    inQ[st] = 1;
    pq.push(pq_t(st, 0));

    while (!pq.empty() && pq.top().cost <= T) {
        maxn u = pq.top().V; maxa cu = pq.top().cost;
        pq.pop();
        ++res[u], inQ[u] = 0;

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i];
            if (inQ[v]) continue;
            inQ[v] = 1;
            pq.push(pq_t(v, cu + w[v]));
        }
    }
}


void Process() {
    Dijkstra(0);
    for(maxn i = 0; i < n; i++) std::cout << res[i] << '\n';
}


int main() {
    freopen("dogs.inp", "r", stdin);
    //freopen("dogs.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
