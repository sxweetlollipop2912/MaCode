#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 47
#define N 45

typedef int maxn;
typedef long long maxa;

maxa L[maxN], Cnt[maxN];
maxn n, K;

void Prepare() {
    std::cin >> n >> K;
}


maxa Count(const maxn n, const maxn K) {
    if (K <= 0) return 0;
    if (K >= L[n]) return Cnt[n];
    return Count(n - 2, K) + Count(n - 1, K - L[n - 2]);
}


void Process() {
    L[0] = L[1] = Cnt[0] = 1;
    for (maxn i = 2; i <= N; i++) 
        L[i] = L[i - 1] + L[i - 2],
        Cnt[i] = Cnt[i - 2] + Cnt[i - 1];

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        std::cout << Count(n, K) << '\n';
    }
}


int main() {
    freopen("fib2.inp", "r", stdin);
    freopen("fib2.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Process();
}
