// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define maxN 1002
#define maxN2 2002

typedef int maxn;

maxn m, n, f1[maxN][maxN], f2[maxN][maxN], f3[maxN][maxN], f4[maxN][maxN], cnt[maxN2][maxN2];
maxn res_x, res_y, res_R, res_cnt;
bool a[maxN][maxN];


void Prepare() {
    std::cin >> m >> n;
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        char c; std::cin >> c;
        a[i][j] = (c == '*');
    }
}


void CalR() {
    memset(f1, 0, sizeof(f1));
    for(maxn i = 2; i < m; i++) for(maxn j = 2; j < n; j++) {
        if (a[i][j] && (a[i - 1][j] | a[i][j - 1])) continue;
        f1[i][j] = std::min(f1[i - 1][j], f1[i][j - 1]) + 1;
    }
    memset(f2, 0, sizeof(f2));
    for(maxn i = 2; i < m; i++) for(maxn j = n - 1; j > 1; j--) {
        if (a[i][j] && (a[i - 1][j] | a[i][j + 1])) continue;
        f2[i][j] = std::min(f2[i - 1][j], f2[i][j + 1]) + 1;
    }
    memset(f3, 0, sizeof(f3));
    for(maxn i = m - 1; i > 1; i--) for(maxn j = 2; j < n; j++) {
        if (a[i][j] && (a[i + 1][j] | a[i][j - 1])) continue;
        f3[i][j] = std::min(f3[i + 1][j], f3[i][j - 1]) + 1;
    }
    memset(f4, 0, sizeof(f4));
    for(maxn i = m - 1; i > 1; i--) for(maxn j = n - 1; j > 1; j--) {
        if (a[i][j] && (a[i + 1][j] | a[i][j + 1])) continue;
        f4[i][j] = std::min(f4[i + 1][j], f4[i][j + 1]) + 1;
    }
}


void CalCnt() {
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) 
        cnt[i + j][i - j + n] = a[i][j];
    for(maxn i = 1; i <= m + n; i++) for(maxn j = 1; j <= m + n; j++)
        cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
}


maxn Count(const maxn x, const maxn y, const maxn R) {
    if (x <= R) return 0;
    maxn x1 = x - R + y, y1 = x - R - y + n, x2 = x + R + y, y2 = x + R - y + n;
    return cnt[x2][y2] - cnt[x1 - 1][y2]  - cnt[x2][y1 - 1] + cnt[x1 - 1][y1 - 1];
}


void Process() {
    CalR(); CalCnt();

    res_cnt = 0;
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        maxn R = std::min(f1[i][j], std::min(f2[i][j], std::min(f3[i][j], f4[i][j])));
        maxn count = Count(i, j, R);
        if (count <= res_cnt) continue;
        res_cnt = count, res_x = i, res_y = j, res_R = R;
    }

    std::cout << res_cnt << ' ' << res_x << ' ' << res_y << ' ' << res_R << '\n';
}


int main() {
    //freopen("rbull.inp", "r", stdin);
    //freopen("rbull.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}