#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 300001
#define maxX 5002
#define X first
#define Y second
#define valid(c) (c.X >= MINX && c.X <= MAXX && c.Y >= MINY && c.Y <= MAXY)

typedef long maxn;
typedef std::pair <maxn, maxn> c_t;

maxn MAXX, MAXY, MINX, MINY;
maxn n, K, f[8][2] = { { 1,1 },{ -1,1 },{ 1,-1 },{ -1,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } }, step[maxX][maxX];
c_t a[maxN], k[maxN];
std::queue <c_t> bfs;


void Prepare() {
    std::cin >> n >> K;

    MINX = MINY = maxX;
    MAXX = MAXY = 0;
    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i].X >> a[i].Y;

        MAXX = std::max(MAXX, a[i].X);
        MINX = std::min(MINX, a[i].X);
        MAXY = std::max(MAXY, a[i].Y);
        MINY = std::min(MINY, a[i].Y);
    }
    for(maxn i = 0; i < K; i++) {
        std::cin >> k[i].X >> k[i].Y;

        MAXX = std::max(MAXX, k[i].X);
        MINX = std::min(MINX, k[i].X);
        MAXY = std::max(MAXY, k[i].Y);
        MINY = std::min(MINY, k[i].Y);
    }
}


void BFS() {
    for(maxn i = MINX; i <= MAXX; i++)
        std::fill(step[i], step[i] + MAXY + 1, -1);

    for(maxn i = 0; i < n; i++) {
        bfs.push(a[i]);
        step[a[i].X][a[i].Y] = 0;
    }

    while (!bfs.empty()) {
        c_t u = bfs.front(); bfs.pop();

        for(int i = 0; i < 4; i++) {
            c_t v = c_t(u.X + f[i][0], u.Y + f[i][1]);
            if (!valid(v) || step[v.X][v.Y] != -1)
                continue;

            step[v.X][v.Y] = step[u.X][u.Y] + 1;
            bfs.push(v);
        }
    }
}


void Process() {
    BFS();
    for(maxn i = 0; i < K; i++) {
        c_t u = k[i];
        maxn re = step[u.X][u.Y] == -1? maxX : step[u.X][u.Y];

        for(int j = 4; j < 8; j++) {
            c_t v = c_t(u.X + f[j][0], u.Y + f[j][1]);
            if (!valid(v) || step[v.X][v.Y] == -1) continue;

            re = std::min(re, step[v.X][v.Y] + 1);
        }

        std::cout << re << '\n';
    }
}


int main() {
    freopen("anninh.inp", "r", stdin);
    freopen("anninh.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
