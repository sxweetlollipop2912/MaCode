#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define maxN 200001
#define row(x) (x)
#define col(x) ((x) + n)
#define isRow(x) ((x) < n)
#define N (2 * n)

typedef long maxn;
typedef std::pair <maxn, maxn> c_t;

maxn n, m;
std::set <maxn> ad[maxN];
std::map <c_t, char> res;
c_t res_c[maxN];


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < m; i++) {
        maxn x, y;
        std::cin >> x >> y, --x, --y, x = row(x), y = col(y);
        ad[x].insert(y);
        ad[y].insert(x);
        res_c[i] = c_t(x, y);
    }
}


void Euler(const maxn u, const maxn prev = N) {
    while (!ad[u].empty()) {
        maxn v = *ad[u].begin();
        ad[u].erase(v); ad[v].erase(u);
        Euler(v, u);
    }

    maxn x = u, y = prev;
    if (!isRow(x)) std::swap(x, y);
    res[c_t(x, y)] = x == u? 'W' : 'M';
}


bool Process() {
    for(maxn i = 0; i < N; i++) if (ad[i].size() & 1) {
        ad[i].insert(N);
        ad[N].insert(i);
    }
    Euler(N);
    for(maxn i = 0; i < N; i++) if (ad[i].size()) Euler(i);

    for(maxn i = 0; i < m; i++) if (res.find(res_c[i]) == res.end()) return 0;
    for(maxn i = 0; i < m; i++) std::cout << res[res_c[i]];
    return 1;
}


int main() {
    freopen("mienphi.inp", "r", stdin);
    freopen("mienphi.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    if (!Process()) std::cout << "Impossible";
}
