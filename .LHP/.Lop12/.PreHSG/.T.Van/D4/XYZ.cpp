#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 501
#define maxA 99999999999999999
#define maxV 250001
#define N (m * n)
#define row(x, n) ((x) / (n))
#define col(x, n) ((x) % (n))
#define num(i, j, n) ((i) * (n) + (j))
#define valid(i, j, m, n) ((i) >= 0 && (i) < (m) && (j) >= 0 && (j) < (n))
#define V first
#define Cost second
#define cost(x) (a[row(x, n)][col(x, n)])
#define ST (0)
#define EN num(m - 1, n - 1, n)

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn m, n, c1, c2, c3, f[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
maxa a[maxN][maxN], mn[4][maxV], res;


void Prepare() {
    std::cin >> m >> n;

    maxn x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    --x1, --y1, --x2, --y2, --x3, --y3;
    c1 = num(x1, y1, n);
    c2 = num(x2, y2, n);
    c3 = num(x3, y3, n);

    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++)
        std::cin >> a[i][j];
}


class cmp {
public:
    bool operator()(const pq_t &p1, const pq_t &p2) {
        return p1.Cost > p2.Cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Dijkstra(const maxn st, maxa mn[]) {
    pq = std::priority_queue <pq_t, std::vector <pq_t>, cmp >();
    std::fill(mn, mn + N, maxA);

    mn[st] = cost(st);
    pq.push(pq_t(st, mn[st]));

    while (!pq.empty()) {
        maxn u = pq.top().V; pq.pop();

        for(int k = 0; k < 4; k++) {
            maxn vx = row(u, n) + f[k][0], vy = col(u, n) + f[k][1], v = num(vx, vy, n);
            if (!valid(vx, vy, m, n) || mn[v] <= mn[u] + a[vx][vy]) continue;

            mn[v] = mn[u] + a[vx][vy];
            pq.push(pq_t(v, mn[v]));
        }

        while (!pq.empty() && pq.top().Cost != mn[pq.top().V]) pq.pop();
    }
}


void Process() {
    Dijkstra(ST, mn[0]);
    Dijkstra(c1, mn[1]);
    Dijkstra(c2, mn[2]);
    Dijkstra(c3, mn[3]);

    res = maxA;
    /// 1 -> 2
    res = std::min(res, mn[0][c1] + mn[1][c2] - cost(c1) + mn[2][EN] - cost(c2));
    /// 2 -> 1
    res = std::min(res, mn[0][c2] + mn[2][c1] - cost(c2) + mn[1][EN] - cost(c1));
    /// 1 -> 3
    res = std::min(res, mn[0][c1] + mn[1][c3] - cost(c1) + mn[3][EN] - cost(c3));
    /// 3 -> 1
    res = std::min(res, mn[0][c3] + mn[3][c1] - cost(c3) + mn[1][EN] - cost(c1));
    /// 2 -> 3
    res = std::min(res, mn[0][c2] + mn[2][c3] - cost(c2) + mn[3][EN] - cost(c3));
    /// 3 -> 2
    res = std::min(res, mn[0][c3] + mn[3][c2] - cost(c3) + mn[2][EN] - cost(c2));

    std::cout << res;
}


int main() {
    freopen("xyz.inp", "r", stdin);
    freopen("xyz.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
