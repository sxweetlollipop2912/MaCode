#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <math.h>

#define maxN 300002
#define INF 9999999999999999

typedef long maxn;
typedef double maxa;

const maxa eps = 1e-8;

maxn n, K;
maxa a[maxN], sum[maxN], Sum;


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i], Sum += a[i];
}


bool Check(const maxa X) {
    sum[0] = 0;
    for(maxn i = 1; i <= n; i++) sum[i] = a[i] - X + sum[i - 1];

    maxa mn = INF;
    for(maxn i = K; i <= n; i++) {
        mn = std::min(mn, sum[i - K]);
        if (sum[i] - mn > eps) return 1;
    }

    return 0;
}


void Process() {
    maxa l = 0, r = Sum;

    int MAX = 25000000 / log2(n);
    for(int i = 0; i <= MAX && (r - l) > eps; i++) {
        maxa m = (l + r) / 2;
        if (Check(m)) l = m;
        else r = m;
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << l;
}


int main() {
    freopen("rate.inp", "r", stdin);
    freopen("rate.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
