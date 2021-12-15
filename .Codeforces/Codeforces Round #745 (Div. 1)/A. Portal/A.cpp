// AC
#include <iostream>
#include <algorithm>

#define maxN 402

typedef int maxn;

maxn m, n, s[maxN][maxN], f[maxN], res;
bool a[maxN][maxN];


void Prepare() {
    std::cin >> m >> n;
    
    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        char c; std::cin >> c;
        a[i][j] = c == '1';
    }

    for(maxn i = 1; i <= m; i++) for(maxn j = 1; j <= n; j++) {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
}


maxn Sum(const maxn ul_r, const maxn ul_c, const maxn dr_r, const maxn dr_c) {
    return s[dr_r][dr_c] - s[dr_r][ul_c - 1] - s[ul_r - 1][dr_c] + s[ul_r - 1][ul_c - 1];
}


void Process() {
    res = m * n;
    
    for(maxn u = 1; u <= m; u++) for(maxn d = u + 4; d <= m; d++) {
        for(maxn r = n; r >= 4; r--) {
            f[r] = Sum(u + 1, 1, d - 1, r - 1) + (r - 1 - Sum(u, 1, u, r - 1)) + (r - 1 - Sum(d, 1, d, r - 1)) + (d - u - 1 - Sum(u + 1, r, d - 1, r));
            if (r != n)
                f[r] = std::min(f[r], f[r + 1]);
        }
        for(maxn l = 1; l <= n - 4 + 1; l++) {
            maxn re = f[l + 3] - Sum(u + 1, 1, d - 1, l) - (l - Sum(u, 1, u, l)) - (l - Sum(d, 1, d, l)) + (d - u - 1 - Sum(u + 1, l, d - 1, l));
            res = std::min(res, re);
        }
    }

    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}