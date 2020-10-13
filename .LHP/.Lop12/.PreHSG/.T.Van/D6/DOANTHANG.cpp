#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 200001
#define L first
#define R second

typedef int maxa;
typedef long maxn;
typedef std::pair <maxa, maxa> p_t;

maxn n;
maxa res;
p_t a[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i].L >> a[i].R;
    std::sort(a, a + n);
}


void Process() {
    res = 0;

    maxa mxr = -1, curl = -1;
    for(maxn i = 0; i < n; i++) {
        if (a[i].L <= mxr) mxr = std::max(mxr, a[i].R);
        else {
            res += mxr - curl;
            curl = a[i].L, mxr = a[i].R;
        }
    }
    res += mxr - curl;

    std::cout << res;
}


int main() {
    freopen("doanthang.inp", "r", stdin);
    freopen("doanthang.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
