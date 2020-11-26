// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

#define maxN 200010
#define idx(x) (vertice[x])
#define V first
#define cost second

typedef long long maxn;
typedef std::pair <maxn, maxn> pq_t;

const maxn N = 1e15, INF = 9999999999999999;

maxn n, m, nv, mn[maxN];
std::vector <maxn> ad[maxN], V;
std::map <maxn, maxn> vertice;


maxn A(const maxn B) {
    maxn idx = std::lower_bound(V.begin(), V.end(), B - 4 + 1) - V.begin();
    return B - (3 + 2 * idx);
}


maxn next(maxn x) {
    std::map <maxn, maxn>::iterator it = vertice.upper_bound(x);
    return it == vertice.end() ? -1 : it->first;
}
maxn prev(maxn x) {
    std::map <maxn, maxn>::iterator it = vertice.lower_bound(x);
    return it == vertice.begin() ? -1 : (it--)->first;
}


void Prepare() {
    std::cin >> n >> m;

    V.push_back(2);
    for(maxn i = 1, x = 2; V.back() < N; i++, x += !(i & 1)) V.push_back(V.back() + x);

    nv = 1;
    for(maxn i = 0; i < m; i++) {
        maxn v; std::cin >> v;
        maxn u = A(v);
        if (!vertice[u]) vertice[u] = nv++;
        if (!vertice[v]) vertice[v] = nv++;
        ad[idx(u)].push_back(v);
        ad[idx(v)].push_back(u);
    }
    if (!vertice[1]) vertice[1] = nv++;
    if (!vertice[n]) vertice[n] = nv++;
    nv = vertice.size();

    for(std::map <maxn, maxn>::iterator it = vertice.begin(); it != vertice.end(); it++) {
        maxn u = it->second, u_idx = idx(u);
        maxn v = next(u);
        if (v != -1) ad[u_idx].push_back(v);
        v = prev(u);
        if (v != -1) ad[u_idx].push_back(v);
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp> pq;


maxn Dijkstra(const maxn st, const maxn en) {
    std::fill(mn, mn + maxN, INF);
    mn[idx(st)] = 0;
    pq.push(pq_t(st, mn[idx(st)]));

    while (!pq.empty() && pq.top().V != en) {
        maxn u = pq.top().V; pq.pop();

        for(maxn i = 0; i < ad[idx(u)].size(); i++) {
            maxn v = ad[u][i];
            if (mn[idx(v)] <= mn[idx(u)] + 1) continue;
            mn[idx(v)] = mn[idx(u)] + 1;
            pq.push(pq_t(v, mn[idx(v)]));
        }
    }
}


void Process() {
    std::cout << BFS(1, n);
}


int main() {
    freopen("vuotnguc.inp", "r", stdin);
    //freopen("vuotnguc.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
