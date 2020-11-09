#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>

#define maxN 1001
#define X first
#define Y second
#define valid(x, y) ((x) > 0 && (x) < m - 1 && (y) >= 0 && (y) < n)

typedef int maxn;
typedef std::pair <maxn, maxn> c_t;

maxn m, n, d[maxN][maxN], f[8][2] = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } };
bool a[maxN][maxN];
std::deque <c_t> dq;


void Prepare() {
    std::cin >> m >> n;
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) {
        char c; std::cin >> c;
        a[i][j] = c == '.';
    }
}


maxn Deque() {
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++)
        d[i][j] = -1;

    for(maxn i = 1; i < m - 1; i++) {
        if (a[i][0]) dq.push_back(c_t(i, 0));
        else dq.push_front(c_t(i, 0));
        d[i][0] = a[i][0];
    }

    while (!dq.empty()) {
        c_t u = dq.front(); dq.pop_front();
        if (u.Y == n - 1) return d[u.X][u.Y];

        for(int k = 0; k < 8; k++) {
            c_t v = c_t(u.X + f[k][0], u.Y + f[k][1]);
            if (!valid(v.X, v.Y) || d[v.X][v.Y] != -1) continue;

            if (a[v.X][v.Y]) dq.push_back(c_t(v.X, v.Y));
            else dq.push_front(c_t(v.X, v.Y));
            d[v.X][v.Y] = d[u.X][u.Y] + a[v.X][v.Y];
        }
    }

    return 0;
}


void Process() {
    std::cout << Deque();
}


int main() {
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
