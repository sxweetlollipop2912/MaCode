// AC
// Thuật: TKNP size của robot, sau đó ktra = BFS
//
// BFS: 
// Dùng prefix sum mảng 2d để kiểm tra có ô obscured trong 1 phạm vi nhất định k (mảng T, hàm check),
// và đánh dấu 1 phạm vi đã đc robot quét qua (mảng cv, hàm cover).
//
// Edge case (probably): ô (1, 1) k phải lúc nào cũng trống :v

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 5000001
#define obscured 0
#define X first
#define Y second

typedef long maxn;
typedef std::pair <maxn, maxn> p_t;

maxn m, n, K;
maxn f[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
p_t start;
std::vector <std::vector <bool> > done;
std::vector <std::vector <maxn> > a, T, cv;
std::queue <p_t> bfs;


void Prepare() {
    std::cin >> m >> n >> K;

    a.resize(m + 2);
    std::fill(a.begin(), a.end(), std::vector <maxn>(n + 2, 1));

    done.resize(m + 2);
    std::fill(done.begin(), done.end(), std::vector <bool>(n + 2, false));

    T.resize(m + 2);
    std::fill(T.begin(), T.end(), std::vector <maxn>(n + 2, 0));

    cv.resize(m + 2);
    std::fill(cv.begin(), cv.end(), std::vector <maxn>(n + 2, 0));

    for(maxn i = 0; i < K; i++) {
        maxn x, y;
        std::cin >> x >> y;
        a[x][y] = obscured;
    }

    start = p_t(-1, -1);
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        if (start.X == -1 && a[i][j] != obscured) start = p_t(i, j);

        T[i][j] = T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1] + a[i][j];
    }
}


maxn sum(const std::vector <std::vector <maxn> > &T, const p_t ul, const p_t dr) {
    return T[dr.X][dr.Y] - T[dr.X][ul.Y - 1] - T[ul.X - 1][dr.Y] + T[ul.X - 1][ul.Y - 1];
}


bool check(const p_t ul, const maxn sz) {
    p_t dr = p_t(ul.X + sz - 1, ul.Y + sz - 1);
    return sum(T, ul, dr) == sz * sz;
}


void cover(const p_t ul, const maxn sz, const maxn val) {
    p_t dr = p_t(ul.X + sz - 1, ul.Y + sz - 1);

    cv[ul.X][ul.Y] += val;
    cv[ul.X][dr.Y + 1] -= val;
    cv[dr.X + 1][ul.Y] -= val;
    cv[dr.X + 1][dr.Y + 1] += val;
}


bool BFS(const maxn sz) {
    bfs = std::queue <p_t>();
    std::fill(cv.begin(), cv.end(), std::vector <maxn>(n + 2, 0));
    std::fill(done.begin(), done.end(), std::vector <bool>(n + 2, false));

    if (!check(start, sz)) return 0;
    bfs.push(start);
    done[start.X][start.Y] = true;

    while (!bfs.empty()) {
        p_t cur = bfs.front(); bfs.pop();
        cover(cur, sz, 1);

        for(int i = 0; i < 4; i++) {
            p_t nxt = p_t(cur.X + f[i][0], cur.Y + f[i][1]);
            if (nxt.X <= 0 || nxt.X > m - sz + 1 || nxt.Y <= 0 || nxt.Y > n - sz + 1 || done[nxt.X][nxt.Y]) continue;

            done[nxt.X][nxt.Y] = 1;
            if (!check(nxt, sz)) continue;

            bfs.push(nxt);
        }
    }

    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        cv[i][j] += cv[i - 1][j] + cv[i][j - 1] - cv[i - 1][j - 1];
    }
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        if (a[i][j] != obscured && cv[i][j] == 0) {
            return 0;
        }
    }
    return 1;
}


void Process() {
    maxn l = 1, r = std::min(n, m);

    while (l != r) {
        maxn m = (l + r + 1) / 2;
        if (BFS(m)) l = m;
        else r = m - 1;
    }

    if (BFS(l)) std::cout << l;
    else std::cout << "-1";
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}

