#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 1001
//#define maxM 100002
#define maxA 20000002
#define vert first
#define dist second
#define nre 0
#define rev 1

typedef int maxn;
typedef long maxm, maxa;
typedef std::pair <maxn, maxa> ad_t, pq_t;

maxn n, S;
maxm m;
maxa go[maxN], ret[maxN], res;
std::vector <ad_t> ad[2][maxN];
bool done[maxN];


void Prepare() {
    std::cin >> n >> m >> S;
    --S;

    for(maxm i = 0; i < m; i++) {
        maxn u, v; maxa d;
        std::cin >> u >> v >> d;
        --u, --v;
        ad[nre][u].push_back((ad_t(v, d)));
        ad[rev][v].push_back((ad_t(u, d)));
    }
}


///********************** DIJKSTRA *****************************
class cmp {
public:
    bool operator() (const pq_t p1, const pq_t p2) {
        return p1.dist > p2.dist;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Fill(const maxn u, const maxn id, maxa mn[]) {
    for(maxm i = 0; i < ad[id][u].size(); i++) {
        maxn v = ad[id][u][i].vert, d = ad[id][u][i].dist;
        if (done[v] || mn[v] <= mn[u] + d) continue;
        mn[v] = mn[u] + d;
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


void Dijkstra(maxn cur, const maxn id, maxa mn[]) {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    std::fill(done, done + n, false);
    std::fill(mn, mn + n, maxA);

    mn[cur] = 0;
    pq.push(pq_t(cur, mn[cur]));

    while (cur != -1) {
        done[cur] = true;
        Fill(cur, id, mn);
        cur = Find();
    }
}
///****************** END_OF_DIJKSTRA *****************************


void Process() {
    Dijkstra(S, nre, go);
    Dijkstra(S, rev, ret);

    res = 0;
    for(maxn i = 0; i < n; i++) res = std::max(res, go[i] + ret[i]);
    std::cout << res;
}


int main() {
    freopen("tatnien.inp","r",stdin);
    //freopen("tatnien.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
