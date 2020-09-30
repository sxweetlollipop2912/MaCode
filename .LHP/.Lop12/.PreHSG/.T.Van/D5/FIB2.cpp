#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 47

typedef int maxn;
typedef long long maxa;

maxa L[maxN], Cnt[maxN];
maxn n, K;

void Prepare() {
    std::cin >> n >> K;
}


maxa Count(const maxn n, const maxn K) {
    if (L[n]) {
        if (K == L[n]) return Cnt[n];
        else if (K <= L[n - 2]) return Count(n - 2, K);
        else return Cnt[n - 2] + Count(n - 2, K - Cnt[n - 2]);
    }

}


void Process() {
    L[0] = L[1] = Cnt[0] = 1;
}
