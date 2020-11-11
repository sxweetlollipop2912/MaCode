#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define maxN 7003

typedef int maxn;
typedef long long maxa;
typedef std::string str;

const maxa MOD = 998244353;

maxn n, f[maxN][maxN], L[maxN][maxN];
str s;


void Prepare() {
    std::cin >> s;
    n = s.size();
}


bool Greater(const maxn l1, const maxn l2, const maxn len) {
    if (l1 < 1 || s[l1 - 1] == '0' || s[l2 - 1] == '0' || L[l1][l2] >= len) return 0;
    return s[l1 + L[l1][l2] - 1] < s[l2 + L[l1][l2] - 1];
}


void Process() {
    for(maxn i = n; i > 0; i--) for(maxn j = n; j > 0; j--) {
        if (s[i - 1] != s[j - 1]) continue;
        L[i][j] = L[i + 1][j + 1] + 1;
    }

    for(maxn i = 1; i <= n; i++) {
        for(maxn l = 1; l < i; l++) {
            f[i][l] = f[i][l - 1];
            if (s[i - l] == '0') continue;

            if (Greater(i - 2*l + 1, i - l + 1, l))
                f[i][l] = (f[i][l] + f[i - l][l]) % MOD;
            else f[i][l] = (f[i][l] + f[i - l][l - 1]) % MOD;
        }
        f[i][i] = (f[i][i - 1] + 1) % MOD;
        for(maxn l = i + 1; l <= n; l++) f[i][l] = f[i][l - 1];
    }
    std::cout << f[n][n];
}


int main() {
    freopen("split.inp", "r", stdin);
    freopen("split.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
