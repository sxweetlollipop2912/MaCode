#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 500002
#define maxA 100002
#define maxR 99999999999999999

typedef long maxn, maxa;
typedef long long maxr;

maxn n, cnt[maxA], sum[maxA];
maxa lim;
maxr res;


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        maxa a;
        std::cin >> a;

        cnt[a]++;
        lim = std::max(lim, a);
    }

    for(maxn i = 1; i <= lim; i++) sum[i] = cnt[i] + sum[i - 1];
}


maxr combine3(maxr n) {
    return (n / (double)6)*(n - 1)*(n - 2);
}


maxr combine2(maxr n) {
    return (n / (double)2)*(n - 1);
}


void Process() {
    for(maxn i = 1; i <= lim; i++) {
        res += combine2(cnt[i]) * (maxr)(sum[std::min(i * 2 - 1, lim)] - cnt[i]) + combine3(cnt[i]);
        //std::cout << i << ' ' << res << ' ' << sum[i] << '\n';
    }
}


int main() {
    freopen("tgcan.inp","r",stdin);
    //freopen("tgcan.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
    std::cout << res;
}
