#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 10002
#define maxK 7
#define K 5

typedef long maxn, maxa;

const maxa maxA = 999999999;

maxn n, prev[maxN];
maxa vK[maxK], a[maxN], f[maxN][maxK];
int col[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 1; i <= K; i++) std::cin >> vK[i];
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
}


bool Check_1(const maxa x1, const maxa x2, const maxa x3) {
    return x1 <= x2 && x2 <= x3;
}
bool Check_2(const maxa x1, const maxa x2, const maxa x3) {
    return x1 >= x2 && x2 >= x3;
}
bool Check_3(const maxa x1, const maxa x2, const maxa x3) {
    return (x1 & 1) == (x2 & 1) && (x2 & 1) == (x3 & 1);
}
bool Check_4(const maxa x1, const maxa x2, const maxa x3) {
    return (x1 & 1) != (x2 & 1) && (x2 & 1) != (x3 & 1);
}
bool Check_5(const maxa x1, const maxa x2, const maxa x3) {
    return (x1 % 4 == 0) && (x2 % 4 == 0) && (x3 % 4 == 0);
}


void Process() {
    for(maxn i = 0; i <= n; i++) std::fill(f[i], f[i] + K + 1, -maxA);
    for(maxn i = 0; i <= 2; i++) f[i][0] = 0, prev[i] = i - 1, col[i] = 0;

    for(maxn i = 3; i <= n; i++) {
        if (Check_1(a[i - 2], a[i - 1], a[i]))
            f[i][1] = std::max(f[i - 1][1] + vK[1], f[i - 3][0] + vK[1] * 3);
        if (Check_2(a[i - 2], a[i - 1], a[i]))
            f[i][2] = std::max(f[i - 1][2] + vK[2], f[i - 3][0] + vK[2] * 3);
        if (Check_3(a[i - 2], a[i - 1], a[i]))
            f[i][3] = std::max(f[i - 1][3] + vK[3], f[i - 3][0] + vK[3] * 3);
        if (Check_4(a[i - 2], a[i - 1], a[i]))
            f[i][4] = std::max(f[i - 1][4] + vK[4], f[i - 3][0] + vK[4] * 3);
        if (Check_5(a[i - 2], a[i - 1], a[i]))
            f[i][5] = std::max(f[i - 1][5] + vK[5], f[i - 3][0] + vK[5] * 3);

        f[i][0] = f[i - 1][0];
        prev[i] = i - 1, col[i] = 0;

        //std::cout <<"i " << i << ' ' << f[i][1] << ' ' << vK[1] << '\n';

        for(int k = 1; k <= K; k++) {
            if (f[i][0] > f[i][k]) continue;
            f[i][0] = f[i][k];
            col[i] = k;
            if (f[i][k] == f[i - 1][k] + vK[k]) prev[i] = prev[i - 1];
            else prev[i] = i - 3;
        }
    }

    std::cout << f[n][0] << '\n';

    for(maxn i = n; i >= 3; i = prev[i]) {
        //std::cout << "i " << i << ' ' << col[i] << ' ' << prev[i] << '\n';
        if (!col[i]) continue;
        std::cout << i << ' ' << prev[i] + 1 << ' ' << col[i] << '\n';
    }
}


int main() {
    //freopen("paint.inp", "r", stdin);
    //freopen("paint.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
