#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 2003
#define maxS 4003
#define maxM 11
#define ofs(x) ((x) + 2000)

typedef int maxn;
typedef long maxa;
typedef long long maxr;

const maxn N = 2;
const maxr MOD = 998244353;
const maxa MOD11 = 11;

maxn n;
maxa a[maxN], la[maxN], ca[maxN];
std::vector <maxn> c, l;
maxr fl[2][maxS][maxM], fc[2][maxN][maxM], res;


maxa CalL(maxa x) {
    bool isL = 0; maxa cnt[2];
    cnt[0] = cnt[1] = 0;
    for(; x != 0; isL = !isL, x /= 10) cnt[isL] += x % 10;
    
    if (isL) return cnt[0] - cnt[1];
    else return cnt[1] - cnt[0];
}


maxa CalC(maxa x) {
    bool isL = 0; maxa cnt[2];
    cnt[0] = cnt[1] = 0;
    for(; x != 0; isL = !isL, x /= 10) cnt[isL] += x % 10;
    
    if (isL) return cnt[1] - cnt[0];
    else return cnt[0] - cnt[1];
}


bool isL(maxa x) {
    bool re = 0;
    for(; x != 0; re = !re, x /= 10);
    return re;
}


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i];
        la[i] = (CalL(a[i]) + MOD11) % MOD11, ca[i] = (CalC(a[i]) + MOD11) % MOD11;
        if (isL(a[i])) l.push_back(i);
        else c.push_back(i);
        std::cout << i << ' ' << a[i] << ' ' << la[i] << ' ' << ca[i] << ' ' << isL(a[i]) << '\n';
    }
}


void Process() {
    bool pc = 0; fc[!pc][0][0] = 1;
    for(maxn i = 0; i < c.size(); i++, pc = !pc) for(maxn sl = 0; sl <= i + 1; sl++) for(maxa s = 0; s < MOD11; s++) {
        maxa lx = la[c[i]], cx = ca[c[i]], x;
        if (sl != 0) {
            x = (s - cx + MOD11) % MOD11;
            (fc[pc][sl][s] += (fc[!pc][sl - 1][x] * (sl - 1 + ((l.size() + 1) / 2)))) %= MOD; 
        }
        if (sl != i + 1) {
            x = (s - lx + MOD11) % MOD11;
            (fc[pc][sl][s] += (fc[!pc][sl][x] * (((i + 1) - sl) - 1 + ((l.size() / 2) + 1)))) %= MOD; 
        }
    }
    pc = !pc;
    std::cout << "dp1 " << fc[pc][2][10] << '\n';

    bool pl = 0; fl[!pl][ofs(0)][0] = 1;
    for(maxn i = 0; i < l.size(); i++, pl = !pl) for(maxn j = -N; j <= N; j++) for(maxa s = 0; s < MOD11; s++) {
        if ((i + j) & 1) continue;
        maxa lx = la[l[i]], cx = ca[l[i]], x = (s - lx + MOD11) % MOD11;
        maxn slL = (i + 1 + j) / 2, slR = i + 1 - slL;

        if (j != N)  
            (fl[pl][ofs(j + 1)][(s + lx) % MOD11] += ((fl[!pl][ofs(j)][s] * (slL + slR)) % MOD)) %= MOD;
        if (i != 0 && j != -N) 
            (fl[pl][ofs(j - 1)][(s + cx) % MOD11] += ((fl[!pl][ofs(j)][s] * (slL + slR)) % MOD)) %= MOD;

        std::cout << "fl " << i << ' ' << !pl << ' ' << s << ' ' << j << ' ' << fl[!pl][ofs(j)][s] << '\n';
    }

    bool pl = 0;
    for(maxn i = 0; i < l.size(); i++, pl = !pl) for(maxn j = 0; j < l.size(); j++) for(maxa s = 0; s < MOD11; s++) {
        
    } 
    pl = !pl;
    std::cout << "dp2\n";

    std::cout << fl[pl][ofs(0)][0] << '\n';

    res = 0;
    for(maxa s = 0; s < MOD11; s++) for(maxn sl = 0; sl <= c.size(); sl++) {
        if (l.size() & 1) res = (res + ((fc[pc][sl][s] * fl[pl][ofs(1)][(MOD11 - s) % MOD11]) % MOD)) % MOD;
        else
            res = (res + ((fc[pc][sl][s] * fl[pl][ofs(0)][(MOD11 - s) % MOD11]) % MOD)) % MOD;
    }

    std::cout << res;
}


int main() {
    Prepare();
    Process();
}