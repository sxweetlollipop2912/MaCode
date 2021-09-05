// undone
#include <iostream>
#include <vector>
#include <algorithm>

#define NO_PATH 0
#define ONE_PATH 1
#define FINITE_PATH 2
#define INF_PATH -1

typedef long maxn;
typedef int type_t;

maxn n, m;
std::vector <type_t> type;
std::vector <maxn> low, cnt;
std::vector <std::vector <maxn> > ad;


void Prepare() {
    std::cin >> n >> m;

    ad.assign(n, std::vector <maxn>());
    type.assign(n, NO_PATH);
    low.assign(n, 0);
    cnt.assign(n, 0);

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[v].push_back(u);
    }
}


void DFS(const maxn u, maxn& CNT, std::vector <maxn>& stack) {
    cnt[u] = low[u] = ++CNT;
    type[u] = 0;
    stack.push_back(u);

    for(maxn v : ad[u]) {
        if (u == v) type[u] == INF_PATH;
        if (cnt[v] == -1) continue;

        if (cnt[v]) low[u] = std::min(low[u], cnt[v]);
        else {
            DFS(v, CNT, stack);
            low[u] = std::min(low[u], low[v]);
        }

        if (type[v] == INF_PATH)
            type[u] = INF_PATH;
        if (type[u] != INF_PATH)
            type[u] = std::min(type[u] + type[v], 2);
    }
    if (u == 0 && type[u] != INF_PATH) type[u] = ONE_PATH;

    if (cnt[u] != low[u]) return;

    for(maxn v = stack.back();; cnt[v] = -1, type[v] = INF_PATH) {
        stack.pop_back();
        if (v == u) break;
    }
}


void Process() {
    type[0] = ONE_PATH;

    for(maxn i = 0; i < n; i++) {
        if (cnt[i]) continue;
        maxn CNT = 0;
        std::vector <maxn> stack;
        DFS(i, CNT, stack);
    }

    for(maxn i = 0; i < n; i++) {
        std::cout << type[i] << ' ';
    }
}


int main() {
    Prepare();
    Process();
}