#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 1003
#define abs(x) ((x) < 0? -(x) : (x))
#define dist(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))

typedef long maxn;

maxn m, n, f[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } }, res_cnt;
bool a[maxN][maxN];


void Prepare() {
    std::cin >> m >> n;

    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        char c; std::cin >> c;
        a[i][j] = c == '*';
    }
}


bool Check(const maxn x, const maxn y, const maxn R) {
    if (R >= x || R >= y || R > m - x || R > n - y) return 0;

    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        if (dist(i, j, x, y) > R || !a[i][j]) continue;
        for(int k = 0; k < 4; k++) {
            maxn ik = i + f[k][0], jk = j + f[k][1];
            if (dist(ik, jk, x, y) > R) continue;
            if (a[ik][jk]) return 0;
        }
    }
    return 1;
}


maxn Sum(const maxn x, const maxn y, const maxn R) {
    if (R >= x || R >= y || R > m - x || R > n - y) return 0;
    maxn sum = 0;

    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        if (dist(i, j, x, y) > R || !a[i][j]) continue;
        sum += a[i][j];
    }
    return sum;
}


void Process() {
    res_cnt = 0;
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) for(maxn R = 0; R < i; R++)
        if (Check(i, j, R)) res_cnt = std::max(res_cnt, Sum(i, j, R));
    std::cout << res_cnt;
}


int main() {
    freopen("rbull.inp", "r", stdin);
    freopen("rbull.ans", "w", stdout);

    Prepare();
    Process();
}
