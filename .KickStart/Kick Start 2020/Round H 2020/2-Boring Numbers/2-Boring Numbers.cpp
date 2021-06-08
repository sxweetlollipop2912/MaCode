// 2-Boring Numbers
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 20

typedef int maxn;
typedef long long maxa;

const maxn N = 18;
const maxa INF = 2e18 + 1;

maxa L, R, f[maxN], res;
std::vector <maxn> vL, vR;


void Prepare() {
    std::cin >> L >> R;
    L -= 1;

    for(maxa x = L; x != 0; x /= 10) vL.push_back(x % 10);
    std::reverse(vL.begin(), vL.end());
    for(maxa x = R; x != 0; x /= 10) vR.push_back(x % 10);
    std::reverse(vR.begin(), vR.end());
}


maxa DP(const std::vector <maxn> &v, const maxn pos = 0, const bool equal = true) {
    if (pos == v.size()) return 1;
    maxa res = 0;

    if (equal) {
        maxn lim = equal? v[pos] : 10;
        maxn cnt = 0;
        for(maxn i = 0; i < lim; i++) if (i & 1 != pos & 1) ++cnt;
        
        if (lim & 1 != pos & 1) res = DP(v, pos + 1, true);
        res += cnt * DP(v, pos + 1, false);
    }
    else {
        res = f[v.size() - pos];
    }

    return res;
}


void Process() {
    f[0] = 1;
    for(maxn i = 1; i <= N; i++) f[i] = f[i - 1] * 5;

    res = DP(vR) - DP(vL);
    std::cout << DP(vR) << ' ' << DP(vL) << ' ' << res;
}


int main() {
    Prepare();
    Process();
}