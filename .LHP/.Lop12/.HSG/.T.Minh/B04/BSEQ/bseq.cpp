#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>

#define maxN 16
#define BIT ((1 << n) - 1)
#define num(c) ((c) - 'A')
#define chr(x) ((x) + 'A')
#define shl(x) ((maxb)1 << (maxb)(x))

typedef int maxn, maxb;
typedef long long maxa;
typedef std::string str;

maxn n, cnt[maxN];
maxb req[maxN];
maxa res;


void Prepare() {
    for(maxn i = 0; i < n; i++) {
        str s;
        std::cin >> s;

        cnt[i] = s.size();
        req[i] = 0;
        if (s == "?") req[i] = BIT, cnt[i] = n;
        else for(maxn j = 0; j < s.size(); j++) req[i] |= shl(num(s[j]));
    }
}


maxa Try(const maxn idx, const maxb bl, const maxb br, const maxb b, const maxb c2, const maxb c1) {
    //std::cout << idx << ' ' << c2 << ' ' << c1 << '\n';
    if (idx == n) return 1;

    maxb B = BIT & ~(bl | br | b);
    B &= ~(c1 >> 2);
    B &= ~(c1 << 2);
    B &= ~(c2 >> 1);
    B &= ~(c2 << 1);
    B &= req[idx];

    if (B == 0) return 0;
    //std::cout << idx << ' ' << B << '\n';
    maxa re = 0;

    while (B != 0) {
        //std::cout << B << '\n';
        maxb i = B & (-B); B -= i;
        //std::cout << "i " << i << ' ' << B << '\n';
        re += Try(idx + 1, (bl | i) << 1, (br | i) >> 1, b | i, c1, i);
    }
    return re;
}


void Process() {
    res = 1;
    for(maxn i = 0; i < n; i++) res *= cnt[i];

    //std::cout << n << ' ' << res << ' ' << Try(0, 0, 0, 0, 0, 0) << '\n';
    res -= Try(0, 0, 0, 0, 0, 0);

    std::cout << res << '\n';
}


int main() {
    freopen("bseq.inp", "r", stdin);
    freopen("bseq.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (std::cin >> n && n) {
        Prepare();
        Process();
    }
}
