#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 200001
#define L first
#define R second
#define S(d) (2 * (d) * (d))

typedef long long maxa;
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

    maxa mxr = -1;
    for(maxn i = 0; i < n; i++) {
        if (a[i].R <= mxr) continue;
        if (a[i].L <= mxr)
            res = res - S(mxr - a[i].L) + S(a[i].R - a[i].L);
        else
            res += S(a[i].R - a[i].L);
        mxr = a[i].R;
    }

    std::cout << res;
}


int main() {
    freopen("rocky.inp", "r", stdin);
    freopen("rocky.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
