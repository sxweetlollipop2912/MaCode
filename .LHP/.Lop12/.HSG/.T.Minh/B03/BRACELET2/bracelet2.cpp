#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <math.h>
#include <string.h>
#include <vector>

#define maxN 12
#define maxT 9
#define INF 999999999
#define T 8
#define maxB 2049
#define maxC 27
#define C 26
#define BIT ((1 << n) - 1)
#define num(c) ((c) - 'A')
#define Off(b, x) ((b) & (~(1 << (x))))

typedef int maxn;
typedef long maxa;

maxn n, op[8] = { 4,5,6,7,0,1,2,3 };
bool done[maxB][maxT][maxT];
maxa a[maxT], f[maxB][maxT][maxT], res;
std::string br[maxN];
std::vector <maxn> br_st[maxN][maxC];


void Init() {
    memset(done, 0, sizeof(done));
    for(maxn i = 0; i < n; i++) for(int j = 0; j < C; j++)
        br_st[i][j].clear();
}


void Prepare() {
    for(int i = 0; i < T; i++) std::cin >> a[i];

    for(maxn i = 0; i < n; i++) {
        std::cin >> br[i];

        for(maxn j = 0; j < T; j++)
            br_st[i][num(br[i][j])].push_back(j);
    }
}


maxa DP(const maxn b, const char st, const char en) {
    if (b == 0) return a[num(st)];
    if (done[b][num(st)][num(en)]) return f[b][num(st)][num(en)];
    done[b][num(st)][num(en)] = 1;

    maxa *res = &f[b][num(st)][num(en)];
    *res = -INF;

    maxn b1 = b;

    while (b1 != 0) {
        maxn idx = log2(b1);
        b1 -= (1 << idx);

        for(int i = 0; i < br_st[idx][num(en)].size(); i++) {
            maxn j = br_st[idx][num(en)][i];
            if (Off(b, idx) == 0 && br[idx][op[j]] != st) continue;
            *res = std::max(*res, DP(Off(b, idx), st, br[idx][op[j]]) + a[num(br[idx][j])]);
        }
    }

    return *res;
}


void Process() {
    res = -INF;
    for(maxn i = 0; i < n; i++) for(int j = 0; j < T; j++) {
        res = std::max(res, DP(Off(BIT, i), br[i][j], br[i][op[j]]));
    }
    if (res < 0) std::cout << "-1\n";
    else std::cout << res << '\n';
}


int main() {
    freopen("bracelet2.inp", "r", stdin);
    freopen("bracelet2.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (std::cin >> n && n) {
        Init();
        Prepare();
        Process();
    }
}
