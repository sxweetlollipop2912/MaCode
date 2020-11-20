// AC 50/50
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 70001
#define maxM 2001

typedef long maxn;

maxn n, m, a[maxN];
bool okl[maxN][maxM], okr[maxN][maxM];
std::vector <maxn> child[maxN];


bool cmp(const maxn &x, const maxn &y) {
    return a[x] < a[y];
}


void Prepare() {
    std::cin >> n >> m;
    for(maxn i = 0; i < n; i++) std::cin >> a[i], --a[i];

    for(maxn i = 1; i < n; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        child[u].push_back(v);
    }
    
    for(maxn i = 0; i < n; i++) std::sort(child[i].begin(), child[i].end(), cmp);
}


void DFS(const maxn u, const maxn L, const maxn R) {
    okl[u][a[u]] = okr[u][a[u]] = 1;

    maxn m;
    for(m = 0; m < child[u].size() && a[child[u][m]] <= a[u]; m++);

    for(maxn i = m - 1; i >= 0; i--) {
        maxn v = child[u][i];
        DFS(v, L, a[u] - 1);

        maxn x;
        for(x = L; x < a[u] && (!okr[v][x] || !okl[u][x + 1]); x++);
        if (x == a[u]) continue;
        for(x = L; x < a[u]; x++) okl[u][x] |= okl[v][x];
    }

    for(maxn i = m; i < child[u].size(); i++) {
        maxn v = child[u][i];
        DFS(v, a[u] + 1, R);
        
        maxn x;
        for(x = a[u] + 1; x <= R && (!okl[v][x] || !okr[u][x - 1]); x++);
        if (x > R) continue;
        for(x = a[u] + 1; x <= R; x++) okr[u][x] |= okr[v][x];
    }
}


void Process() {
    DFS(0, 0, m - 1);
    maxn cntl = 0, cntr = 0;
    for(maxn i = 0; i < m; i++) cntl += okl[0][i], cntr += okr[0][i];
    std::cout << cntl * cntr;
}


int main() {
    freopen("uzastopni.inp", "r", stdin);
    freopen("uzastopni.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}