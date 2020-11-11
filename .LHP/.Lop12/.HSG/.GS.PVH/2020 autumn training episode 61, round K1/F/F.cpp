// AC 50/50
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 70001
#define maxA 2001

typedef long maxn, maxa;

maxn n;
maxa A, a[maxN];
bool okl[maxN][maxA], okr[maxN][maxA];
std::vector <maxn> ad[maxN];


bool cmp(const maxn &x, const maxn &y) {
    return a[x] < a[y];
}


void Prepare() {
    std::cin >> n >> A;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];

    for(maxn i = 0; i < n - 1; i++) {
        maxn u, v; std::cin >> u >> v;
        u--, v--;
        ad[u].push_back(v);
    }
    for(maxn i = 0; i < n; i++) std::sort(ad[i].begin(), ad[i].end(), cmp);
}


bool DFS(const maxn u, const maxa L, const maxa R) {
    if (L > R || L > a[u] || R < a[u]) return 0;

    maxn l = 0, m = 0, r = ad[u].size() - 1;
    while (l < ad[u].size() && a[ad[u][l]] < L) ++l;
    while (r >= 0 && a[ad[u][r]] > R) --r;
    for(m = l; m <= r && a[ad[u][m]] < a[u]; m++);


    okl[u][a[u]] = okr[u][a[u]] = 1;

    for(maxn i = m; i <= r; i++) {
        maxn v = ad[u][i];
        maxn Lv = a[u] + 1, Rv = R;
        if (!DFS(v, Lv, Rv)) continue;

        bool connect = 0;
        for(maxa x = Lv; x <= a[v]; x++) {
            if (!okr[u][x - 1] || !okl[v][x]) continue;
            connect = 1; break;
        }
        if (!connect) continue;

        for(maxa x = a[v]; x <= Rv; x++) okr[u][x] |= okr[v][x];
    }

    for(maxn i = m - 1; i >= l; i--) {
        maxn v = ad[u][i];
        maxn Lv = L, Rv = a[u] - 1;
        if (!DFS(v, Lv, Rv)) continue;

        bool connect = 0;
        for(maxa x = a[v]; x <= Rv; x++) {
            if (!okl[u][x + 1] || !okr[v][x]) continue;
            connect = 1; break;
        }
        if (!connect) continue;

        for(maxa x = Lv; x <= a[v]; x++) okl[u][x] |= okl[v][x];
    }

    return 1;
}


void Process() {
    DFS(0, 1, A);

    maxa cntl = 0, cntr = 0;
    for(maxa x = 1; x <= A; x++) cntl += okl[0][x];
    for(maxa x = 1; x <= A; x++) cntr += okr[0][x];

    std::cout << (cntl * cntr);
}


int main() {
    freopen("uzastopni.inp", "r", stdin);
    freopen("uzastopni.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}