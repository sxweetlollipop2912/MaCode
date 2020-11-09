// AC
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define maxN 10002

typedef int maxn;
typedef long maxa;

maxn n, root[maxN], d[maxN];
maxa m, L[maxN], R[maxN];
bool st[maxN];
std::vector <maxa> V;


void Prepare() {
    std::cin >> m >> n;

    for(maxn i = 0; i < n; i++) {
        std::string s;
        std::cin >> L[i] >> R[i] >> s;
        st[i] = s[0] == 'o';
    }
}


maxn Root(const maxn x) {
    maxn rt = root[x] == x ? x : Root(root[x]);
    d[x] ^= d[root[x]];
    return (root[x] = rt);
}


maxn Process() {
    for(maxn i = 0; i < n; i++) {
        V.push_back(L[i] - 1);
        V.push_back(R[i]);
    }
    std::sort(V.begin(), V.end());
    V.resize(std::unique(V.begin(), V.end()) - V.begin());

    for(maxn i = 0; i < V.size(); i++) 
        root[i] = i, d[i] = 0;

    for(maxn i = 0; i < n; i++) {
        maxn l = std::lower_bound(V.begin(), V.end(), L[i] - 1) - V.begin();
        maxn r = std::lower_bound(V.begin(), V.end(), R[i]) - V.begin();
        maxn lp = Root(l), rp = Root(r);

        if (lp == rp) {
            if (d[l] ^ d[r] != st[i]) return i;
        }
        else {
            d[lp] = st[i] ^ d[l] ^ d[r];
            root[lp] = rp;
        }
    }

    return n;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process();
}
