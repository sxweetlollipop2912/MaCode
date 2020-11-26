// AC
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 50002

typedef long maxn;

maxn n, d1[maxN], d2[maxN], res;
std::string s;


void Prepare() {
    std::cin >> n >> s;
}


void Process() {
    for(maxn l = 0, r = -1, i = 0; i < n; i++) {
        maxn k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            ++k;

        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }

        res = std::max(res, k * 2 - 1);
    }

    for(maxn l = 0, r = -1, i = 0; i < n; i++) {
        maxn k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
            ++k;

        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k - 2;
            r = i + k - 1;
        }

        res = std::max(res, k * 2);
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}