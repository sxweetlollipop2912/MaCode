#include <iostream>
#include <cstdio>
#include <string>

#define maxN 203
#define MOD (maxa)100000

typedef int maxn;
typedef long long maxa;
typedef std::string str;

maxn n;
str s;
maxa cnt[maxN][maxN];


void Prepare() {
    std::cin >> n >> s;
}


maxa waysB(const char c1, const char c2) {
    if (c1 == '?' && c2 == '?') return 3;
    if ((c1 == '(' && c2 == ')') || (c1 =='{' && c2 == '}') || (c1 == '[' && c2 == ']')) return 1;
    if ((c1 == '(' || c1 == '{' || c1 == '[') && c2 == '?') return 1;
    if ((c2 == ')' || c2 == '}' || c2 == ']') && c1 == '?') return 1;
    return 0;
}


maxa Cnt(const maxn l, const maxn r) {
    if (l > r) return 1;
    return cnt[l][r];
}


void Process() {
    for(maxn len = 2; len <= n; len += 2) {
        for(maxn l = 0; l <= n - len; l++) {
            maxn r = l + len - 1;
            for (maxn m = l + 1; m < r - 1; m += 2) {
                cnt[l][r] = (cnt[l][r] + (Cnt(l + 1, m - 1) * waysB(s[l], s[m]) * Cnt(m + 1, r))) % MOD;
            }
            cnt[l][r] = (cnt[l][r] + waysB(s[l], s[r]) * Cnt(l + 1, r - 1)) % MOD;
        }
    }
    std::cout << cnt[0][n - 1];
}


int main() {
    //freopen("dayngoac.inp","r",stdin);
    //freopen("dayngoac.out","w",stdout);

    //std::ios_base::sync_with_stdio(0);
    //std::cin.tie(0);

    Prepare();
    Process();
}