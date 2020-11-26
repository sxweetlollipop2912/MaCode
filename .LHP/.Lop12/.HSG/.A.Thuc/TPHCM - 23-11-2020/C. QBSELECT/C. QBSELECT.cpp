// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
 
#define maxN 10002
#define maxB 18
#define B 16
#define isOn(b, x) (((b) >> (x)) & 1)
#define On(b, x) ((b) | ((maxb)1 << (x)))
 
typedef int maxn, maxb;
typedef long long maxa;
 
const maxa INF = 9999999999999999;
 
maxn n;
maxb arr_b[8] = { 0,1,2,4,8,5,9,10 };
maxa a[maxN][4], f[maxN][maxB], res;
 
 
void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < 4; i++) for(maxn j = 1; j <= n; j++) std::cin >> a[j][i];
}
 
 
void Process() {
    for(maxn i = 0; i <= n; i++) std::fill(f[i], f[i] + maxB, -INF);
 
    for(maxn i = 1; i <= n; i++) {
        f[i][0] = *std::max_element(f[i - 1], f[i - 1] + maxB);
        for(maxb i1 = 1; i1 < 8; i1++) for(maxb j1 = 0; j1 < 8; j1++) {
            maxb bi = arr_b[i1], bj = arr_b[j1];
            if ((bi & bj) != 0) continue;
            maxa val = 0;
            for(maxn j = 0; j < 4; j++) if (isOn(bi, j)) val += a[i][j];
            f[i][bi] = std::max(f[i][bi], std::max((maxa)0, f[i - 1][bj]) + val);
        }
    }
 
    res = *std::max_element(f[n], f[n] + maxB);
    std::cout << res;
}
 
 
int main() {
    //freopen("C.inp", "r", stdin);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}