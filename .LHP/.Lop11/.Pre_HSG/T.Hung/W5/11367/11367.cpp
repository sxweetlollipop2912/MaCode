// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
#define maxM 10001
#define maxD 101
#define maxP 101
#define maxCap 101
#define maxC 2000000002
#define vert first
#define gas second
#define inf first
#define cost second

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> info_t;
typedef std::pair <info_t, maxa> pq_t;

maxn n;
maxm m;
maxa g[maxN][maxN], p[maxN], mn[maxN][maxCap];
std::vector <maxn> ad[maxN];
bool done[maxN][maxCap];


void Prepare() {
    std::cin >> n >> m;
    for(maxn i = 0; i < n; i++) {
        std::cin >> p[i];
        std::fill(g[i], g[i] + n, maxD);
    }
    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa d;
        std::cin >> u >> v >> d;
        g[u][v] = g[v][u] = std::min(g[u][v], d);
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u, const maxa gu, const maxa C) {
    if (gu < C && !done[u][gu + 1] && mn[u][gu + 1] > mn[u][gu] + p[u]) {
        mn[u][gu + 1] = mn[u][gu] + p[u];
        pq.push(pq_t(info_t(u, gu + 1), mn[u][gu + 1]));
    }
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (gu < g[u][v] || done[v][gu - g[u][v]] || mn[v][gu - g[u][v]] <= mn[u][gu]) continue;
        mn[v][gu - g[u][v]] = mn[u][gu];
        pq.push(pq_t(info_t(v, gu - g[u][v]), mn[v][gu - g[u][v]]));
    }
}


bool Dijkstra(const maxn S, const maxa T, const maxa C) {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    for(maxn i = 0; i < n; i++) {
        std::fill(done[i], done[i] + C + 1, 0);
        std::fill(mn[i], mn[i] + C + 1, maxC);
    }
    mn[S][0] = 0;
    pq.push(pq_t(info_t(S, 0), mn[S][0]));

    while (!pq.empty()) {
        info_t cur = pq.top().inf; pq.pop();
        if (done[cur.vert][cur.gas]) continue;

        done[cur.vert][cur.gas] = 1;
        Fill(cur.vert, cur.gas, C);
    }

    return mn[T][0] != maxC;
}


void Process() {
    int q;
    std::cin >> q;

    while (q--) {
        maxn s, t; maxa C;
        std::cin >> C >> s >> t;
        if (!Dijkstra(s, t, C)) std::cout << "impossible\n";
        else std::cout << mn[t][0] << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
