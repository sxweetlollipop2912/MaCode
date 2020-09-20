// broken, refer to old version
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <iomanip>

#define maxN 1001
#define maxA 10000001
#define fi first
#define se second
#define vert fi
#define cost se

typedef long maxn;
typedef long long maxa;
typedef std::pair<maxa, maxa> cost_t;
typedef std::pair<maxn, maxa> pq_t;

maxn n, m;
cost_t C[maxN][maxN];
maxa Ctmp[maxN][maxN], mn[maxN], C1, C2;
bool done[maxN];
std::vector<maxn> ad[maxN];


void Prepare() {
    std::cin >> n >> m;

    for (maxn i = 0; i < n; i++) {
        maxn u, v;
        std::cin >> u >> v, --u, --v;
        if (u == v) continue;
        std::cin >> C[u][v].fi >> C[u][v].se;

        C[u][v].fi *= 1000, C[u][v].se *= 1000;
        C[v][u].fi = C[u][v].fi, C[v][u].se = C[u][v].se, C1 += C[u][v].fi, C2 += C[u][v].se;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


class cmp {
public:
    bool operator()(const pq_t p1, const pq_t p2) {
        return p1.cost > p2.cost;
    }
};

std::priority_queue<pq_t, std::vector<pq_t>, cmp> pq;


void Fill(const maxn u) {
    for (maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (done[v] || mn[v] <= mn[u] + Ctmp[u][v]) continue;
        mn[v] = mn[u] + Ctmp[u][v];
        pq.push(pq_t(v, mn[v]));
    }
}


maxn Find() {
    while (!pq.empty() && done[pq.top().vert]) pq.pop();
    if (pq.empty()) return -1;
    maxn re = pq.top().vert;
    pq.pop();
    return re;
}


maxa Prim(const maxa M) {
    pq = std::priority_queue<pq_t, std::vector<pq_t>, cmp>();
    std::fill(done, done + n, 0);
    std::fill(mn, mn + n, maxA);

    maxn u = 0, v = 0;
    mn[v] = 0;
    pq.push(pq_t(v, mn[v]));

    maxa C1 = 0, C2 = 0;
    for (maxn i = 1; i < n; i++) {
        done[v] = 1;
        C1 += C[u][v].fi, C2 += C[u][v].se;
        Fill(v);
        u = v, v = Find();
    }

    return C1 - M * C2;
}


void Modify_Graph(const maxa M) {
    for (maxn u = 0; u < n; u++)
        for (maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i];
            Ctmp[u][v] = C[u][v].fi - m * C[u][v].se;
        }
}


void Process() {
    maxa l = 0, r = (C1 / C2) * 1000;
    while (l != r) {
        maxa mid = (l + r) / (maxa)2;
        Modify_Graph(mid);
        maxa re = Prim(mid);
        if (re >= 0) r = mid;
        else l = mid + 1;
        
    }

    std::cout << l << ' ' << (l / 1000) << '.';
    for (int x = 100; x != 0; x /= 10) {
        if (l / x != 0) break;
        std::cout << '0';
    }
    std::cout << (l % 1000);
}


int main() {
    //freopen("nangcap.inp", "r", stdin);
    //freopen("nangcap.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}