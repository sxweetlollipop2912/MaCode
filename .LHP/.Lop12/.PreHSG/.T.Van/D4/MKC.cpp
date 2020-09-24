#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 200001
#define maxA 99999999999999999
#define V first
#define Cost second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n;
maxa a[maxN];
bool done[maxN];
std::vector <ad_t> ad[maxN];


void Prepare() {
    maxn W = 0;
    std::cin >> n >> W;

    for(maxn i = 0; i < n; i++) std::cin >> a[i];

    for(maxn i = 0; i < W; i++) {
        maxn u, v; maxa w;
        std::cin >> u >> v >> w;
        --u, --v;
        ad[u].push_back(ad_t(v, w));
        ad[v].push_back(ad_t(u, w));
    }

    maxn mn = std::min_element(a, a + n) - a;
    for(maxn i = 0; i < n; i++) {
        if (i == mn) continue;
        ad[i].push_back(ad_t(mn, a[mn] + a[i]));
        ad[mn].push_back(ad_t(i, a[i] + a[mn]));
    }
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.Cost > p2.Cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


maxa Prim() {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    std::fill(done, done + n, 0);

    maxa re = 0;
    pq.push(pq_t(0, 0));

    for(maxn i = 0; i < n; i++) {
        while (done[pq.top().V]) pq.pop();

        maxn u = pq.top().V;
        done[u] = 1;
        re += pq.top().Cost;
        pq.pop();

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i].V; maxa c = ad[u][i].Cost;
            if (done[v]) continue;
            pq.push(pq_t(v, c));
        }
    }

    return re;
}


void Process() {
    std::cout << Prim();
}


int main() {
    freopen("mkc.inp", "r", stdin);
    freopen("mkc.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
