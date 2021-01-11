#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 300001
#define V first
#define fi first
#define se second
#define cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxn> ad_t;
typedef std::pair <ad_t, maxa> e_t;

maxn n, m, K, P, root[maxN], rank[maxN];
bool isK[maxN], hasK[maxN];
std::vector <e_t> e, p;
std::vector <maxn> ide, idp, del, add;
maxa res;


bool cmp_e(const maxn x, const maxn y) {
    if (e[x].cost != e[y].cost) return e[x].cost > e[y].cost;
    return x > y;
}
bool cmp_p(const maxn x, const maxn y) {
    if (p[x].cost != p[y].cost) return p[x].cost < p[y].cost;
    return x < y;
}


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0, u; i < K; i++) std::cin >> u, --u, isK[u] = 1;

    std::cin >> m;
    for(maxn i = 0; i < m; i++) {
        maxn u, v; maxa c; std::cin >> u >> v >> c;
        --u, --v; if (u > v) std::swap(u, v);
        e.push_back(e_t(ad_t(u, v), c)); ide.push_back(i);
    }
    std::sort(ide.begin(), ide.end(), cmp_e);

    std::cin >> P;
    for(maxn i = 0; i < P; i++) {
        maxn u, v; maxa c; std::cin >> u >> v >> c;
        --u, --v; if (u > v) std::swap(u, v);
        p.push_back(e_t(ad_t(u, v), c)); idp.push_back(i);
    }
    std::sort(idp.begin(), idp.end(), cmp_p);

    for(maxn i = 0; i < n; i++)
        root[i] = i, rank[i] = 0, hasK[i] = isK[i];
}


bool Union(maxn x, maxn y) {
    while (x != root[x]) x = root[x];
    while (y != root[y]) y = root[y];
    if (x == y || (hasK[x] && hasK[y])) return 0;

    if (rank[x] < rank[y]) root[y] = x, hasK[x] |= hasK[y];
    else root[x] = y, hasK[y] |= hasK[x], ++rank[x];
    return 1;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < ide.size(); i++) {
        e_t edge = e[ide[i]];
        maxn u = edge.V.fi, v = edge.V.se; maxa c = edge.cost;
        if (Union(u, v)) continue;
        res += c; //std::cout << "e " << u + 1 << ' ' << v + 1 << '\n';
        del.push_back(ide[i]);
    }

    for(maxn i = 0; i < idp.size(); i++) {
        e_t edge = p[idp[i]];
        maxn u = edge.V.fi, v = edge.V.se; maxa c = edge.cost;
        if (!Union(u, v)) continue;
        res += c;// std::cout << "p " << u + 1 << ' ' << v + 1 << '\n';
        add.push_back(idp[i]);
    }

    std::cout << res << '\n' << del.size() << '\n';
    std::sort(del.begin(), del.end());
    for(maxn i = 0; i < del.size(); i++) std::cout << del[i] + 1 << ' ';

    std::cout << '\n' << add.size() << '\n';
    std::sort(add.begin(), add.end());
    for(maxn i = 0; i < add.size(); i++) std::cout << add[i] + 1 << ' ';
}


int main() {
    freopen("moji.inp", "r", stdin);
    freopen("moji.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    Prepare();
    Process();
}



