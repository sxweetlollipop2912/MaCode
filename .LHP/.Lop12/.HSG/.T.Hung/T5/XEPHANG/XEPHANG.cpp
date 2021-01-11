#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1001
#define maxH 502

typedef long maxn;

maxn H, n, m, root[maxN], sz[maxN], Ngr, fl[maxN], cnt[maxN], cnt_up[maxN], cnt_down[maxN], par[maxN], res[maxN];
bool done[maxN];
std::vector <maxn> ad[maxN], ad2[maxN], V;


maxn Root(maxn x) {
    if (x != root[x]) root[x] = Root(root[x]);
    return root[x];
}


void Prepare() {
    std::cin >> H >> n >> m;
    Ngr = n;

    for(maxn i = 0; i < n; i++) root[i] = i, sz[i] = 1;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; char c;
        std::cin >> u >> c >> v;
        --u, --v;
        u = Root(u), v = Root(v);
        if (c == '<') {
            ad[u].push_back(v);
            ++par[v];
            ad2[u].push_back(v);
            ad2[v].push_back(u);
        }
        else if (u != v) {
            root[v] = u, par[u] += par[v], sz[u] += sz[v], --Ngr;
            while (!ad[v].empty()) {
                ad[u].push_back(ad[v].back());
                ad[v].pop_back();
            }
            while (!ad2[v].empty()) {
                ad2[u].push_back(ad2[v].back());
                ad2[v].pop_back();
            }
        }
    }

    for(maxn u = 0; u < n; u++) {
        for(maxn i = 0; i < ad[u].size(); i++)
            ad[u][i] = Root(ad[u][i]);
        for(maxn i = 0; i < ad2[u].size(); i++)
            ad2[u][i] = Root(ad2[u][i]);
    }
}


maxn DFS(const maxn u, std::vector <maxn> &V) {
    done[u] = 1;
    V.push_back(u);
    for(maxn i = 0; i < ad2[u].size(); i++)
        if (!done[ad2[u][i]]) DFS(ad2[u][i], V);
}


maxn Sum(const maxn u) {
    maxn re = 1;
    for(maxn i = 0; i < ad[u].size(); i++)
        re += Sum(ad[u][i]);
    return re;
}


void Process_gr(const std::vector <maxn> &V) {
    maxn N = V.size(), floor = 0;
    std::fill(fl, fl + n, 0);
    std::fill(cnt, cnt + n, 0);

    std::vector <maxn> vt;
    for(maxn i = 0; i < N; i++) {
        maxn u = V[i];
        if (par[u]) continue;
        vt.push_back(u); fl[u] = 1;
    }

    while (!vt.empty()) {
        maxn u = vt.back(); vt.pop_back();
        floor = std::max(floor, fl[u]);
        ++cnt[fl[u]];
        for(maxn j = 0; j < ad[u].size(); j++) {
            maxn v = ad[u][j];
            fl[v] = std::max(fl[v], fl[u] + 1);
            --par[v];
            if (!par[v]) vt.push_back(v);
        }
    }

    for(maxn i = 0; i < N; i++) {
        maxn u = V[i], sum = Sum(u);
        if (floor == H) res[u] = fl[u];
        else if (N == Ngr && cnt[fl[u]] == 1 && sum - 1 == H - fl[u])
            res[u] = fl[u];
        else if (N == Ngr && cnt[fl[u]] == 1 && N - sum == fl[u] - 1)
            res[u] = fl[u];
        std::cout << "u " << u << ' ' << fl[u] << ' ' << sum << ' ' << res[u] << '\n';
    }
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        maxn u = Root(i);
        if (done[u]) continue;
        V.clear(); DFS(u, V);
        Process_gr(V);
    }

    for(maxn i = 0; i < n; i++) {
        maxn u = Root(i);
        std::cout << res[u] << '\n';
    }
}


int main() {
    freopen("xephang.inp", "r", stdin);

    Prepare();
    Process();
}
