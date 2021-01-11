#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 1000001

typedef long maxn;
typedef long long maxa;

struct Edge {
    maxn u, v;
    maxa cost;
    Edge() {u = 0, v = 0, cost = 0;}
    Edge(const maxn u, const maxn v, const maxa cost) {
        this->u = u, this->v = v, this->cost = cost;
    }
    bool static cmp(const Edge &e1, const Edge &e2) {
        return e1.cost < e2.cost;
    }
};

maxn m, n, root[maxN], rank[maxN];
std::vector <Edge> e;
maxa res;


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; maxa c; std::cin >> u >> v >> c;
        --u, --v;
        e.push_back(Edge(u, v, c));
    }
    for(maxn i = 0; i < n; i++) root[i] = i, rank[i] = 0;

    std::sort(e.begin(), e.end(), Edge::cmp);
}


bool Union(maxn x, maxn y) {
    while (x != root[x]) x = root[x];
    while (y != root[y]) y = root[y];
    if (x == y) return 0;

    if (rank[x] < rank[y]) root[x] = y;
    else root[y] = x, ++rank[x];
    return 1;
}


void Process() {
    maxn cnt = n;
    res = 0;
    for(maxn i = e.size() - 1; i >= 0; i--) {
        maxn u = e[i].u, v = e[i].v; maxa cost = e[i].cost;
        if (Union(u, v)) res += cost, --cnt;
        else if (cost > 0) res += cost;
    }

    if (cnt == 1) std::cout << res;
    else std::cout << "Impossible";
}


int main() {
    freopen("beta.inp", "r", stdin);
    //freopen("beta.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
