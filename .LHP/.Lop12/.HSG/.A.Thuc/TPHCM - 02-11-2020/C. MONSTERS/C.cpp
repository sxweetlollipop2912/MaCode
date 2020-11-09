// AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 1001
#define maxA 1000001
#define X first
#define Y second
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)

typedef int maxn;
typedef std::pair <maxn, maxn> c_t;

maxn m, n, dA[maxN][maxN], dM[maxN][maxN], f[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } }, res;
bool map[maxN][maxN];
std::vector <c_t> M, A;
std::queue <c_t> bfs;


void Prepare() {
    std::cin >> m >> n;
    
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++) {
        char c; std::cin >> c;
        map[i][j] = c != '#';
        if (c == 'M') M.push_back(c_t(i, j));
        if (c == 'A') A.push_back(c_t(i, j));
    }
}


maxn BFS(const std::vector <c_t> &st, maxn (&d)[maxN][maxN], const bool isA) {
    for(maxn i = 0; i < m; i++) for(maxn j = 0; j < n; j++)
        d[i][j] = maxA;
    bfs = std::queue <c_t>();

    for(maxn i = 0; i < st.size(); i++) {
        maxn x = st[i].X, y = st[i].Y;
        d[x][y] = 0;
        bfs.push(c_t(x, y));
    }

    while (!bfs.empty()) {
        c_t u = bfs.front(); bfs.pop();

        for(int k = 0; k < 4; k++) {
            c_t v = c_t(u.X + f[k][0], u.Y + f[k][1]);

            if (!valid(v.X, v.Y)) {
                if (isA) return d[u.X][u.Y];
                continue;
            }
            if (d[v.X][v.Y] != maxA || !map[v.X][v.Y]) continue;
            if (isA && d[u.X][u.Y] + 1 >= dM[v.X][v.Y]) continue;

            d[v.X][v.Y] = d[u.X][u.Y] + 1;
            bfs.push(c_t(v.X, v.Y));
        }
    }

    return -1;
}


void Process() {
    BFS(M, dM, false);
    res = BFS(A, dA, true);

    if (res == -1) std::cout << "NO";
    else std::cout << "YES\n" << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}