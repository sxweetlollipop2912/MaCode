// undone
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

#define maxN 21
#define X first
#define Y second
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

typedef int maxn;
typedef std::pair <maxn, maxn> co_t;
typedef std::set <co_t> pic_t;

maxn m, n, pn, map[maxN][maxN], gr[maxN], f[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
char a[maxN][maxN];
std::vector <pic_t> pic;


void Prepare() {
    std::cin >> m >> n;
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++)
        std::cin >> a[i][j], map[i][j] = -1;
}


void DFS(const co_t u, const char color, const char num, pic_t &pic) {
    std::cout << u.X << ' ' << u.Y << '\n';
    pic.insert(u);
    map[u.X][u.Y] = num;

    for(int k = 0; k < 4; k++) {
        co_t v = co_t(u.X + f[k][0], u.Y + f[k][1]);
        if (!valid(v.X, v.Y) || a[v.X][v.Y] != color || pic.find(v) != pic.end()) continue;
        DFS(v, color, num, pic);
    }
}


void Rotate(pic_t &pic, pic_t &re) {
    re.clear();
    maxn xmax = -1, ymin = maxN;

    for(co_t u : pic) {
        xmax = std::max(xmax, u.X);
        ymin = std::min(ymin, u.Y);
    }

    for(co_t u : pic) {
        re.insert(co_t(u.Y - ymin, xmax - u.X));
    }
}


void Process() {
    pn = 0;
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++)
        if (map[i][j] == -1)
            DFS(co_t(i, j), a[i][j], pn, pic[pn++]);

    for(maxn i = 0, gn = 0; i < pn; i++) {
        if (gr[i]) continue;
        gr[i] = ++gn;
        pic_t p1, p2, p3, p4;
        Rotate(pic[i], p1); Rotate(p1, p2); Rotate(p2, p3); Rotate(p3, p4);

        for(maxn j = i + 1; j < pn; j++)
            if (!gr[j] && (pic[j] == p1 || pic[j] == p2 || pic[j] == p3 || pic[j] == p4)) gr[j] = gn;
    }

    for(maxn i = 0; i < m; i++, std::cout << '\n') for(maxn j = 0; j < n; j++)
        std::cout << map[i][j] + 1 << ' ';
    for(maxn i = 0; i < m; i++, std::cout << '\n') for(maxn j = 0; j < n; j++)
        std::cout << gr[map[i][j]] << ' ';
}


int main() {
    freopen("hinh.inp","r",stdin);

    Prepare();
    Process();
}
