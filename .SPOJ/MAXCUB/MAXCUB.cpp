// AC
#include <iostream>
#include <algorithm>

#define maxN 32

typedef int maxn;
typedef long long maxa;

const maxa INF = 1e16;

maxn n;
maxa a[maxN][maxN][maxN], s[maxN][maxN][maxN], res;


void Prepare() {
    std::cin >> n;

    for(maxn i = 1; i <= n; i++) for(maxn j = 1; j <= n; j++) for(maxn k = 1; k <= n; k++) {
        std::cin >> a[i][j][k];
    }

    for(maxn i = 1; i <= n; i++) for(maxn j = 1; j <= n; j++) for(maxn k = 1; k <= n; k++) {
        s[i][j][k] = s[i][j - 1][k] + s[i][j][k - 1] - s[i][j - 1][k - 1] + a[i][j][k];
    }
}


maxa Sum(maxn i, maxn ux, maxn uy, maxn dx, maxn dy) {
    return s[i][dx][dy] - s[i][ux - 1][dy] - s[i][dx][uy - 1] + s[i][ux - 1][uy - 1];
}


void Process() {
    res = -INF;

    for(maxn sz = 1; sz <= n; sz++) for(maxn ux = 1; ux <= n - sz + 1; ux++) for(maxn uy = 1; uy <= n - sz + 1; uy++) {
        maxn dx = ux + sz - 1, dy = uy + sz - 1;

        maxa sum = 0;
        for(maxn i = 0; i < sz; i++) 
            sum += Sum(i, ux, uy, dx, dy);
        for(maxn i = sz; i <= n; i++) {
            sum += Sum(i, ux, uy, dx, dy) - Sum(i - sz, ux, uy, dx, dy);
            res = std::max(res, sum);
        }
    }

    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}