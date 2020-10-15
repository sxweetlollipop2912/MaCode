#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 100002
#define maxC 28
#define C 26
#define num(c) ((c) - 'a')
#define cal(cnt, len) ((cnt) / (maxr)(len))
#define equal(x, y) (std::abs((x) - (y)) < eps)
#define greater(x, y) ((x) - eps > (y))

typedef long maxn;
typedef double maxr;

const maxr eps = 10e-5;

maxn n, cnt[maxC], res_l, res_len;
maxr res;
std::string a;


void Prepare() {
    std::cin >> n >> a;
}


void Process() {
    res = n;

    for(int i = 1; i <= C; i++) {
        std::fill(cnt, cnt + maxC, 0);
        maxn CNT = 0, L = 0, len = 0;

        for(maxn l = 0, r = 0; r < n; r++) {
            if (!cnt[num(a[r])]) ++CNT;
            ++cnt[num(a[r])];

            while (CNT > i) {
                --cnt[num(a[l])];
                if (!cnt[num(a[l])]) --CNT;
                ++l;
            }
            if (CNT == i && len < r - l + 1) L = l, len =  r - l + 1;
        }

        if (!len) continue;

        maxr re = cal(i, len);
        if (greater(re, res) || (equal(re, res) && (len <= res_len)))
            continue;
        res = re, res_l = L, res_len = len;
    }

    std::cout << res_l + 1 << ' ' << res_l + res_len - 1 + 1;
}


int main() {
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}