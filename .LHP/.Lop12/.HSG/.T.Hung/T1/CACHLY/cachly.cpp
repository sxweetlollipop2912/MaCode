#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1000001
#define maxM 102
#define maxK 502
#define INF 9999999999999999
#define S(x) (((x) + 1) * (x) / 2)

typedef long long maxn;

maxn n, K, m, cnt[maxM], res, f[maxM][maxK];


void Prepare() {
    std::cin >> n >> m >> K;

    for(maxn i = 1; i <= n; i++) {
        maxn r; std::cin >> r;
        ++cnt[r];
    }
}


void Process() {
    for(maxn i = 1; i <= m; i++)
        f[i][0] = f[i - 1][0] + S(cnt[i]);

    for(maxn i = 1; i <= m; i++) for(maxn k = 1; k <= K; k++) {
        f[i][k] = std::min(f[i][k - 1], f[i - 1][k] + S(cnt[i]));
        for(maxn j = 1; j <= k; j++) {
            maxn x = (j + 1) * S(cnt[i] / (j + 1)) + ((cnt[i] / (j + 1)) + 1) * (cnt[i] % (j + 1));
            f[i][k] = std::min(f[i][k], f[i - 1][k - j] + x);
        }
    }

    std::cout << f[m][K];
}


int main() {
    //freopen("cachly.inp", "r", stdin);
    //freopen("cachly.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
