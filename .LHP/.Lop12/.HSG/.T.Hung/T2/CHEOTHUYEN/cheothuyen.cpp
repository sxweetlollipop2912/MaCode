#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 2503
#define maxD 250001
#define fill2D(a, r, c, x) for(maxn i = 0; i <= (r); i++) std::fill(a[i], a[i] + (c) + 1, x)

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxn> p_t;

const maxn N = 2500, INF = 9999;

maxn D, cnt[maxN][maxN], mnR[maxN][maxN], mnC[maxN][maxN], mxR[maxN][maxN], mxC[maxN][maxN];
maxa fu[maxN][maxN], fd[maxN][maxN];
bool isD[maxN][maxN];
std::vector <p_t> vD;


void Prepare() {
    std::cin >> D;

    for(maxn i = 0; i < D; i++) {
        maxn x, y; std::cin >> x >> y;
        isD[x][y] = 1;
        vD.push_back(p_t(x, y));
    }

    for(maxn i = 1; i <= N; i++) for(maxn j = 1; j <= N; j++) {
        cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + isD[i][j];
    }

    fill2D(mnR, N, N, INF);
    fill2D(mnC, N, N, INF);
    for(maxn i = 1; i <= N; i++) for(maxn j = 1; j <= N; j++) {
        mnR[i][j] = std::min(mnR[i - 1][j], mnR[i][j - 1]);
        mnC[i][j] = std::min(mnC[i - 1][j], mnC[i][j - 1]);
        if (isD[i][j]) {
            mnR[i][j] = std::min(mnR[i][j], i);
            mnC[i][j] = std::min(mnC[i][j], j);
        }
    }

    fill2D(mxR, N + 1, N + 1, -INF);
    fill2D(mxC, N + 1, N + 1, -INF);
    for(maxn i = N; i >= 1; i--) for(maxn j = N; j >= 1; j--) {
        mxR[i][j] = std::max(mxR[i + 1][j], mxR[i][j + 1]);
        mxC[i][j] = std::max(mxC[i + 1][j], mxC[i][j + 1]);
        if (isD[i][j]) {
            mxR[i][j] = std::max(mxR[i][j], i);
            mxC[i][j] = std::max(mxC[i][j], j);
        }
    }
}


maxn Count(maxn r1, maxn c1, maxn r2, maxn c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return cnt[r2][c2] - cnt[r1 - 1][c2] - cnt[r2][c1 - 1] + cnt[r1 - 1][c1 - 1];
}


void Process() {
    for(maxn i = 1; i <= N; i++) for(maxn j = N; j >= 1; j--) {
        maxn minR = mnR[i][j - 1], maxC = mxC[i + 1][j];
        if (minR == INF && maxC == -INF) {
            fu[i][j] = isD[i][j]? 2 : 0; 
            continue;
        }
        maxn mi = minR ==  INF? i : minR, 
             mj = maxC == -INF? j : maxC;
        maxn cnt_all = Count(1, j, i, N), 
             cnt_m   = Count(1, mj, mi, N);
        fu[i][j] = (cnt_all - cnt_m) * 2 + fu[mi][mj] + cnt_m;
    }

    for(maxn i = N; i >= 1; i--) for(maxn j = 1; j <= N; j++) {
        maxn maxR = mxR[i][j + 1], minC = mnC[i - 1][j];
        if (maxR == -INF && minC == INF) {
            fd[i][j] = isD[i][j]? 2 : 0;
            continue;
        }
        maxn mi = maxR == -INF? i : maxR, 
             mj = minC ==  INF? j : minC;
        maxn cnt_all = Count(i, 1, N, j), 
             cnt_m   = Count(mi, 1, N, mj);
        fd[i][j] = (cnt_all - cnt_m) * 2 + fd[mi][mj] + cnt_m;
        //std::cout << "fd " << i << ' ' << j << ' ' << fd[i][j] << '\n';
    }

    for(maxn i = 0; i < vD.size(); i++) {
        maxn x = vD[i].first, 
             y = vD[i].second;
        maxa res = fu[x][y] + fd[x][y] - 4 + Count(1, 1, x - 1, y - 1) + Count(x + 1, y + 1, N, N);
        std::cout << res << '\n';
    }
}


int main() {
    freopen("cheothuyen.inp", "r", stdin);
    freopen("cheothuyen.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}