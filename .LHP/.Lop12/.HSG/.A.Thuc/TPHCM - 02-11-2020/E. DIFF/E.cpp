// AC
#include <iostream>
#include <algorithm>

#define maxN 100001

typedef long maxn;
typedef long long maxa;

maxn n, Q, root[maxN];
maxa d[maxN];


void Prepare() {
    std::cin >> n >> Q;
    for(maxn i = 0; i < n; i++) root[i] = i, d[i] = 0;
}


maxn Root(const maxn x) {
    if (x == root[x]) return x;
    maxn rt = Root(root[x]);
    d[x] += d[root[x]];
    return (root[x] = rt);
}


void Process() {
    for(maxn i = 0; i < Q; i++) {
        int opt; maxn x, y;
        std::cin >> opt >> x >> y;
        maxn rtx = Root(x), rty = Root(y);

        if (opt == 1) {
            maxa D; std::cin >> D;
            if (rtx != rty) 
                root[rty] = rtx, d[rty] = d[x] - d[y] + D;
        }
        else {
            if (rtx == rty) std::cout << d[y] - d[x] << '\n';
            else std::cout << "NO INFO\n";
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}