#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 300001

typedef long maxn;

maxn n, K, par[maxN], mx1[maxN], mx2[maxN], mxout[maxN];
bool done[maxN], has_in[maxN], has_out[maxN];
std::vector <maxn> isK, ad[maxN];
std::queue <maxn> bfs;


void Prepare() {
    std::cin >> n >> K;

    for(maxn i = 0, u; i < K; i++) {
        std::cin >> u, --u;
        isK.push_back(u);
    }

    for(maxn i = 1, u, v; i < n; i++) {
        std::cin >> u >> v; --u; --v;
        ad[u].push_back(v); ad[v].push_back(u);
    }
}


void BFS(const maxn step, bool done[]) {
    bfs = std::queue <maxn>();
    std::fill(done, done + n, 0);
    for(maxn i = 0; i < isK.size(); i++) {
        bfs.push(isK[i]);
        done[isK[i]] = 1;
    }

    for(maxn st = 0, sz = bfs.size(); st < step; st++, sz = bfs.size()) for(maxn i = 0; i < sz; i++) {
        maxn u = bfs.front(); bfs.pop();
        for(maxn ia = 0; ia < ad[u].size(); ia++) {
            maxn v = ad[u][ia];
            if (done[v]) continue;
            done[v] = 1; bfs.push(v);
        }
    }
}


void DFS_IN(const maxn u) {
    has_in[u] = !done[u];
    if (has_in[u]) mx1[u] = 0, mx2[u] = -1;
    else mx1[u] = mx2[u] = -1;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i]; if (par[v] != -1) continue;
        par[v] = u; DFS_IN(v);
        if (!has_in[v]) continue;
        has_in[u] = 1;
        if (mx1[v] + 1 >= mx1[u]) mx2[u] = mx1[u], mx1[u] = mx1[v] + 1;
        else if (mx1[v] + 1 > mx2[u]) mx2[u] = mx1[v] + 1;
    }
}


void DFS_OUT(const maxn u) {
    mxout[u] = has_out[u] = 0;
    if (par[u] != u) {
        if (has_out[par[u]]) /// out cua par
            mxout[u] = std::max(mxout[u], mxout[par[u]] + 1), has_out[u] = 1;
        if (has_in[par[u]] && (!has_in[u] || mx1[par[u]] != mx1[u] + 1)) /// mx1 cua par
            mxout[u] = std::max(mxout[u], mx1[par[u]] + 1), has_out[u] = 1;
        else if (has_in[par[u]] && has_in[u] && mx1[par[u]] == mx1[u] + 1 && mx2[par[u]] != -1) /// mx2 cua par
            mxout[u] = std::max(mxout[u], mx2[par[u]] + 1), has_out[u] = 1;
    }

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i]; if (par[u] == v) continue;
        DFS_OUT(v);
    }
}


bool Check(const maxn step) {
    BFS(step, done);
    std::fill(par, par + n, -1);
    par[0] = 0;
    DFS_IN(0); DFS_OUT(0);
    //if (step == 2) for(maxn u = 0; u < n; u++) std::cout << u + 1 << ' ' << mx1[u] << ' ' << mx2[u] << ' ' << mxout[u] << '\n';
    for(maxn u = 0; u < n; u++) if (std::max(mx1[u], mxout[u]) <= step) return 1;
    return 0;
}


void Process() {
    maxn l = 0, r = n;
    while (l != r) {
        maxn m = (l + r) / 2;
        if (Check(m)) r = m;
        else l = m + 1;
    }
    std::cout << l;
}


int main() {
    freopen("business.inp", "r", stdin);
    freopen("business.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}

