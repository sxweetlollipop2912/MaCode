#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define maxN 1001
#define x first
#define y second
#define MOD 1000000000

typedef int maxn;
typedef long long maxr;
typedef std::pair <maxn, maxn> co_t;

maxn m, n, f[4][2] = { { 2,-1 },{ 2,1 },{ 1,2 },{ -1,2 } };
co_t S, T;
bool done[maxN][maxN];
maxr cnt[maxN][maxN];
std::queue <co_t> bfs;


void Prepare() {
    std::cin >> m >> n >> T.x >> T.y;
    --T.x, --T.y, S.x = S.y = 0;
}


bool check(const maxn cx, const maxn cy) {
    return cx >= 0 && cx < m && cy >= 0 && cy < n;
}


void BFS() {
    done[S.x][S.y] = cnt[S.x][S.y] = 1; bfs.push(S);

    while (!bfs.empty()) {
        maxn cx = bfs.front().x, cy = bfs.front().y; bfs.pop();

        for(int i = 0; i < 4; i++) {
            maxn x1 = cx + f[i][0], y1 = cy + f[i][1];
            if (!check(x1, y1)) continue;

            cnt[x1][y1] = (cnt[x1][y1] + cnt[cx][cy]) % MOD;
            if (done[x1][y1]) continue;
            done[x1][y1] = 1; bfs.push(co_t(x1, y1));
        }
    }
}


void Process() {
    BFS();
    std::cout << cnt[T.x][T.y];
}


int main() {
    //freopen("quanco.inp", "r", stdin);
    //freopen("quanco.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}