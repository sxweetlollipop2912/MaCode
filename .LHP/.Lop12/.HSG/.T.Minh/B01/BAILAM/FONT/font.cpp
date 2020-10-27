#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 30
#define On(b, x) ((b) | (1 << (x)))

typedef int maxn;
typedef long long maxb;

const maxb BIT = (1 << 26) - 1;

maxn n;
maxb b[maxN];


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        b[i] = 0;
        for(maxn is = 0; is < s.size(); is++)
            b[i] = On(b[i], s[is] - 'a');
    }
}


maxb Try(const maxn idx, const maxb B) {
    if (B == BIT) return (1 << (n - idx));
    if (idx == n) return 0;
    return Try(idx + 1, B) + Try(idx + 1, B | b[idx]);
}


void Process() {
    std::cout << Try(0, 0);
}


int main() {
    freopen("font.inp", "r", stdin);
    freopen("font.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
