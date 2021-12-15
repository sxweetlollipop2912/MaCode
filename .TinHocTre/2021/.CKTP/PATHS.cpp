// AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

#define maxN 200001
#define maxL 19
#define U first
#define V second.first
#define C second.second
#define aV first
#define aC second
#define pU firsrt
#define pV second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t;
typedef std::pair <maxn, ad_t> e_t;
typedef std::pair <maxn, maxn> p_t;

const maxa INF = 1e18;

maxn n, m, root[maxN], rank[maxN], par[maxN][maxL], h[maxN];
maxa res[maxN], mx[maxN][maxL];
std::vector <e_t> e;
std::vector <ad_t> ad[maxN];
std::map <p_t, maxn> map;

void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn u, v, c; std::cin >> u >> v >> c;
        --u, --v;
        e.push_back(e_t(u, ad_t(v, c)));
        map[p_t(u, v)] = i;
        map[p_t(v, u)] = i;
    }
}


bool Union(maxn x, maxn y) {
    while (x != root[x]) x = root[x];
    while (y != root[y]) y = root[y];

    if (x == y) return 0;

    if (rank[x] < rank[y]) root[x] = y;
    else root[y] = x, ++rank[x];
    return 1;
}


bool cmp(const e_t x, const e_t y) {
    return x.C < y.C;
}


void DFS(const maxn u) {
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].aV;
        if (par[v][0] != -1) continue;

        par[v][0] = u;
        //std::cout << "par " << v << ' ' << u << '\n';
        mx[v][0] = ad[u][i].aC;
        h[v] = h[u] + 1;
        DFS(v);
    }
}


maxa Kruskal() {
    std::sort(e.begin(), e.end(), cmp);
    for(maxn i = 0; i < n; i++) root[i] = i, rank[i] = 0, par[i][0] = -1;
    maxa re = 0;

    for(maxn i = 0; i < m; i++) {
        maxn u = e[i].U, v = e[i].V;
        if (Union(u, v)) {
            ad[u].push_back(ad_t(v, e[i].C));
            ad[v].push_back(ad_t(u, e[i].C));
            res[map[p_t(u, v)]] = -1;
            res[map[p_t(v, u)]] = -1;
            //std::cout << "tree " << u << ' ' << v << '\n';

            re += e[i].C;
        }
    }

    par[0][0] = 0;
    mx[0][0] = 0;
    h[0] = 0;
    DFS(0);

    return re;
}


void Build() {
    for(maxn lg = 1; (1 << lg) <= n; lg++) for(maxn i = 0; i < n; i++) {
        mx[i][lg] = std::max(mx[i][lg - 1], mx[par[i][lg - 1]][lg - 1]);
        par[i][lg] = par[par[i][lg - 1]][lg - 1];

        //std::cout << "build " << i << ' ' << lg << ' ' << h[i] << ' ' << par[i][lg] << ' ' << mx[i][lg] << '\n';
    }
}


maxa LCA(maxn x, maxn y) {
    //std::cout << "LCA " << x << ' ' << y << ' ' << h[x] << ' ' << h[y] << '\n';
    maxa re = 0;

    while (h[x] != h[y]) {
        maxn lg = log2(std::max(h[x] - h[y], h[y] - h[x]));
        if (h[x] > h[y]) {
            re = std::max(re, mx[x][lg]);
            x = par[x][lg];
        }
        else {
            re = std::max(re, mx[y][lg]);
            y = par[y][lg];
        }
    }
    //std::cout << re << '\n';

    if (x == y) return re;

    for(maxn lg = maxL - 1; lg >= 0; lg--) {
        if (par[x][lg] == par[y][lg]) continue;

        re = std::max(re, mx[x][lg]);
        re = std::max(re, mx[y][lg]);

        x = par[x][lg];
        y = par[y][lg];
    }

    if (x != y) {
        re = std::max(re, mx[x][0]);
        re = std::max(re, mx[y][0]);
        x = par[x][0];
        y = par[y][0];
    }

    //std::cout << x << ' ' << y << ' ' << re << '\n';
    return re;
}


void Process() {
    maxa sum = Kruskal();
    Build();

    for(maxn i = 0; i < m; i++) {
        maxn u = e[i].U, v = e[i].V, idx = map[p_t(u, v)];
        maxa c = e[i].C;

        if (res[idx] == -1) res[idx] = sum;
        else {
            res[idx] = sum - LCA(u, v) + c;
        }
        ////std::cout << "res " << u << ' ' << v << ' ' << c << ' ' << res[idx] << '\n';
    }

    for(maxn i = 0; i < m; i++) std::cout << res[i] << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}