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
    res = n, res_len = 0;

    for(maxn l = 0; l < n; l++) {
        std::fill(cnt, cnt + maxC, 0);
        maxn CNT = 0;
        for(maxn r = l; r < n; r++) {
            if (!cnt[num(a[r])]) ++CNT;
            ++cnt[num(a[r])];
            
            maxr re = cal(CNT, r - l + 1);
            if (greater(re, res) || (equal(re, res) && r - l + 1 <= res_len)) continue;
            res = re;
            res_l = l, res_len = r - l + 1;
        }
    }
    std::cout << res_l + 1 << ' ' << res_l + res_len - 1 + 1;
}


int main() {
    freopen("color.inp", "r", stdin);
    freopen("color.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}