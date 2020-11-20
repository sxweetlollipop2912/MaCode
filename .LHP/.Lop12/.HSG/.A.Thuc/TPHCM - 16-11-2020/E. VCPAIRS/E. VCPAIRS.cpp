// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

#define maxN 100001

typedef long maxn, maxa;
typedef long long maxr;

maxn n, m, c[maxN], root[maxN], sz[maxN];
std::map <maxa, maxn> cnt[maxN];
maxr res;


void Prepare() {
    std::cin >> n >> m;

    for(maxn i = 0; i < n; i++) {
        std::cin >> c[i];
        cnt[i][c[i]] = 1;
        root[i] = i, sz[i] = 1;
    }
}


maxn Root(maxn x) {
    if (x != root[x]) root[x] = Root(root[x]);
    return root[x];
}


maxr Union(maxn x, maxn y) {
    x = Root(x), y = Root(y);
    if (x == y) return 0;

    if (sz[x] < sz[y]) std::swap(x, y);

    maxr re = 0;
    for(std::map <maxa, maxn>::iterator it = cnt[y].begin(); it != cnt[y].end(); it++) {
        maxa color = it->first; maxn cnty = it->second;
        maxn *cntx = &cnt[x][color];
        re += (maxr)(*cntx) * (maxr)cnty;
        (*cntx) += cnty;
    }

    root[y] = x, sz[x] += sz[y];
    return re;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v, --u, --v;
        res += Union(u, v);
        std::cout << res << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}