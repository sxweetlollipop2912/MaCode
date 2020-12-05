// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define maxN 302
#define maxM 605
#define ofs(x) ((x) + n)
#define U (M1 + M2 * 2 + M4 * 4)

typedef int maxn;
typedef long maxr;

const maxr MOD = 1e9 + 9;

maxn n, MAX, M1, M2, M4;
maxr f[maxN][maxM][maxN], res;


void Prepare() {
    std::cin >> n >> MAX >> M1 >> M2 >> M4;
}


maxr DP(const maxn idx, const maxn m1, const maxn m2, const maxn m4) {
    if ((M1 + m1) < 0 || (M1 + m1) > MAX || (M2 + m2) < 0 || (M2 + m2) > MAX || (m4 + M4) < 0 || (m4 + M4) > MAX) return 0;
    //std::cout << idx << ' ' << m2 << ' ' << m4 << '\n';
    if (idx == n) return 1;

    if (f[idx][ofs(m2)][m4] != -1) return f[idx][ofs(m2)][m4];
    maxr &res = f[idx][ofs(m2)][m4];

    (res = DP(idx + 1, m1 + 1, m2, m4) + DP(idx + 1, m1 - 1, m2 + 1, m4)) %= MOD;
    if (m2 + M2 != 0) (res += DP(idx + 1, m1 - 1, m2 - 1, m4 + 1)) %= MOD;
    else (res += DP(idx + 1, m1 - 3, m2, m4 + 1)) %= MOD;

    return res;
}


void Process() {
    memset(f, -1, sizeof(f));
    res = DP(0, 0, 0, 0);
    std::cout << res;
}


int main() {
    //freopen("icecream.inp", "r", stdin);
    //freopen("icecream.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}