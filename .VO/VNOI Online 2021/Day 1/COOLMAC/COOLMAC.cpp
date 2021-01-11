#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001
#define L first
#define R second

typedef long maxn, maxa;
typedef std::pair <maxa, maxa> p_t;

const maxa INF = 999999999;

maxn n, D;
p_t a[maxN];
maxa t[maxN], Tmin;
std::vector <p_t> st;


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i].L >> a[i].R;

    std::cin >> D; Tmin = INF;
    for(maxn i = 0; i < D; i++) std::cin >> t[i], Tmin = std::min(Tmin, t[i]);

    std::sort(a, a + n);
}


bool Process() {
    st.push_back(p_t(0, Tmin - 1));

    for(maxn i = 0; i < n; i++) {
        if (st.back().R >= a[i].R) continue;
        if (st.back().R + 1 < a[i].L) return 0;
        while (st.size() > 1 && st[st.size() - 2].R + 1 >= a[i].L) st.pop_back();
        st.push_back(a[i]);
    }

    if (st.back().R != 1e5) return 0;
    std::cout << ((maxn)st.size() - (maxn)((st[0].R == Tmin - 1)));
    return 1;
}


int main() {
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    if (!Process()) std::cout << "-1";
}