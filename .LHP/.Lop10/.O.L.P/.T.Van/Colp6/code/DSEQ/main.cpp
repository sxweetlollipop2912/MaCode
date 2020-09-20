#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100002
#define maxA 1000000001
#define minA -1000000001
#define maxR 1000000000000001
#define minR -1000000000000001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], mn[maxN], mx[maxN], mnv[maxN], mxv[maxN], res;


void Prepare() {
    std::cin >> n >> a[0];

    maxa sum = a[0];
    mn[0] = sum;
    mx[0] = sum;

    for(maxn i = 1; i < n; i++) {
        std::cin >> a[i];

        sum += a[i];
        mn[i] = std::min(mn[i - 1], sum);
        mx[i] = std::max(mx[i - 1], sum);
    }
}


maxa abs(maxa x) {
    return x < 0 ? -x : x;
}


void Process() {
    res = minR;
    maxa sumv = a[n - 1];

    mxv[n - 1] = a[n - 1];
    mnv[n - 1] = a[n - 1];

    for(maxn j = n - 2; j >= 0; j--) {
        sumv += a[j];
        mnv[j] = std::min(mnv[j + 1], sumv);
        mxv[j] = std::max(mxv[j + 1], sumv);
    }

    for(maxn j = 1; j < n; j++) res = std::max(res, std::max(abs(mx[j - 1] - mnv[j]), abs(mxv[j] - mn[j - 1])));

    std::cout << res;
}


int main() {
    freopen("dseq.inp","r",stdin);
    freopen("dseq.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
