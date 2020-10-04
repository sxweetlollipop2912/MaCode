#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001

typedef long maxn, maxa;

int f[8][2] = { { 1,1 },{ 1,0 },{ 0,1 },{ 0,0 },{ -1,1 },{ -1,0 },{ 1,-1 },{ 0,-1 } }, stf, enf;
maxn n, l_cnt[2], r_cnt[2];
maxa st, en;
std::vector <maxa> V[8];


bool Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        maxn x; maxa a;
        std::cin >> x >> a, --x;
        V[x].push_back(a);

        if (f[x][0] == -1 || f[x][1] == -1) {
            if (f[x][0] == -1) st = a, stf = f[x][1];
            else en = a, enf = f[x][0];
        }
        if (f[x][0] != -1) ++l_cnt[f[x][0]];
        if (f[x][1] != -1) ++r_cnt[f[x][1]];
    }
    std::cout << l_cnt[0] << ' ' << l_cnt[1] << ' ' << r_cnt[0] << ' ' << r_cnt[1] << '\n';

    if (l_cnt[0] != r_cnt[1] || l_cnt[1] != r_cnt[0] || V[4].size() + V[5].size() != 1 || V[6].size() + V[7].size() != 1) return 0;
    //--l_cnt[enf], --r_cnt[stf], --r_cnt[!enf], --l_cnt[!stf];

    for(int i = 0; i < 8; i++) std::sort(V[i].begin(), V[i].end(), std::greater<maxa>());
    return 1;
}


void Process() {
    std::cout << st << ' ' << enf << '\n';

    ++r_cnt[stf];
    for (maxn i = 0, prev = stf; i < n - 3; i++) {
        maxn mn = -1;
        for(int k = 0; k < 4; k++) {
            if (V[k].empty() || f[k][0] == prev || (f[k][1] != enf && r_cnt[f[k][1]] == 1)) continue;
            if (mn == -1 || V[mn].back() > V[k].back())
                mn = k;
        }
        std::cout << mn << ' ' << V[mn].back() << '\n';
        V[mn].pop_back();
        --r_cnt[prev], --l_cnt[f[mn][0]];
        prev = f[mn][1];
    }

    for(int k = 0; k < 4; k++) if (!V[k].empty()) std::cout << V[k].back() << ' ';
    std::cout << en;
}


int main() {
    freopen("puzzle.inp", "r", stdin);

    if (Prepare()) Process();
    else std::cout << -1;
}
