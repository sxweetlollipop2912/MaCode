// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 102
//#define maxM 10001
#define maxC 1000000002
#define vert first
#define cost second

typedef int maxn, maxm;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n;
maxm m;
std::vector <maxn> ad[maxN];
maxa C[maxN][maxN], mn[maxN];
bool done[maxN];


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < n; i++) {
        ad[i].clear();
        std::fill(C[i], C[i] + n, 0);
    }
    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa d;
        std::cin >> u >> v >> d;
        C[v][u] = C[u][v] = std::min(-d, C[u][v]);
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
}


class cmp {
public:
    bool operator() (const pq_t p1, const pq_t p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u) {
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (done[v] || mn[v] <= C[u][v]) continue;
        mn[v] = C[u][v];
        pq.push(pq_t(v, C[u][v]));
    }
}


maxa Prim() {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    std::fill(done, done + n, 0);
    std::fill(mn, mn + n, 0);

    mn[0] = -maxC;
    pq.push(pq_t(0, mn[0]));

    for(maxn i = 0; i < n; i++) {
        while (done[pq.top().vert]) pq.pop();
        maxn u = pq.top().vert; done[u] = 1;
        pq.pop();
        Fill(u);
    }
    return *std::max_element(mn, mn + n);
}


void Process() {
    if (n == 1) std::cout << C[0][0] << '\n';
    else std::cout << -Prim() << '\n';
}


int main() {
    //freopen("10842.inp","r",stdin);
    //freopen("10842.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int q;
    std::cin >> q;

    for(int cntq = 1; cntq <= q; cntq++) {
        std::cout << "Case #" << cntq << ": ";
        Prepare();
        Process();
    }
}