#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 700001
#define maxC 27
#define C 26
#define num(c) ((c) - 'a')
#define fi(i) num(a[i][0])
#define en(i) num(a[i][a[i].size() - 1])

typedef long maxn;
typedef std::string str;

maxn n, f[maxC][maxC], res;
str a[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
    f[fi(0)][en(0)] = a[0].size();

    for(maxn i = 1; i < n; i++) {
        for(int c = 0; c < C; c++) {
            if (!f[c][fi(i)]) continue;
            f[c][en(i)] = std::max(f[c][en(i)], f[c][fi(i)] + (maxn)a[i].size());
        }
        f[fi(i)][en(i)] = std::max(f[fi(i)][en(i)], (maxn)a[i].size());
    }

    res = 0;
    for(int c = 0; c < C; c++)
        if (f[c][c]) res = std::max(res, f[c][c]);
    std::cout << res;
}


int main() {
    freopen("puzzles.inp", "r", stdin);
    freopen("puzzles.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
