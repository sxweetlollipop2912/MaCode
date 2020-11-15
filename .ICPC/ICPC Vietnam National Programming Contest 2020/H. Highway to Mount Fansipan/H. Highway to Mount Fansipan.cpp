// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <string.h>

#define maxN 100002
#define maxC 27
#define num(c) ((c) - 'a')
#define fi first
#define se second

typedef long maxn;
typedef long long maxa;
typedef std::string str;
typedef std::pair <int, maxn> p_t;

const maxa MOD = 1e9 + 7;

maxn n, ns, w[maxN];
maxa cnt[maxC][maxN], f[maxN], res;
str s[maxN];
std::multiset <p_t> set;


void Init() {
    for(maxn i = 0; i < ns; i++) {
        cnt[num(s[i][0])][s[i].size()] = 0;
    }
}


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> w[i];

    std::cin >> ns;
    for(maxn i = 0; i < ns; i++) {
        std::cin >> s[i];
        ++cnt[num(s[i][0])][s[i].size()];
    }

    f[0] = 1;
    for(maxn i = 1; i <= ns; i++) f[i] = (f[i - 1] * i) % MOD;
}


maxa pow(const maxa a, maxa p) {
    maxa x = a, re = 1;
    for(; p != 0; p >>= 1) {
        if (p & 1) re = (re * x) % MOD;
        x = (x * x) % MOD;
    }
    return re;
}


maxa P(const maxn n, const maxn k) {
    if (n < k) return 0;
    maxa re = ((f[n] * pow(f[n - k], MOD - 2)) % MOD) % MOD;
    return re;
}


maxa Count(const str &s) {
    if (s.size() != n) return 0;
    for(maxn i = 0; i < n; i++) if (!cnt[num(s[i])][w[i]]) return 0;
    set.clear();

    for(maxn i = 0; i < n; i++) set.insert(p_t(num(s[i]), w[i]));
    if (set.empty()) return 0;

    maxa re = 1;
    while (!set.empty()) {
        p_t p = *set.begin();
        maxa cntk = set.count(p), cntn = cnt[p.fi][p.se];
        if (num(s[0]) == p.fi && s.size() == p.se) --cntn;
        if (cntk > cntn) return 0;
        re = (re * P(cntn, cntk)) % MOD;
        set.erase(p);
    }

    return re;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < ns; i++) {
        res = (res + Count(s[i])) % MOD;
    }
    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Init();
        Prepare();
        Process();
    }
}
