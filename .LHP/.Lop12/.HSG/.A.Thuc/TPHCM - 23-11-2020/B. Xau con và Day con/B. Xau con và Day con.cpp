// B. Xau con và Day con
// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 5002

typedef int maxn;
typedef long long maxa;
typedef std::string str;

const maxa MOD = 1e9 + 7;

maxn ns, nt;
str s, t;
maxa f[maxN], res;


void Prepare() {
    std::cin >> s >> t;
    ns = s.size(), nt = t.size();
}


void Process() {
    std::fill(f, f + ns + 1, 0);
    for(maxn it = nt - 1; it >= 0; it--) for(maxn is = 0; is < ns; is++) {
        if (t[it] != s[is]) continue;
        f[is] = (f[is] + f[is + 1] + 1) % MOD;
    }
    res = 0;
    for(maxn i = 0; i < ns; i++) res = (res + f[i]) % MOD;

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}