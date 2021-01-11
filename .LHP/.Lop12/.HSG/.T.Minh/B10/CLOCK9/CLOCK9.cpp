/// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

#define maxN 10
#define maxA 4
#define maxB 262146
#define cw(x) (((x) + 1) % 4)
#define ccw(x) (((x) + 4 - 1) % 4)

typedef int maxn;
typedef std::vector <maxn> v_t;
typedef long st_t;

const maxn mov[9][5] = { { 0,1,3,4,-1 }, { 0,1,2,-1,-1 },{ 1,2,4,5,-1 },{ 0,3,6,-1,-1 },{ 1,3,4,5,7 },{ 2,5,8,-1,-1 },{ 3,4,6,7,-1 },{ 6,7,8,-1,-1 },{ 4,5,7,8,-1 } };
const maxn N = 9;

st_t st, en;
v_t a;
//maxn f[maxA][maxA][maxA][maxA][maxA][maxA][maxA][maxA][maxA];
maxn f[maxB];
st_t prev[maxB];
std::queue <st_t> bfs;
std::vector <maxn> res;


st_t toSt(const v_t &v) {
    st_t re = 0;
    for(maxn i = 0, b = 0; i < v.size(); i++, b += 2) re += (v[i] << b);
    return re;
}


void Prepare() {
    st = en = 0; a.assign(N, 0);
    for(maxn i = 0; i < N; i++) std::cin >> a[i];//, st[i] = (st[i] / 3) % 4;
    /*for(maxn i = 0; i < N; i++) {
        char c; std::cin >> c;
        st[i] = c - '0';
    }*/
    st = toSt(a);
}


void Turn(st_t &st, const maxn mov_id) {
    for(maxn i = 0; i < 5; i++) {
        if (mov[mov_id][i] == -1) continue;
        maxn idx = mov[mov_id][i] * 2;
        maxn x = (st >> idx) % 4; st -= (x << idx); x = cw(x); st += (x << idx);
    }
}
void Reverse(st_t &st, const maxn mov_id) {
    for(maxn i = 0; i < 5; i++) {
        if (mov[mov_id][i] == -1) continue;
        maxn idx = mov[mov_id][i] * 2;
        maxn x = (st >> idx) % 4; st -= (x << idx); x = ccw(x); st += (x << idx);
    }
}


bool BFS(const st_t &st, const st_t &en) {
    bfs = std::queue <st_t>();
    memset(f, -1, sizeof(f));

    f[st] = -2;
    bfs.push(st);

    while (!bfs.empty()) {
        st_t u = bfs.front(); bfs.pop();
        /*std::cout << f(u) << '\n';
        for(maxn i = 0; i < N; i++) std::cout << u[i] << ' ';
        std::cout << '\n';*/
        if (u == en) return 1;

        for(int k = std::max(f[u], 0); k < 9; k++) {
            st_t v = u; Turn(v, k);
            if (f[v] != -1) continue;
            f[v] = k; prev[v] = u;
            bfs.push(v);
        }
    }
    return 0;
}


void Process() {
    BFS(st, en);

    res.clear();
    for(st_t cur = en; cur != st; cur = prev[cur]) {
        res.push_back(f[cur]);
    }
    std::reverse(res.begin(), res.end());
    for(maxn i = 0; i < res.size(); i++) std::cout << res[i] + 1 << ' ';
    //std::cout << res.size();
}


int main() {
    freopen("clock9.inp", "r", stdin);
    freopen("clock9.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
