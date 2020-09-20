#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 102
#define maxR 10001
#define maxSP 8

typedef int maxn, maxr;

struct co {
    maxn x, y;
};
co newCo(maxn x, maxn y) {
    co re;
    re.x = x; re.y = y;
    return re;
}

/*struct info {
    maxn x, y;
    maxr step;
};
info newInfo(maxn x, maxn y, maxt step) {
    info re;
    re.x = x; re.y = y; re.steo = step;
    return re;
}*/

maxn n, bx, by, qx, qy, desx, desy;
co prev[maxN][maxN];
std::queue <co> bfs;
bool map[maxN][maxN];
int sp[8][2] = { {-2,1 },{ -1,2 },{ 1,2 },{ 2,1 },{ 2,-1 },{ 1,-2 },{ -1,-2 },{ -2,-1} };


void Prepare() {
    std::cin >> n >> qx >> qy >> bx >> by >> desx >> desy;
}


bool check_co(maxn x, maxn y) {
    if (x <= 0 || x > n || y <= 0 || y > n) return 0;
    if (x == qx || y == qy) return 0;
    if (abs(x - qx) == abs(y - qy)) return 0;
    return 1;
}



bool Fill(co c) {
    maxn x = c.x, y = c.y;

    for(int i = 0; i < maxSP; i++)  {
        maxn x1 = x + sp[i][0], y1 = y + sp[i][1];
        if (!check_co(x1, y1) || map[x1][y1]) continue;

        prev[x1][y1] = c;
        map[x1][y1] = 1;
        bfs.push(newCo(x1, y1));

        if (x1 == desx && y1 == desy) return 1;
    }

    return 0;
}


bool BFS() {
    prev[bx][by] = newCo(-1, -1);
    bfs.push(newCo(bx, by));

    map[bx][by] = 1;

    while (!bfs.empty()) {
        if (Fill(bfs.front())) return 1;
        bfs.pop();
    }

    return 0;
}


void Output() {
    std::vector <co> res;
    co p = newCo(desx, desy);

    while (p.x != -1) {
        res.push_back(p);
        p = prev[p.x][p.y];
    }

    for(maxr i = res.size() - 1; i > 0; i--) std::cout << "(" << res[i].x << "," << res[i].y << ")=>";
    std::cout << "(" << res[0].x << "," << res[0].y << ")";
}



int main() {
    freopen("hauma.inp","r",stdin);
    freopen("hauma.out","w",stdout);

    Prepare();
    if (BFS()) Output();
    else std::cout << 0;
}
