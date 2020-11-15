// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <vector>

#define maxN 1000001
#define X first
#define Y second
#define num(p) (p.X * n + p.Y)
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

typedef long maxn;
typedef std::pair <maxn, maxn> p_t;

const maxn INF = 99999999;

maxn m, n, N, f[8][2] = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } };
maxn d[maxN];
std::vector <std::vector <char> > a;
std::deque <p_t> dq;


void Init() {
    a.clear();
    dq = std::deque <p_t>();
}


void Prepare() {
    N = n * m;
    a.assign(m, std::vector <char> (n, '.'));

    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) {
        std::cin >> a[i][j];
    }
}


bool Push(const p_t &p) {
    if (a[p.X][p.Y] == '@') return 0;
    if (a[p.X][p.Y] == '.') dq.push_back(p);
    else dq.push_front(p);
    return 1;
}


maxn Process() {
    std::fill(d, d + N, INF);

    for(maxn i = 0; i < m; i++) {
        p_t p = p_t(i, 0);
        if (Push(p)) d[num(p)] = (a[p.X][p.Y] == '.');
    }
    for(maxn j = 1; j < n; j++) {
        p_t p = p_t(m - 1, j);
        if (Push(p)) d[num(p)] = (a[p.X][p.Y] == '.');
    }

    while (!dq.empty()) {
        p_t u = dq.front(); dq.pop_front();
        maxn nu = num(u);

        for(int k = 0; k < 8; k++) {
            p_t v = p_t(u.X + f[k][0], u.Y + f[k][1]);
            maxn nv = num(v);

            if (!valid(v.X, v.Y)) {
                if (v.X == -1 || v.Y == n) return d[nu];
                continue;
            }
            if (d[nv] == INF && Push(v)) d[nv] = d[nu] + (a[v.X][v.Y] == '.');
        }
    }
    return -1;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (std::cin >> m >> n && m) {
        Init();
        Prepare();
        std::cout << Process() << '\n';
    }
}