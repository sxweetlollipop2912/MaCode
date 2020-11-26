// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
 
#define maxN 103
#define maxB 10
#define B 8
#define isOn(b, x) (((b) >> (x)) & 1)
#define On(b, x) ((b) | ((maxb)1 << (x)))
 
typedef int maxn, maxb;
typedef long long maxa;
 
maxn n, block[maxN], mx[maxN][maxB][maxB];
maxa cnt[maxN][maxB][maxB];
bool done[maxN][maxB][maxB];
 
 
void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> block[i];
}
 
 
bool valid(const maxb b1, const maxb b2, const maxn idx) {
    if (idx == 0 && (isOn(b2, 1) || isOn(b1, 2))) return 0;
    if (idx == 1 && (isOn(b2, 0) || isOn(b2, 2))) return 0;
    if (idx == 2 && (isOn(b2, 1) || isOn(b1, 0))) return 0;
    return 1;
}
 
 
maxa DP(const maxn idx, const maxb b1, const maxb b2) {
    if (idx == n) return 0;
    maxn &re = mx[idx][b1][b2];
    maxa &re_cnt = cnt[idx][b1][b2];
    if (re != -1) return re;
    re = re_cnt = 0;
 
    for(maxb b = 0; b < B; b++) {
        bool ok = 1; maxn cur_cnt = 0;
        for(maxn i = 0; i < 3; i++) {
            cur_cnt += isOn(b, i);
            if (isOn(b, i) && (i == block[idx] - 1 || !valid(b1, b2, i))) ok = 0;
        }
        if (!ok) continue;
        maxn new_mx = cur_cnt + DP(idx + 1, b, b1);
        if (re > new_mx) continue;
        if (re == new_mx)
            re_cnt += idx + 1 == n? 1 : cnt[idx + 1][b][b1];
        else
            re = new_mx, re_cnt = idx + 1 == n? 1 : cnt[idx + 1][b][b1];
    }
    return re;
}
 
 
void Process() {
    memset(mx, -1, sizeof(mx));
    DP(0, 0, 0);
    std::cout << mx[0][0][0] << ' ' << cnt[0][0][0];
}
 
 
int main() {
    //freopen("D.inp", "r", stdin);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}