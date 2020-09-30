#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 1001

typedef int maxn;
typedef std::string str;

char s[maxN];
maxn n, res, res_l;
bool f[maxN][maxN];


void Prepare() {
    n = 0;
    while (std::cin >> s[n]) ++n;
}


void Process() {
    f[0][0] = 1;
    res = 1, res_l = 0;

    for(maxn i = 1; i < n; i++) {
        f[i][i] = 1;
        if (s[i] != s[i - 1]) continue;
        f[i - 1][i] = 1;
        if (res != 2) res = 2, res_l = i - 1;
    }

    for(maxn l = 3; l <= n; l++) for(maxn i = 0; i <= n - l; i++) {
        maxn j = i + l - 1;
        f[i][j] = (f[i + 1][j - 1] & (s[i] == s[j]));

        if (!f[i][j] || l <= res) continue;
        res = l, res_l = i;
    }

    for(maxn i = res_l, l = 0; l < res; l++, i++) std::cout << s[i];
}


int main() {
    freopen("doixung.inp", "r", stdin);
    freopen("doixung.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
