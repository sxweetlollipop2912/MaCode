// not done
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 200002
#define maxA 99999999999999999
#define Sum(l, r) (sum[r] - sum[l - 1])

typedef long maxn;
typedef long long maxa;

maxn n;
maxa M, a[maxN], sum[maxN], f[maxN];


void Prepare() {
    std::cin >> n >> M;
    for (maxn i = 1; i <= n; i++) std::cin >> a[i];

    sum[0] = 0, sum[1] = a[1];
    for (maxn i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];
}


void Process() {
    f[0] = 0;
    for (maxn i = 1; i <= n; i++) {
        maxa mx = a[i]; f[i] = maxA;
        for (maxn j = i; j > 0 && Sum(j, i) <= M; j--) {
            mx = std::max(mx, a[j]);
            f[i] = std::min(f[i], mx + f[j - 1]);
        }
    }
    std::cout << f[n];
}


int main() {
    freopen("main.inp", "r", stdin);
    freopen("main.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}