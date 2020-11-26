// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define maxN 100002

typedef long maxn;

const maxn N = 100000;

maxn n, m, f[maxN];
std::vector <maxn> ad[maxN], V, vertice;
std::queue <maxn> bfs;


maxn A(const maxn B) {
    maxn idx = std::lower_bound(V.begin(), V.end(), B - 4 + 1) - V.begin();
    return B - (3 + 2 * idx);
}


void Prepare() {
    std::cin >> n >> m;

    V.push_back(2);
    for(maxn i = 1, x = 2; V.back() < N; i++, x += !(i & 1)) V.push_back(V.back() + x);

    for(maxn i = 1; i <= N; i++) {
        if (i != N) ad[i].push_back(i + 1);
        if (i != 1) ad[i].push_back(i - 1);
    }
    for(maxn i = 0; i < m; i++) {
        maxn v; std::cin >> v;
        maxn u = A(v);
        ad[u].push_back(v);
        vertice.push_back(u); vertice.push_back(v);
    }
}


maxn BFS(const maxn st, const maxn en) {
    std::fill(f, f + maxN, -1);
    bfs = std::queue <maxn>();

    f[st] = 0; bfs.push(st);

    while (!bfs.empty() && bfs.front() != en) {
        maxn u = bfs.front(); bfs.pop();

        for(maxn i = 0; i < ad[u].size(); i++) {
            maxn v = ad[u][i];
            if (f[v] != -1) continue;
            f[v] = f[u] + 1;
            bfs.push(v);
        }
    }

    return f[en];
}


void Process() {
    std::cout << BFS(1, n);
}


int main() {
    freopen("vuotnguc.inp", "r", stdin);
    //freopen("vuotnguc.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
