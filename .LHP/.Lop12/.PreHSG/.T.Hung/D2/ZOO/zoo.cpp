#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>

#define maxN 1001
#define maxMN 1000001
#define X first
#define Y second
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

typedef int maxn;
typedef std::string str;
typedef std::pair <maxn, maxn> co_t;

maxn m, n, f[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } }, res;
bool done[maxN][maxN];
str a[maxN];
std::queue <co_t> bfs[2];


void Prepare() {
    std::cin >> m >> n;

    std::cin.ignore();
    for(maxn i = 0; i < m; i++) std::getline(std::cin, a[i]);
}


void BFS() {
    bool p = 0;

    bfs[p].push(co_t(0,0));

    while (!bfs[p].empty() || !bfs[!p].empty()) {
        ++res;
        while (!bfs[p].empty()) {
            co_t u = bfs[p].front(); bfs[p].pop();

            for(int k = 0; k < 4; k++) {
                co_t v = co_t(u.X + f[k][0], u.Y + f[k][1]);
                if (!valid(v.X, v.Y) || done[v.X][v.Y] || a[v.X][v.Y] == '*') continue;

                if (a[v.X][v.Y] == a[u.X][u.Y]) bfs[p].push(v);
                else bfs[!p].push(v);

                done[v.X][v.Y] = 1;
            }
        }
        p = !p;
    }
}


void Process() {
    BFS();
    std::cout << res;
}


int main() {
    freopen("zoo.inp", "r", stdin);
    freopen("zoo.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
