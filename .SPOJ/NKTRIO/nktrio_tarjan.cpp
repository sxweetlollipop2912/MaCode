#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxN 1001

typedef long maxn;

maxn n, par[maxN], low[maxN], num[maxN], cmp[maxN], del[maxN], CNT;
bool a[maxN][maxN];
std::vector <maxn> ad[maxN], st;


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < n; j++) {
        std::cin >> a[i][j];
        if (a[i][j]) ad[i].push_back(j);
    }
}


void Result(const maxn u) {
    for(maxn v = 0; v < n; v++) {
        if (!a[v][u]) continue;
        if (cmp[v] != cmp[u] || par[v] == u || cmp[par[v]] != cmp[u]) continue;
        std::cout << u + 1 << ' ' << par[v] + 1 << ' ' << v + 1;
        return;
    }
}


bool Tarjan(const maxn u) {
    num[u] = low[u] = ++CNT;
    st.push_back(u);

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i];
        if (del[v]) continue;

        if (!num[v]) {
            par[v] = u;
            if (Tarjan(v)) return 1;
            low[u] = std::min(low[u], low[v]);
        }
        else if (par[u] != v)
            low[u] = std::min(low[u], num[v]);
    }

    if (num[u] != low[u]) return 0;

    maxn cnt = 0;
    for(maxn v = st.back(); v != u; v = st.back()) {
        cmp[v] = num[u], del[v] = 1;
        ++cnt;
        st.pop_back();
    }
    cmp[u] = num[u], del[u] = 1, ++cnt;

    if (cnt < 3) return 0;
    Result(u); return 1;
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        if (!num[i] && Tarjan(i)) return;
    }
    std::cout << "-1 -1 -1";
}


int main() {
    //freopen("D.inp", "r", stdin);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
