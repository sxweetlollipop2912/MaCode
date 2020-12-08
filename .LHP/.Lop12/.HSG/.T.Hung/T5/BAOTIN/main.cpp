#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>

#define maxN 100001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa K, a[maxN];


void Prepare() {
    double x;
    std::cin >> x >> n;
    K = round(x * 1000);

    for(maxn i = 0; i < n; i++) {
        std::cin >> x;
        a[i] = round(x * 1000);
    }
    std::sort(a, a + n);
}


bool Check(const maxa L) {
    maxa prev = L;
    for(maxn i = 0; i < n; i++) {
        maxa pos = std::min(a[i], prev + K);
        if (a[i] - pos > L) return 0;
        prev = pos + (L - (a[i] - pos));
    }
    return 1;
}


void Process() {
    maxa l = 0, r = 1e15 + 1;
    while (l != r) {
        maxa m = (l + r) / 2;
        if (Check(m)) r = m;
        else l = m + 1;
    }

    std::cout << std::fixed; std::cout << std::setprecision(3);
    std::cout << (l / (double)1000);
}


int main() {
    freopen("baotin.inp", "r", stdin);
    freopen("baotin.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
