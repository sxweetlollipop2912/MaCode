#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 102
#define maxK 11
#define maxD 4

#define up 0
#define right 1
#define down 2
#define left 3
#define turnR(x) (((x) + 1) % 4)
#define turnL(x) (((x) + 3) % 4)

#define isValid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

#define nextK(k) (((k) + 1) % K)

typedef int maxn, maxk;

struct st_t {
    maxn X, Y;
    maxk K;
    int Dir;

    st_t(maxn x, maxn y, maxk k, int dir) {
        X = x; Y = y;
        K = k;
        Dir = dir;
    }
};

maxn m, n, enx, eny, F[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } }, CNT, res;
maxk K;
char a[maxN][maxN], aK[maxK];
bool done[maxN][maxN][maxK][maxD], f[maxN][maxN][maxK][maxD];


void Prepare() {
    std::cin >> m >> n >> K;

    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) {
        std::cin >> a[i][j];

        CNT += (a[i][j] != '#');
        if (a[i][j] == 'E') {
            enx = i; eny = j;
        }
    }
    for(maxk i = 0; i < K; i++) std::cin >> aK[i];
}


bool DFS(const maxn x, const maxn y, const maxk k, const int dir) {
    if (done[x][y][k][dir]) return f[x][y][k][dir];

    done[x][y][k][dir] = 1;
    f[x][y][k][dir] = 0;

    if (aK[k] == 'F') {
        if (isValid(x + F[dir][0], y + F[dir][1]))
            f[x][y][k][dir] = DFS(x + F[dir][0], y + F[dir][1], nextK(k), dir);
        else
            f[x][y][k][dir] = DFS(x, y, nextK(k), dir);
    }
    if (aK[k] == 'R') {
        f[x][y][k][dir] = DFS(x, y, nextK(k), turnR(dir));
    }
    if (aK[k] == 'L') {
        f[x][y][k][dir] = DFS(x, y, nextK(k), turnL(dir));
    }

    return f[x][y][k][dir];
}


void Process() {
    for(maxk k = 0; k < K; k++) for(int i = 0; i < 4; i++)
        done[enx][eny][k][i] = f[enx][eny][k][i] = 1;

    res = 0;
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) {
        res += DFS(i, j, 0, up);
        //std::cout << i << ' ' << j << ' ' << a[i][j] << ' ' << res << '\n';
    }

    if (res == CNT) std::cout << "YES";
    else std::cout << res;
}


int main() {
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
