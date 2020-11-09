#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define maxN 1000001

typedef long maxn, maxa;
typedef std::vector <maxn> v_t;

maxn n, res;
maxa a[maxN];
bool done[maxN];
std::map <maxa, v_t> map1, map2;
v_t V;


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) std::cin >> a[i];

    for(maxn i = 0; i < n; i++)
        map1[i - a[i]].push_back(i);

    for(maxn i = n - 1; i >= 0; i--)
        map2[-(a[i] + i)].push_back(i);
}


void Process() {
    res = 0;
    V.push_back(0);

    while (!V.empty()) {
        maxn u = V.back(); V.pop_back();
        done[u] = 1;

        res = std::max(res, u);

        v_t *v = &map1[a[u] + u];
        while (!(*v).empty() && (*v).back() > u) {
            if (!done[(*v).back()]) V.push_back((*v).back());
            (*v).pop_back();
        }

        v = &map2[a[u] - u];
        while (!(*v).empty() && (*v).back() < u) {
            if (!done[(*v).back()]) V.push_back((*v).back());
            (*v).pop_back();
        }
    }

    std::cout << res + 1;
}


int main() {
    freopen("rbech.inp", "r", stdin);
    freopen("rbech.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
