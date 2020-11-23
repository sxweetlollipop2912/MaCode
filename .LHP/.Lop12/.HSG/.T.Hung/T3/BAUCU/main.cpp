#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxN 4004005
#define maxRC 2005
#define X first
#define Y second
#define num(c) (c.X * N + c.Y)
#define c_t(x) c_t((x) / N, (x) % N)
#define valid(x, y) ((x) >= 0 && (x) < N && (y) >= 0 && (y) < N)

typedef long maxn;
typedef std::pair <maxn, maxn> c_t;

const maxn N = 2000;

maxn B, S, res[2], stp[maxN], f[4][2] = { { -1,0 }{ 1,0 },{ 0,-1 },{ 0,1 } };
maxn l[maxRC], r[maxRC], u[maxRC], d[maxRC];
std::queue <maxn> bfs;


void Prepare() {
    std::cin >> B >> S;

    for(maxn i = 0; i < B; i++) {
        maxn x, y; std::cin >> x >> y;
        x += N / 2, y += N / 2;
        stp[x][y] = -1;
    }
}


void BFS(const c_t st, const maxn S) {
    stp[st.X][st.Y] = 0;
    bfs.push(num(st));

    while (!bfs.empty()) {
        maxn nu = bfs.front(); bfs.pop();
        c_t u = c_t(nu);

        if (stp[nu] > S) return;
        ++res[stp[nu] & 1];

        for(int k = 0; k < 4; k++) {
            c_t v = c_t(u.X + f[k][0], u.Y + f[k][1]);
            maxn nv = num(v);
            if (!valid(v.X, v.Y) || stp[v.X][v.Y] || v == st) continue;

            stp[nv] = stp[nu] + 1;
            bfs.push(nv);
        }
    }
}


void Process() {
    BFS(c_t(N / 2, N / 2), S);

    /// up
    for(maxn j = 0; j <= N; j++) {
        maxn nu = num(c_t(0, j));
        if (stp[nu] <= 0) continue;
        for(maxn j1 = j, cnt = 0; cnt < stp[nu] && j1 <= N; cnt++, j1++) u[j1] = std::max(u[j1], stp[nu] - cnt);
        for(maxn j1 = j, cnt = 0; cnt < stp[nu] && j1 >= 0; cnt++, j1--) u[j1] = std::max(u[j1], stp[nu] - cnt);
        u[N + 1] = std::max(u[N + 1], stp[nu] - (N - j + 1));
        u[N + 2] = std::max(u[N + 2], stp[nu] - j);
    }

    /// down
    for(maxn j = 0; j <= N; j++) {
        maxn nu = num(c_t(N, j));
        if (stp[nu] <= 0) continue;
        for(maxn j1 = j, cnt = 0; cnt < stp[nu] && j1 <= N; cnt++, j1++) d[j1] = std::max(d[j1], stp[nu] - cnt);
        for(maxn j1 = j, cnt = 0; cnt < stp[nu] && j1 >= 0; cnt++, j1--) d[j1] = std::max(d[j1], stp[nu] - cnt);
        u[N + 1] = std::max(u[N + 1], stp[nu] - (N - j + 1));
        u[N + 2] = std::max(u[N + 2], stp[nu] - j);
    }
}
