#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 100001

typedef long maxn;
typedef long long maxa;

maxn n, st, par[maxN];
maxa a[maxN], sum[maxN], left[maxN];
std::vector <maxn> ad[maxN];
std::priority_queue <maxa, std::vector <maxa>> pq;


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    std::cin >> st; --st;
    ++a[st];

    std::fill(par, par + n, -1);
}


void DFS(const maxn u) {
    --a[u];
    sum[u] = 1, left[u] = a[u];
    
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != -1) continue;
        par[v] = u; DFS(v);
    }

    pq = std::priority_queue <maxa, std::vector <maxa>>();
    maxa sum_left = 0;
    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (par[v] != u) continue;
        pq.push(sum[v]);
        sum_left += left[v];
    }

    for(; a[u] != 0 && !pq.empty(); --a[u]) {
        sum[u] += pq.top() + 1; pq.pop();
    }

    sum[u] += std::min(a[u], sum_left) * 2;
    left[u] = std::max(a[u] - sum_left, (maxa)0);
}


void Process() {
    par[st] = st;
    DFS(st);
    std::cout << sum[st] - 1;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}