// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
 
#pragma warning (disable:4996)
 
#define maxN 52
#define maxT 12
#define x first
#define y second
#define coo first
#define dist second
#define scene first
#define end second
#define sc first
#define cost second
#define Scene (maxn)2048
#define nopath (maxN * maxN * 2)
#define unable 0
#define able 1
#define treasure -1
#define fillTable(a, r, c, X) for (maxn i = 0; i < r; i++) std::fill(a[i], a[i] + c, X)
 
typedef int maxn;
typedef std::pair <maxn, maxn> co_t, sc_t;
typedef std::pair <sc_t, maxn> pq_t;
typedef std::pair <co_t, maxn> bfs_t;
 
maxn ROW, COL, id[maxN][maxN], mn[Scene + 2][maxT], d[maxT][maxT], n, res;
bool done[Scene + 2][maxN];
int map[maxN][maxN];
int f[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int f1[8][2] = { {0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1} };
co_t start;
 
 
bool check(const co_t c) {
    return c.x >= 0 && c.y >= 0 && c.x < ROW && c.y < COL;
}
 
 
void Prepare() {
    std::cin >> COL;
    fillTable(map, ROW, COL, able);
 
    n = 1;
    for (maxn i = 0; i < ROW; i++) 
        for (maxn j = 0; j < COL; j++) {
            char c;
            std::cin >> c;
 
            if (c == '@') start.x = i, start.y = j, id[i][j] = 0;
            else if (c == '!') map[i][j] *= treasure, id[i][j] = n++;
            else if (c != '.') {
                map[i][j] = unable;
                if (c != '*') continue;
 
                for (int k = 0; k < 8; k++) {
                    maxn x1 = i + f1[k][0], y1 = j + f1[k][1];
                    if (check(co_t(x1, y1))) map[x1][y1] = unable;
                }
            }
        }
}
 
 
void BFS(const co_t st) {
    fillTable(done, ROW, COL, 0);
    std::queue <bfs_t> bfs;
 
    bfs.push(bfs_t(st, 0));
    done[st.x][st.y] = 1;
 
    while (!bfs.empty()) {
        bfs_t u = bfs.front();
        bfs.pop();
 
        if (u.coo == start || map[u.coo.x][u.coo.y] == treasure) 
            d[id[st.x][st.y]][id[u.coo.x][u.coo.y]] = u.dist;
 
        for (int k = 0; k < 4; k++) {
            bfs_t v = bfs_t(co_t(u.coo.x + f[k][0], u.coo.y + f[k][1]), u.dist + 1);
            if (!check(v.coo) || map[v.coo.x][v.coo.y] == unable || done[v.coo.x][v.coo.y]) continue;
 
            done[v.coo.x][v.coo.y] = 1;
            bfs.push(v);
        }
    }
}
 
 
void Create_Graph() {
    fillTable(d, n, n, nopath);
 
    if (map[start.x][start.y] == able) 
        BFS(start);
 
    for (maxn i = 0; i < ROW; i++) 
        for (maxn j = 0; j < COL; j++) 
            if (map[i][j] == treasure) BFS(co_t(i, j));
}
 
 
maxn on(const maxn num, const maxn bit) {
    return num | (1 << (bit - 1));
}
 
 
// --------- DIJKSTRA --------------------------------------------
 
class cmp {
public:
    bool operator()(const pq_t p1, const pq_t p2) {
        return p1.cost > p2.cost;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;
 
 
void Fill(const maxn np, const maxn u) {
    for (maxn v = 1; v < n; v++) {
        maxn np_v = on(np, v);
        if (d[u][v] == nopath || np_v == np || done[np_v][v] || mn[np_v][v] <= mn[np][u] + d[u][v]) continue;
 
        mn[np_v][v] = mn[np][u] + d[u][v];
        pq.push(pq_t(sc_t(np_v, v), mn[np_v][v]));
    }
}
 
 
sc_t Find() {
    while (!pq.empty() && done[pq.top().sc.scene][pq.top().sc.end]) pq.pop();
    if (pq.empty()) return sc_t(-1, -1);
 
    sc_t re = pq.top().sc;
    pq.pop();
    return re;
}
 
 
void Dijkstra() {
    fillTable(done, Scene + 2, maxT, 0);
    fillTable(mn, Scene + 2, maxT, nopath);
 
    sc_t cur = sc_t(0, 0);
    mn[cur.scene][cur.end] = 0;
    pq.push(pq_t(cur, 0));
 
    while (!pq.empty()) {
        done[cur.scene][cur.end] = 1;
        Fill(cur.scene, cur.end);
        cur = Find();
    }
}
 
// ------------- DIJKSTRA -----------------------------------
 
 
void Process() {
    Create_Graph();
    Dijkstra();
     
    res = (bool)(n - 1) * nopath;
    for (maxn i = 1; i < n; i++) 
        res = std::min(res, mn[(1 << (n - 1)) - 1][i] + d[i][0]);
 
    if (res == nopath) res = -1;
    std::cout << res << '\n';
}
 
 
int main() {
    //freopen("10937.inp", "r", stdin);
    //freopen("10937.out", "w", stdout);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    while (std::cin >> ROW && ROW) {
        Prepare();
        Process();
    }
}