// AC
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 13

typedef int maxn;
typedef long long maxa;

maxn n, k;
maxa a[maxN], lmx[maxN], rmx[maxN], lmx1[maxN], rmx1[maxN];


void Prepare() {
    std::cin >> n >> k;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];

    lmx[0] = a[0];
    for(maxn i = 1; i < n; i++) lmx[i] = std::max(lmx[i - 1], a[i]);
    rmx[n - 1] = a[n - 1];
    for(maxn i = n - 2; i >= 0; i--) rmx[i] = std::max(rmx[i + 1], a[i]);
}


maxa Count(const maxa a[], const maxn n) {
    lmx1[0] = a[0];
    for(maxn i = 1; i < n; i++) lmx1[i] = std::max(lmx1[i - 1], a[i]);
    rmx1[n - 1] = a[n - 1];
    for(maxn i = n - 2; i >= 0; i--) rmx1[i] = std::max(rmx1[i + 1], a[i]);

    maxa re = 0;
    for(maxn i = 0; i < n; i++) re += std::min(lmx1[i], rmx1[i]) - a[i];
    return re;
}


maxa Try(const maxn i, const maxn k) {
    if (i == n) return Count(a, n);
    if (lmx[i] != a[i] && rmx[i] != a[i]) return Try(i + 1, k);

    maxa re = 0;
    for(maxn ki = 0; ki <= k; ki++) {
        a[i] += ki;
        re = std::max(re, Try(i + 1, k - ki));
        a[i] -= ki;
    }

    return re;
}


void Process() {
    std::cout << Try(0, k);
}


int main() {
    Prepare();
    Process();
}
