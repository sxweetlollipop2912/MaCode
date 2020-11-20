#include <iostream>
#include <algorithm>
#include <cstdio>
 
#define maxN 100001
#define maxB 20
#define shl(x) pow(2, x)
 
typedef long long maxn;
typedef long long maxa;
 
const maxa MOD = 1e9 + 7;
 
maxn n, cnt[maxB], cntb[maxB];
maxa a[maxN], res;
 
 
void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}
 
 
maxa pow(const maxa a, maxa p) {
    maxa re = 1, x = a;
    for(; p != 0; p >>= 1) {
        if (p & 1) re = (re * x) % MOD;
        x = (x * x) % MOD;
    }
    return re;
}
 
 
void Process() {
    for(maxn i = 0; i < n; i++) for(maxn b = 1, ib = 0; b <= a[i]; b <<= 1, ib++) {
        if (a[i] & b) ++cnt[ib];
    }
 
    for(maxn ib = 0; ib < maxB; ib++) {
        maxn left = n - cnt[ib];
        cntb[ib] = (((shl(cnt[ib]) - 1) % MOD) * ((shl(left)) % MOD)) % MOD;
    }
 
    res = 0;
    for(maxn ib = 0, b = 1; ib < maxB; ib++, b <<= 1) res = (res + (b * cntb[ib]) % MOD) % MOD;
    std::cout << res;
}
 
 
int main() {
    //freopen("D.inp", "r", stdin);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}